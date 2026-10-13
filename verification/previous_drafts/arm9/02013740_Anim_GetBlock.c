/* Decompiled C draft; module arm9; ROM address 02013740. No matching claim. */
#include "types.h"
#include "deps/02013740_Anim_GetBlock.h"

int Anim_GetBlock(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + (uint)*(ushort *)(param_1 + 0xc) + param_2 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return param_1 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

