/* Decompiled C draft; module arm9_ov000; ROM address 02186560. No matching claim. */
#include "types.h"
#include "deps/02186560_FUN_02186560.h"

int FUN_02186560(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (*DAT_02186604 != 0) {
    return 2;
  }
  iVar2 = (*(code *)param_1[9])(DAT_02186608,DAT_0218660c);
  if (iVar2 == 0) {
    return 2;
  }
  *DAT_02186604 = iVar2;
  func_0x0214d168((uint *)(uintptr_t)(iVar2),0,DAT_0218660c);
  piVar1 = DAT_02186604;
  *(undefined4 *)(*DAT_02186604 + DAT_02186610) = param_2;
  func_0x0214d168((uint *)(uintptr_t)(*piVar1 + 8),0,DAT_02186614);
  piVar1 = DAT_02186604;
  *(undefined4 *)(*DAT_02186604 + 8) = 0xffffffff;
  iVar2 = *piVar1;
  puVar5 = (undefined4 *)(iVar2 + DAT_02186618);
  iVar7 = 5;
  puVar6 = param_1;
  do {
    uVar3 = *puVar6;
    uVar4 = puVar6[1];
    puVar6 = puVar6 + 2;
    *puVar5 = uVar3;
    puVar5[1] = uVar4;
    puVar5 = puVar5 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *puVar5 = *puVar6;
  *(undefined1 *)(iVar2 + DAT_0218661c) = 0;
  *(undefined1 *)(*DAT_02186604 + DAT_02186620) = 0;
  iVar2 = DAT_02186624;
  *(undefined4 *)(DAT_02186624 + 0x10) = param_1[9];
  *(undefined4 *)(iVar2 + 0x14) = param_1[10];
  uVar3 = FUN_02186298(1);
  piVar1 = DAT_02186604;
  *(undefined4 *)(*DAT_02186604 + 4) = uVar3;
  iVar2 = *(int *)(*piVar1 + 4);
  if (iVar2 == 0) {
    FUN_021864e0();
    iVar2 = 0;
  }
  return iVar2;
}

