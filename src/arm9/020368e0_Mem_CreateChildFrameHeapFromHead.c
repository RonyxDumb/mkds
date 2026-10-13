/* Decompiled C draft; module arm9; ROM address 020368e0. No matching claim. */
#include "types.h"
#include "deps/020368e0_Mem_CreateChildFrameHeapFromHead.h"

void Mem_CreateChildFrameHeapFromHead(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar2 = 0;
  if (uVar1 == uRam02036940) {
    uVar2 = Mem_Exp_Allocate(param_1,param_2,4);
  }
  else if (uVar1 == uRam02036944) {
    uVar2 = Mem_Frame_Allocate(param_1,param_2,4);
  }
  Mem_Frame_Create(uVar2,param_2,1);
  return;
}

