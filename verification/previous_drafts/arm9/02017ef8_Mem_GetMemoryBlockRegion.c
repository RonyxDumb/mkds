/* Decompiled C draft; module arm9; ROM address 02017ef8. No matching claim. */
#include "types.h"
#include "deps/02017ef8_Mem_GetMemoryBlockRegion.h"

void Mem_GetMemoryBlockRegion(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = param_2 - ((int)(uint)*(ushort *)(param_2 + 2) >> 8 & 0x7fU);
  uVar1 = param_2 + 4U & 3;
  uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
  param_1[1] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 + 0x10;
  return;
}

