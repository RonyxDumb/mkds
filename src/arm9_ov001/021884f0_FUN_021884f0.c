/* Decompiled C draft; module arm9_ov001; ROM address 021884f0. No matching claim. */
#include "types.h"
#include "deps/021884f0_FUN_021884f0.h"

void FUN_021884f0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(param_1 + DAT_02188588) = 1;
  if ((*(ushort *)(param_1 + 2) & DAT_0218858c) != 0) {
    param_2 = -param_2;
  }
  piVar2 = (int *)(param_1 + DAT_02188590);
  *piVar2 = param_2;
  piVar1 = (int *)(param_1 + DAT_02188594);
  *piVar1 = *piVar2;
  piVar3 = (int *)(param_1 + DAT_02188598);
  *piVar3 = param_3;
  piVar2 = (int *)(param_1 + DAT_0218859c);
  *piVar2 = *piVar3;
  piVar4 = (int *)(param_1 + DAT_021885a0);
  *piVar4 = param_4;
  piVar3 = (int *)(param_1 + DAT_021885a4);
  *piVar3 = *piVar4;
  *(undefined4 *)(param_1 + DAT_021885a8) = 0;
  puVar5 = (undefined4 *)(param_1 + DAT_021885ac);
  *puVar5 = param_5;
  *(undefined4 *)(param_1 + DAT_021885b0) = *puVar5;
  puVar5 = (undefined4 *)(param_1 + DAT_021885b4);
  *puVar5 = param_6;
  *(undefined4 *)(param_1 + DAT_021885b8) = *puVar5;
  puVar5 = (undefined4 *)(param_1 + DAT_021885bc);
  *puVar5 = param_7;
  *(undefined4 *)(param_1 + DAT_021885c0) = *puVar5;
  *(undefined4 *)(param_1 + DAT_021885c4) = 0;
  *(int *)(param_1 + DAT_021885c8) = *(int *)(param_1 + 4) + *piVar1;
  *(int *)(param_1 + DAT_021885cc) = *(int *)(param_1 + 8) + *piVar2;
  *(int *)(param_1 + DAT_021885d0) = *(int *)(param_1 + 0xc) + *piVar3;
  return;
}

