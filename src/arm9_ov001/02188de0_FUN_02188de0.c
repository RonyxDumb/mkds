/* Decompiled C draft; module arm9_ov001; ROM address 02188de0. No matching claim. */
#include "types.h"
#include "deps/02188de0_FUN_02188de0.h"

void FUN_02188de0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + DAT_02188e10) = param_2;
  *(undefined4 *)(param_1 + DAT_02188e14) = param_3;
  if (param_4 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)(param_1 + DAT_02188e18);
    uVar1 = param_4[1];
    *puVar2 = *param_4;
    puVar2[1] = uVar1;
    puVar2[2] = param_4[2];
  }
  if (param_5 == 0) {
    param_5 = DAT_02188e1c;
  }
  *(int *)(param_1 + DAT_02188e20) = param_5;
  return;
}

