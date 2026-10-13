/* Decompiled C draft; module arm9_ov000; ROM address 021b01a0. No matching claim. */
#include "types.h"
#include "deps/021b01a0_FUN_021b01a0.h"

uint FUN_021b01a0(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 ^ DAT_021b01b0) & 0xffff;
  if (uVar1 == 0) {
    uVar1 = DAT_021b01b0;
  }
  return uVar1;
}

