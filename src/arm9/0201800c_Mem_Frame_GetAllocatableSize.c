/* Decompiled C draft; module arm9; ROM address 0201800c. No matching claim. */
#include "types.h"
#include "deps/0201800c_Mem_Frame_GetAllocatableSize.h"

int Mem_Frame_GetAllocatableSize(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = abs(param_2);
  uVar3 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar5 = param_1 + 0x28U & 3;
  uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar3 = ~(iVar1 - 1U) & (iVar1 - 1U) + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  if (uVar5 < uVar3) {
    iVar1 = 0;
  }
  else {
    iVar1 = uVar5 - uVar3;
  }
  return iVar1;
}

