/* Decompiled C draft; module arm7; ROM address 037fc3d0. No matching claim. */
#include "types.h"
#include "deps/037fc3d0_FUN_037fc3d0.h"

void FUN_037fc3d0(undefined4 param_1)

{
  if (*(uint *)((uint)DAT_037fc404 & 0xfffffffc) >> ((uint)DAT_037fc404 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_037fc404 & 0xfffffffc) << ((uint)DAT_037fc404 & 3) * -8 + 0x20 == 0) {
    *DAT_037fc404 = 1;
    FUN_037ffd80();
    FUN_037fc388(param_1);
  }
  return;
}

