"""Compare current dictionary C bodies with original ARM on bounded valid fixtures.

Host declarations use fixed-width equivalents of the recorded SDK layouts.
C function bodies and unchecked inline helper bodies come from current sources.
Covers the linear and Patricia paths, existing and missing names, and empty
dictionaries. Requires gcc and Unicorn; no malformed-input or full-ROM claim.
"""
from pathlib import Path
import ctypes
import json
import random
import re
import struct
import subprocess
import tempfile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
from unicorn.arm_const import UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_SP
ROOT = Path(__file__).resolve().parents[1]
HEADER = '''#include <stdint.h>
#define NULL 0
#define NNS_G3D_NULL_ASSERT(x)
#define NNS_G3D_ASSERT(x)
#define NNS_G3D_RES_INLINE static inline
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef struct {u8 refBit,idxLeft,idxRight,idxEntry;} NNSG3dResDictTreeNode;
typedef struct {u8 revision,numEntry;u16 sizeDictBlk,dummy_,ofsEntry;NNSG3dResDictTreeNode node[1];} NNSG3dResDict;
typedef union {char name[16];u32 val[4];} NNSG3dResName;
typedef struct {u16 sizeUnit,ofsName;u8 data[4];} NNSG3dResDictEntryHeader;
'''

def body(text, name):
    pattern = r'^[^#;{}\n]*\b' + re.escape(name) + r'\s*\([^;{}]*\)\s*\{'
    match = re.search(pattern, text, re.M)
    assert match, name
    end = match.end(); depth = 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}'); end += 1
    return text[match.start():end] + '\n'


def main():
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(0x02000000, 0x500000)
    manifest = json.loads((ROOT/'baseline/manifest.json').read_text())
    for module in manifest['modules']:
        if module['name'] == 'arm9':
            for section in module['sections']:
                start = section['base'] & ~4095
                end = (section['base'] + section['size'] + 4095) & ~4095
                if not 0x02000000 <= start < end <= 0x02500000:
                    uc.mem_map(start, end - start)
                uc.mem_write(section['base'], (ROOT/'baseline/binaries'/section['file']).read_bytes())
    functions = []
    sources = []
    for address in [0x02013754, 0x020138b4]:
        path, = (ROOT/'src/arm9').glob(f'{address:08x}_*.c')
        name = path.stem[9:];text = path.read_text()
        source = HEADER
        for helper in ['NNS_G3dGetResNameByIdx', 'NNS_G3dGetResDataByIdx']:
            source += body(text, helper)
        source += body(text, name)
        sources.append(source); functions.append((address, name))
    rng = random.Random(29)
    buffer = ctypes.create_string_buffer(4096)
    data_address, stop = 0x02400000, 0x023ff000
    tested = 0
    with tempfile.TemporaryDirectory() as directory:
        paths=[]
        for index,source in enumerate(sources):
            path=Path(directory)/f'dict{index}.c';path.write_text(source);paths.append(str(path))
        library=Path(directory)/'dict.so'
        subprocess.run(['gcc','-std=c11','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',*paths,'-o',str(library)],check=True)
        dll=ctypes.CDLL(str(library))
        for count in [0,1,2,7,15,16,32]:
            for sample in range(32):
                data=bytearray(rng.randbytes(4096));nodes=[(127,0,0,0)]
                if count>=16:
                    def subtree(entries,bit):
                        idx=len(nodes);nodes.append(None)
                        if len(entries)==1:nodes[idx]=(0,idx,idx,entries[0])
                        else:
                            left=subtree([e for e in entries if not ((e<<1)>>bit)&1],bit-1)
                            right=subtree([e for e in entries if ((e<<1)>>bit)&1],bit-1)
                            nodes[idx]=(bit,left,right,0)
                        return idx
                    nodes[0]=(127,subtree(list(range(count)),count.bit_length()-1),0,0)
                entry=(8+4*len(nodes)+3)&~3
                struct.pack_into('<BBHHH',data,0,0,count,4096,0,entry)
                for i,node in enumerate(nodes):struct.pack_into('<BBBB',data,8+4*i,*node)
                stride=4*(sample%4+1);names_offset=4+stride*count
                struct.pack_into('<HH',data,entry,stride,names_offset)
                names=[]
                for i in range(count):
                    value=(i<<1,rng.getrandbits(32),rng.getrandbits(32),rng.getrandbits(32));names.append(value)
                    struct.pack_into('<IIII',data,entry+names_offset+16*i,*value)
                queries=[(*value,) for value in names]+[(value[0],value[1],value[2]^1,value[3]) for value in names]+[(0xffffffff,0,0,0)]
                for query in queries:
                    struct.pack_into('<IIII',data,0xf00,*query)
                    for address,name in functions:
                        function=getattr(dll,name);pointer=address==0x020138b4
                        function.argtypes=[ctypes.c_void_p,ctypes.c_void_p];function.restype=ctypes.c_void_p if pointer else ctypes.c_int
                        uc.mem_write(data_address,bytes(data));uc.reg_write(UC_ARM_REG_SP,0x023fe000);uc.reg_write(UC_ARM_REG_LR,stop);uc.reg_write(UC_ARM_REG_R0,data_address);uc.reg_write(UC_ARM_REG_R1,data_address+0xf00)
                        uc.emu_start(address,stop,count=2000);assert uc.reg_read(UC_ARM_REG_PC)==stop
                        ctypes.memmove(ctypes.addressof(buffer),bytes(data),4096)
                        actual=function(ctypes.addressof(buffer),ctypes.addressof(buffer)+0xf00)
                        if pointer:actual=(actual-ctypes.addressof(buffer)+data_address) if actual else 0
                        else:actual&=0xffffffff
                        assert actual==uc.reg_read(UC_ARM_REG_R0),(count,sample,name,query)
                        expected_index=names.index(query) if query in names else -1
                        expected=(data_address+entry+4+stride*expected_index if expected_index>=0 else 0) if pointer else expected_index&0xffffffff
                        assert actual==expected,(count,name,actual,expected)
                        assert bytes(uc.mem_read(data_address,4096))==bytes(data)==buffer.raw
                        tested+=1
    result=dict(tested=tested,passed=tested,counts=[0,1,2,7,15,16,32],full_rom_link_verified=False)
    (ROOT/'verification/dictionary-semantic-tests.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result))

if __name__=='__main__':main()
