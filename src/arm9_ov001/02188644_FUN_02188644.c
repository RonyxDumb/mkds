/* Decompiled C draft; module arm9_ov001; ROM address 02188644. No matching claim. */
#include "types.h"
#include "deps/02188644_FUN_02188644.h"

void FUN_02188644(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *(undefined4 *)(param_1 + DAT_021886b4) = 0;
  if ((*(ushort *)(param_1 + 2) & DAT_021886b8) != 0) {
    param_2 = -param_2;
  }
  piVar2 = (int *)(param_1 + DAT_021886bc);
  *piVar2 = param_2;
  *(int *)(param_1 + DAT_021886c0) = *piVar2;
  puVar1 = (undefined4 *)(param_1 + DAT_021886c4);
  *puVar1 = param_3;
  *(undefined4 *)(param_1 + DAT_021886c8) = *puVar1;
  puVar1 = (undefined4 *)(param_1 + DAT_021886cc);
  *puVar1 = param_4;
  *(undefined4 *)(param_1 + DAT_021886d0) = *puVar1;
  *(undefined4 *)(param_1 + DAT_021886d4) = 0;
  puVar1 = (undefined4 *)(param_1 + DAT_021886d8);
  *puVar1 = param_5;
  *(undefined4 *)(param_1 + DAT_021886dc) = *puVar1;
  puVar1 = (undefined4 *)(param_1 + DAT_021886e4);
  *puVar1 = DAT_021886e0;
  *(undefined4 *)(param_1 + DAT_021886e8) = *puVar1;
  puVar1 = (undefined4 *)(param_1 + DAT_021886ec);
  *puVar1 = param_7;
  *(undefined4 *)(param_1 + DAT_021886f0) = *puVar1;
  *(undefined4 *)(param_1 + DAT_021886f4) = 0;
  return;
}

