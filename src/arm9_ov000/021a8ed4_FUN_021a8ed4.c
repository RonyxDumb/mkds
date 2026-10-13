/* Decompiled C draft; module arm9_ov000; ROM address 021a8ed4. No matching claim. */
#include "types.h"
#include "deps/021a8ed4_FUN_021a8ed4.h"

uint FUN_021a8ed4(void)

{
  uint uVar1;
  
  uVar1 = FUN_021a8830();
  return uVar1 << 0x18 & DAT_021a8f00 |
         uVar1 << 8 & DAT_021a8f04 | uVar1 >> 0x18 | uVar1 >> 8 & DAT_021a8f08;
}

