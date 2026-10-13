/* Decompiled C draft; module arm9; ROM address 0207b8dc. No matching claim. */
#include "types.h"
#include "deps/0207b8dc_GetRacerAnimationIndex.h"

uint GetRacerAnimationIndex(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0207b8f0 + param_1 * 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

