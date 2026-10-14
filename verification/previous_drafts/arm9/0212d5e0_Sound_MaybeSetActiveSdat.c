/* Decompiled C draft; module arm9; ROM address 0212d5e0. No matching claim. */
#include "types.h"
#include "deps/0212d5e0_Sound_MaybeSetActiveSdat.h"

uint Sound_MaybeSetActiveSdat(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)puRam0212d5f4 & 3;
  uVar2 = *(uint *)((uint)puRam0212d5f4 & 0xfffffffc);
  *puRam0212d5f4 = param_1;
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

