/* Decompiled C draft; module arm9; ROM address 02036948. No matching claim. */
#include "types.h"
#include "deps/02036948_Mem_CreateOrphanChildHeap.h"

void Mem_CreateOrphanChildHeap(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (uVar2 == uRam020369f4) {
    uVar3 = Mem_Exp_GetAllocatableSize(param_1,4);
  }
  else if (uVar2 == uRam020369f8) {
    uVar3 = Mem_Frame_GetAllocatableSize(param_1,4);
  }
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = 0;
  if (uVar2 == uRam020369f4) {
    uVar1 = Mem_Exp_Allocate(param_1,uVar3,4);
  }
  else if (uVar2 == uRam020369f8) {
    uVar1 = Mem_Frame_Allocate(param_1,uVar3,4);
  }
  Mem_Frame_Create(uVar1,uVar3,1);
  return;
}

