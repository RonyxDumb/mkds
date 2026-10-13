/* Decompiled C draft; module arm7; ROM address 037fb098. No matching claim. */
#include "types.h"
#include "deps/037fb098_FUN_037fb098.h"

void FUN_037fb098(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7f00) == 0x1000) {
    *DAT_037fb0d0 = 1;
  }
  else {
    FUN_037fb000();
  }
  return;
}

