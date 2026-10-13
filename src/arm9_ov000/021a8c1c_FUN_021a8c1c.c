/* Decompiled C draft; module arm9_ov000; ROM address 021a8c1c. No matching claim. */
#include "types.h"
#include "deps/021a8c1c_FUN_021a8c1c.h"

undefined4 FUN_021a8c1c(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = FUN_021a88a8();
  if (uVar1 == 0) {
    return 0;
  }
  *param_2 = uVar1 << 0x18 & DAT_021a8c60 |
             uVar1 << 8 & DAT_021a8c64 | uVar1 >> 0x18 | uVar1 >> 8 & DAT_021a8c68;
  return 1;
}

