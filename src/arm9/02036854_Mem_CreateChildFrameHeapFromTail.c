/* Decompiled C draft; module arm9; ROM address 02036854. No matching claim. */
#include "types.h"
#include "deps/02036854_Mem_CreateChildFrameHeapFromTail.h"

void Mem_CreateChildFrameHeapFromTail(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (uVar2 == uRam020368d8) {
    uVar3 = Mem_Exp_Allocate(param_1,param_2,0xfffffffc);
  }
  else if (uVar2 == uRam020368dc) {
    uVar1 = Os_DisableIrq();
    uVar3 = Mem_Frame_Allocate(param_1,param_2,0xfffffffc);
    Os_RestoreIrq(uVar1);
  }
  Mem_Frame_Create(uVar3,param_2,1);
  return;
}

