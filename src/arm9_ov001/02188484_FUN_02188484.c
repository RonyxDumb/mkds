/* Decompiled C draft; module arm9_ov001; ROM address 02188484. No matching claim. */
#include "types.h"
#include "deps/02188484_FUN_02188484.h"

void FUN_02188484(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  *(undefined4 *)(param_1 + DAT_021884c8) = 1;
  if ((*(ushort *)(param_1 + 2) & DAT_021884cc) != 0) {
    param_2 = -param_2;
  }
  *(int *)(param_1 + DAT_021884d0) = param_2;
  *(undefined4 *)(param_1 + DAT_021884d4) = param_3;
  *(undefined4 *)(param_1 + DAT_021884d8) = param_4;
  *(undefined4 *)(param_1 + DAT_021884dc) = param_5;
  *(undefined4 *)(param_1 + DAT_021884e0) = param_6;
  *(undefined4 *)(param_1 + DAT_021884e4) = param_7;
  *(undefined4 *)(param_1 + DAT_021884e8) = param_8;
  *(undefined4 *)(param_1 + DAT_021884ec) = param_9;
  return;
}

