/* Decompiled C draft; module arm7; ROM address 037fa5f4. No matching claim. */
#include "types.h"
#include "deps/037fa5f4_FUN_037fa5f4.h"

void FUN_037fa5f4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  if ((param_1 == (undefined4 *)0x0) ||
     (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0)) {
    FUN_037fb000();
  }
  uVar1 = FUN_037faf70();
  param_1[7] = param_4;
  param_1[8] = param_5;
  param_1[9] = param_2;
  param_1[10] = param_3;
  *param_1 = param_6;
  param_1[1] = param_7;
  FUN_037fa6e4((int)(uintptr_t)(param_1),0,0);
  FUN_037faf84(uVar1);
  return;
}

