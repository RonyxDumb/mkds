"""Compare the complete navigation cluster's host C and original Thumb.

The dispatcher runs its original five grid routines. Four rendering/animation
dependencies are controlled fixtures in both executions; this is not a game run.
"""
from pathlib import Path
import ctypes,json,random,re,struct,subprocess,tempfile
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_THUMB,UC_HOOK_CODE
from unicorn.arm_const import UC_ARM_REG_R0,UC_ARM_REG_R1,UC_ARM_REG_LR,UC_ARM_REG_PC,UC_ARM_REG_SP
from matching_resolver import MatchingContext

ROOT=Path(__file__).resolve().parents[1]
GRIDS=[0x2027448,0x2027648,0x2027850,0x2027a58,0x2027be0]
DISPATCH=0x20270fc
def main():
    ctx=MatchingContext(ROOT,ROOT/'baseline');uc=Uc(UC_ARCH_ARM,UC_MODE_THUMB)
    uc.mem_map(0x02000000,0x400000);uc.mem_map(0x02400000,0x10000)
    for address,data in ctx.sections['arm9']:
        start=address&~4095;end=(address+len(data)+4095)&~4095
        if not 0x02000000<=start<end<=0x02400000:uc.mem_map(start,end-start)
        uc.mem_write(address,data)
    uc.mem_write(0x02174e14,struct.pack('<I',0x02400000))
    trace=[];hooks={0x2027188:1,0x202721c:2,0x2025f54:3,0x2025e60:4}
    def hook(machine,address,size,user):
        if address not in hooks:return
        code=hooks[address];arg=machine.reg_read(UC_ARM_REG_R0)
        if code in [1,2]:arg=0
        if code==3:
            assert machine.reg_read(UC_ARM_REG_R1)==0
            arg-=0x02400000
        trace.append((code,arg))
        if code==4:machine.reg_write(UC_ARM_REG_R0,arg^0x55)
        machine.reg_write(UC_ARM_REG_PC,machine.reg_read(UC_ARM_REG_LR))
    uc.hook_add(UC_HOOK_CODE,hook)
    sources=[];tables=set()
    for a in GRIDS+[DISPATCH]:
        source=next((ROOT/'src/arm9').glob(f'{a:08x}_*.c')).read_text()
        source=source.replace('#define state (*(CharacterSelectState **)0x2174e14u)',
                              'extern CharacterSelectState *data_02174e14;\n#define state data_02174e14')
        tables.update(re.findall(r'extern const unsigned short (data_[0-9a-f]+)\[4\];',source))
        sources.append((a,source))
    fixture='''void *data_02174e14;int log_codes[8],log_args[8],log_count;
void log_call(int c,int a){log_codes[log_count]=c;log_args[log_count++]=a;}
void func_02027188(void){log_call(1,0);}
void func_0202721c(void){log_call(2,0);}
void func_02025f54(void *p,int n){log_call(3,(int)((char *)p-(char *)data_02174e14));if(n)__builtin_trap();}
int func_02025e60(int n){log_call(4,n);return n^0x55;}
'''
    for name in sorted(tables):
        address=int(name[5:],16);values=struct.unpack('<4H',ctx.original('arm9',address,8))
        fixture+='const unsigned short '+name+'[4]={'+','.join(map(str,values))+'};\n'
    counts={};rng=random.Random(35);buffer=ctypes.create_string_buffer(512)
    with tempfile.TemporaryDirectory() as directory:
        paths=[]
        for a,source in sources:
            p=Path(directory)/f'{a:x}.c';p.write_text(source);paths.append(str(p))
        p=Path(directory)/'fixture.c';p.write_text(fixture);paths.append(str(p))
        lib=Path(directory)/'navigation.so'
        subprocess.run(['gcc','-std=c11','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',*paths,'-o',str(lib)],check=True)
        dll=ctypes.CDLL(str(lib));ctypes.c_void_p.in_dll(dll,'data_02174e14').value=ctypes.addressof(buffer)
        logs=(ctypes.c_int*8).in_dll(dll,'log_codes');args=(ctypes.c_int*8).in_dll(dll,'log_args');log_count=ctypes.c_int.in_dll(dll,'log_count')
        for a in GRIDS+[DISPATCH]:
            fn=getattr(dll,f'func_{a:08x}');fn.restype=None;fn.argtypes=[ctypes.c_int] if a==DISPATCH else []
            cases=0
            for count in (range(8,13) if a==DISPATCH else [12]):
                for cursor in (range(count) if a==DISPATCH else [-1,*range(16),0x7fffffff]):
                    for input_value in range(16):
                        data=bytearray(rng.randbytes(512));struct.pack_into('<ii',data,0x60,cursor,input_value);struct.pack_into('<i',data,0x7c,count)
                        for i in range(12):struct.pack_into('<i',data,0x90+i*8,i)
                        ctypes.memmove(buffer,bytes(data),512);uc.mem_write(0x02400000,bytes(data));trace.clear();log_count.value=0
                        if a==DISPATCH:fn(input_value)
                        else:fn()
                        uc.reg_write(UC_ARM_REG_R0,input_value);uc.reg_write(UC_ARM_REG_SP,0x0240f000);uc.reg_write(UC_ARM_REG_LR,0x023ff001)
                        uc.emu_start(a|1,0x023ff000,count=5000)
                        assert buffer.raw==bytes(uc.mem_read(0x02400000,512)),(hex(a),count,cursor,input_value)
                        assert trace==[(logs[i],args[i]) for i in range(log_count.value)]
                        cases+=1
            counts[f'{a:08x}']=cases
    result={'passed':True,'cases':sum(counts.values()),'functions':counts,'scope':'Host C versus original Thumb; full 512-byte state and ordered dependency calls; four rendering/animation dependencies controlled in fixtures. No full-game equivalence.'}
    (ROOT/'verification/checkpoint35-navigation-semantics.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result))
if __name__=='__main__':main()
