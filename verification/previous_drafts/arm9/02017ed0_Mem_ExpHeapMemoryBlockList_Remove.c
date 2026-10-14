/* Decompiled C draft; module arm9; ROM address 02017ed0. No matching claim. */
#include "types.h"
#include "deps/02017ed0_Mem_ExpHeapMemoryBlockList_Remove.h"

uint Mem_ExpHeapMemoryBlockList_Remove(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 + 8U & 3;
  uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0xcU & 3;
  uVar2 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar3 == 0) {
    *param_1 = uVar1;
  }
  else {
    *(uint *)(uVar3 + 0xc) = uVar1;
  }
  if (uVar1 == 0) {
    param_1[1] = uVar3;
  }
  else {
    *(uint *)(uVar1 + 8) = uVar3;
  }
  return uVar3;
}

