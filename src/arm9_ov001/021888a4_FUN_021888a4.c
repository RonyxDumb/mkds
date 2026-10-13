/* Decompiled C draft; module arm9_ov001; ROM address 021888a4. No matching claim. */
#include "types.h"
#include "deps/021888a4_FUN_021888a4.h"

void FUN_021888a4(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + DAT_02188910) = 1;
  }
  else {
    *(undefined4 *)(param_1 + DAT_02188910) = 2;
  }
  puVar1 = (undefined4 *)(param_1 + DAT_02188914);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + DAT_02188918) = *puVar1;
  piVar2 = (int *)(param_1 + DAT_0218891c);
  *piVar2 = param_2;
  *(int *)(param_1 + DAT_02188920) = *piVar2;
  puVar1 = (undefined4 *)(param_1 + DAT_02188924);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + DAT_02188928) = *puVar1;
  *(undefined4 *)(param_1 + DAT_0218892c) = 0;
  puVar1 = (undefined4 *)(param_1 + DAT_02188930);
  *puVar1 = param_3;
  *(undefined4 *)(param_1 + DAT_02188934) = *puVar1;
  puVar1 = (undefined4 *)(param_1 + DAT_0218893c);
  *puVar1 = DAT_02188938;
  *(undefined4 *)(param_1 + DAT_02188940) = *puVar1;
  puVar1 = (undefined4 *)(param_1 + DAT_02188944);
  *puVar1 = param_3;
  *(undefined4 *)(param_1 + DAT_02188948) = *puVar1;
  *(undefined4 *)(param_1 + DAT_0218894c) = 0;
  return;
}

