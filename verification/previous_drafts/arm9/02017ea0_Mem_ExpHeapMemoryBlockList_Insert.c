/* Decompiled C draft; module arm9; ROM address 02017ea0. No matching claim. */
#include "types.h"
#include "deps/02017ea0_Mem_ExpHeapMemoryBlockList_Insert.h"

int Mem_ExpHeapMemoryBlockList_Insert(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  *(int *)(param_2 + 8) = param_3;
  if (param_3 == 0) {
    uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    *param_1 = param_2;
  }
  else {
    uVar2 = param_3 + 0xcU & 3;
    uVar1 = *(uint *)(param_3 + 0xcU & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    *(int *)(param_3 + 0xc) = param_2;
  }
  *(uint *)(param_2 + 0xc) = uVar2;
  if (uVar2 == 0) {
    param_1[1] = param_2;
  }
  else {
    *(int *)(uVar2 + 8) = param_2;
  }
  return param_2;
}

