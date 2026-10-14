/* Decompiled C draft; module arm9; ROM address 02036b74. No matching claim. */
#include "types.h"
#include "deps/02036b74_Mem_AllocateHeapAligned.h"

undefined4 Mem_AllocateHeapAligned(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (uVar2 == uRam02036be4) {
    uVar3 = Mem_Exp_Allocate();
  }
  else if (uVar2 == uRam02036be8) {
    uVar1 = Os_DisableIrq();
    uVar3 = Mem_Frame_Allocate(param_1,param_2,param_3);
    Os_RestoreIrq(uVar1);
  }
  return uVar3;
}

