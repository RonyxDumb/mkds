/* Decompiled C draft; module arm9_ov001; ROM address 0218875c. No matching claim. */
#include "types.h"
#include "deps/0218875c_FUN_0218875c.h"

void FUN_0218875c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_4 == 0) {
    *(undefined4 *)(param_1 + DAT_021887f4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + DAT_021887f4) = 2;
  }
  piVar2 = (int *)(param_1 + DAT_021887f8);
  *piVar2 = 0;
  piVar5 = (int *)(param_1 + DAT_021887fc);
  *piVar5 = *piVar2;
  piVar2 = (int *)(param_1 + DAT_02188800);
  *piVar2 = param_2;
  piVar3 = (int *)(param_1 + DAT_02188804);
  *piVar3 = *piVar2;
  piVar2 = (int *)(param_1 + DAT_02188808);
  *piVar2 = 0;
  piVar4 = (int *)(param_1 + DAT_0218880c);
  *piVar4 = *piVar2;
  *(undefined4 *)(param_1 + DAT_02188810) = 0;
  puVar1 = (undefined4 *)(param_1 + DAT_02188814);
  *puVar1 = param_3;
  *(undefined4 *)(param_1 + DAT_02188818) = *puVar1;
  piVar2 = (int *)(param_1 + DAT_0218881c);
  *piVar2 = param_4;
  *(int *)(param_1 + DAT_02188820) = *piVar2;
  puVar1 = (undefined4 *)(param_1 + DAT_02188824);
  *puVar1 = param_3;
  *(undefined4 *)(param_1 + DAT_02188828) = *puVar1;
  *(undefined4 *)(param_1 + DAT_0218882c) = 0;
  *(int *)(param_1 + DAT_02188830) = *(int *)(param_1 + 4) + *piVar5;
  *(int *)(param_1 + DAT_02188834) = *(int *)(param_1 + 8) + *piVar3;
  *(int *)(param_1 + DAT_02188838) = *(int *)(param_1 + 0xc) + *piVar4;
  return;
}

