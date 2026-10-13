/* Decompiled C draft; module arm9_ov000; ROM address 021b00fc. No matching claim. */
#include "types.h"
#include "deps/021b00fc_FUN_021b00fc.h"

undefined4 FUN_021b00fc(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((param_1 != 0xffffffff) && (param_1 != DAT_021b012c)) &&
     ((param_1 & *DAT_021b0130) != (*DAT_021b0134 & *DAT_021b0130))) {
    uVar1 = 0;
  }
  return uVar1;
}

