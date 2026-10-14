/* Decompiled C draft; module arm9; ROM address 0209b758. No matching claim. */
#include "types.h"
#include "deps/0209b758_StructMapObject_GetAnimationBCAFrameCount.h"

uint StructMapObject_GetAnimationBCAFrameCount(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  iVar3 = Animation_GetCurrentLength(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return (uint)(iVar3 << 4) >> 0x10;
}

