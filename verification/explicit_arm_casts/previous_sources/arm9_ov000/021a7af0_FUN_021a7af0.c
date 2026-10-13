/* Decompiled C draft; module arm9_ov000; ROM address 021a7af0. No matching claim. */
#include "types.h"
#include "deps/021a7af0_FUN_021a7af0.h"

uint FUN_021a7af0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_1c [2];
  
  iVar8 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar8 + 100);
  uVar5 = *(undefined4 *)(param_1 + 0x10);
  uVar9 = *(uint *)(param_1 + 0x14);
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  iVar7 = *(int *)(iVar4 + 0xf8);
  while( true ) {
    iVar2 = FUN_021adf78(local_1c);
    if ((iVar2 == 0) || (0 < (int)(local_1c[0] - iVar7))) goto LAB_021a7b46;
    bVar3 = true;
    if ((*(char *)(iVar8 + 0x73) != '\0') && (*(char *)(iVar8 + 0x73) != '\x04')) {
      bVar3 = false;
    }
    if ((bVar3) && (*(char *)(iVar8 + 8) != '\x04')) break;
    func_0x0200dc3c(10);
  }
  iVar2 = 0;
LAB_021a7b46:
  if (*(char *)(iVar8 + 0x73) == '\x04') {
    if (iVar2 == 0) {
      return 0;
    }
    if (local_1c[0] < uVar9) {
      uVar9 = local_1c[0];
    }
    func_0x0214d1fc(iVar2,uVar5,uVar9);
    FUN_021adf00(uVar9);
    return uVar9;
  }
  if (iVar2 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = FUN_021a7c4c(iVar8,uVar5,uVar9,uVar6,uVar1);
  }
  if ((int)uVar9 < 1) {
    return uVar9;
  }
  if ((int)(uint)*(ushort *)(iVar4 + 0xfc) <= *(int *)(iVar4 + 0xf8)) {
    FUN_021a7a6c(iVar8);
  }
  return uVar9;
}

