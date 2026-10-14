/* Decompiled C draft; module arm7; ROM address 037fa670. No matching claim. */
#include "types.h"
#include "deps/037fa670_FUN_037fa670.h"

void FUN_037fa670(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  
  if ((param_1 == (undefined4 *)0x0) ||
     (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0)) {
    FUN_037fb000();
  }
  uVar1 = FUN_037faf70();
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = param_4;
  param_1[1] = param_5;
  lVar2 = FUN_037fa278();
  lVar2 = lVar2 + CONCAT44(param_3,param_2);
  FUN_037fa6e4((int)(uintptr_t)(param_1),(int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
  FUN_037faf84(uVar1);
  return;
}

