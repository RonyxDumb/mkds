"""Original Thumb routines versus explicit state/list models on valid fixtures.

This checks the reconstructed field interpretation, not whole-game behavior.
"""
import json
import random
import struct
from pathlib import Path
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB
from unicorn.arm_const import UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_R0
from matching_resolver import MatchingContext

ROOT=Path(__file__).resolve().parents[1]
def main():
    ctx=MatchingContext(ROOT,ROOT/'baseline')
    uc=Uc(UC_ARCH_ARM,UC_MODE_THUMB)
    uc.mem_map(0x02000000,0x400000)
    uc.mem_map(0x02400000,0x10000)
    for address,data in ctx.sections['arm9']:
        start=address&~4095;end=(address+len(data)+4095)&~4095
        if not 0x02000000<=start<end<=0x02400000:
            uc.mem_map(start,end-start)
        uc.mem_write(address,data)
    rng=random.Random(34);counts={}
    def word(a):return int.from_bytes(ctx.original('arm9',a,4),'little')
    def run(a,arg=0):
        uc.reg_write(UC_ARM_REG_SP,0x0240f000)
        uc.reg_write(UC_ARM_REG_LR,0x023ff001)
        uc.reg_write(UC_ARM_REG_R0,arg)
        uc.emu_start(a|1,0x023ff000,count=2000)
        return uc.reg_read(UC_ARM_REG_R0)
    for case in range(1024):
        # State transition 2 -> 3; both payload paths and unchanged states.
        state=word(0x20095f0);node=0x02400000
        data=bytearray(rng.randbytes(4096));flag=rng.randrange(256)
        data[word(0x20095f4)]=flag
        uc.mem_write(node,bytes(data))
        before=bytearray(rng.randbytes(20));before[12]=case%8
        struct.pack_into('<I',before,4,node);expected=bytearray(before)
        if before[12]==2:
            expected[16]=4 if flag else 9
            struct.pack_into('<I',expected,8,node+word(0x20095f8) if flag else node)
            expected[12]=3
        uc.mem_write(state,bytes(before));run(0x20095c4)
        assert bytes(uc.mem_read(state,20))==expected
        assert bytes(uc.mem_read(node,4096))==data
        # Four halfword flags map to four bits.
        slot=word(0x20099bc);uc.mem_write(slot,struct.pack('<I',node))
        values=[rng.randrange(65536) if case%16&(1<<i) else 0 for i in range(4)]
        for off,value in zip([18,14,20,22],values):struct.pack_into('<H',data,off,value)
        uc.mem_write(node,bytes(data))
        assert run(0x2009974)==sum(bit for bit,value in zip([2,1,4,8],values) if value)
        assert bytes(uc.mem_read(node,4096))==data
        # Availability requires all three predicates.
        slot=word(0x200bd30);uc.mem_write(slot,struct.pack('<I',node))
        a,b,d=(rng.randrange(3) for _ in range(3))
        for off,value in [(26,a),(28,b),(32,d)]:struct.pack_into('<H',data,off,value)
        uc.mem_write(node,bytes(data))
        assert run(0x200bd0c)==int(a==1 and b==0 and d==0)
        assert bytes(uc.mem_read(node,4096))==data
    counts.update(state_transition=1024,flag_mask=1024,availability=1024)
    # Append to empty and nonempty acyclic lists; check all node bytes.
    slot=word(0x200971c);offset=word(0x2009720);stride=(offset+7)&~3
    for length in range(17):
        data=bytearray(rng.randbytes(stride*(length+1)))
        for i in range(length):struct.pack_into('<I',data,i*stride+offset,0x02400000+(i+1)*stride if i+1<length else 0)
        new=0x02400000+length*stride;expected=bytearray(data)
        if length:struct.pack_into('<I',expected,(length-1)*stride+offset,new)
        struct.pack_into('<I',expected,length*stride+offset,0)
        uc.mem_write(slot,struct.pack('<I',0x02400000 if length else 0))
        uc.mem_write(0x02400000,bytes(data));run(0x20096f4,new)
        assert bytes(uc.mem_read(0x02400000,len(data)))==expected
        assert int.from_bytes(uc.mem_read(slot,4),'little')==(0x02400000 if length else new)
    counts['list_append']=17
    result={'cases':sum(counts.values()),'passed':True,'by_model':counts,'scope':'Original Thumb versus explicit models on valid synthetic state and acyclic lists; not full game equivalence.'}
    (ROOT/'verification/checkpoint34-semantics.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result))
if __name__=='__main__':main()
