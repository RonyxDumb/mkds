/* Decompiled C draft; module arm7; ROM address 037fabc0. No matching claim. */
#include "types.h"
#include "deps/037fabc0_FUN_037fabc0.h"

void FUN_037fabc0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_037faf70();
  param_1[9] = 1;
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) {
    FUN_037faf84();
  }
  else {
    FUN_037fade0((int)(uintptr_t)(param_1));
    *param_1 = 0;
    FUN_037faf84(uVar1);
  }
  return;
}

