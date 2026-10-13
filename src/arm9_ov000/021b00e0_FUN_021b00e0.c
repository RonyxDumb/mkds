/* Decompiled C draft; module arm9_ov000; ROM address 021b00e0. No matching claim. */
#include "types.h"
#include "deps/021b00e0_FUN_021b00e0.h"

undefined4 FUN_021b00e0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_021b00fc();
  if (iVar1 == 0) {
    param_1 = *DAT_021b00f8;
  }
  return param_1;
}

