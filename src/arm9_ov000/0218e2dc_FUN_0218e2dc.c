/* Decompiled C draft; module arm9_ov000; ROM address 0218e2dc. No matching claim. */
#include "types.h"
#include "deps/0218e2dc_FUN_0218e2dc.h"

uint FUN_0218e2dc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_0218e314 * (param_1 >> 0x10);
  uVar1 = DAT_0218e314 * (param_1 & DAT_0218e310) + (uVar2 & DAT_0218e318) * 0x10000;
  if (DAT_0218e31c < uVar1) {
    uVar1 = (uVar1 & DAT_0218e31c) + 1;
  }
  uVar1 = uVar1 + (uVar2 >> 0xf);
  if (DAT_0218e31c < uVar1) {
    uVar1 = (uVar1 & DAT_0218e31c) + 1;
  }
  return uVar1;
}

