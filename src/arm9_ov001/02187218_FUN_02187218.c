/* Decompiled C draft; module arm9_ov001; ROM address 02187218. No matching claim. */
#include "types.h"
#include "deps/02187218_FUN_02187218.h"

void FUN_02187218(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(param_1 + DAT_02187294) = 0;
  *(undefined4 *)(param_1 + DAT_02187298) = param_3;
  *(undefined4 *)(param_1 + DAT_0218729c) = param_2;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  if (0 < *(int *)(param_1 + 0xb4)) {
    iVar1 = *(int *)(param_1 + 0xb4) + -1;
  }
  *(int *)(param_1 + 0xb4) = iVar1;
  *(undefined4 *)(param_1 + DAT_021872a0) = 0;
  *(undefined4 *)(param_1 + DAT_021872a4) = 1;
  if (*(int *)(param_1 + DAT_021872a8) == 0) {
    *(undefined4 *)(param_1 + DAT_021872ac) = 0;
    *(undefined4 *)(param_1 + DAT_021872b0) = 0;
    *(undefined4 *)(param_1 + DAT_021872b4) = 0;
    *(undefined4 *)(param_1 + DAT_021872b8) = 0;
    *(undefined4 *)(param_1 + DAT_021872bc) = 0;
    *(undefined4 *)(param_1 + DAT_021872c0) = 0;
    *(undefined4 *)(param_1 + DAT_021872c4) = 0;
    *(undefined4 *)(param_1 + DAT_021872c8) = 0;
    *(undefined4 *)(param_1 + DAT_021872cc) = 0;
    *(undefined4 *)(param_1 + DAT_021872d0) = 0;
    *(undefined4 *)(param_1 + DAT_021872d4) = 0;
    *(undefined4 *)(param_1 + DAT_021872d8) = 0;
    *(undefined4 *)(param_1 + DAT_021872dc) = 0;
    FUN_02187af4();
  }
  return;
}

