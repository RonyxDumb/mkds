/* Decompiled C draft; module arm9_ov001; ROM address 02188a30. No matching claim. */
#include "types.h"
#include "deps/02188a30_FUN_02188a30.h"

void FUN_02188a30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + DAT_02188a70) == 7) {
    uVar1 = 7;
  }
  else if (*(int *)(param_1 + DAT_02188a70) == 8) {
    uVar1 = 8;
  }
  else {
    uVar1 = 6;
  }
  *(undefined4 *)(param_1 + DAT_02188a70) = uVar1;
  *(undefined4 *)(param_1 + DAT_02188a74) = param_2;
  *(undefined4 *)(param_1 + DAT_02188a78) = param_3;
  *(undefined4 *)(param_1 + DAT_02188a7c) = 0;
  *(undefined4 *)(param_1 + DAT_02188a80) = 2;
  *(undefined4 *)(param_1 + DAT_02188a84) = param_4;
  *(undefined4 *)(param_1 + DAT_02188a88) = param_5;
  return;
}

