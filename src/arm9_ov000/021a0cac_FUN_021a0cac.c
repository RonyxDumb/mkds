/* Decompiled C draft; module arm9_ov000; ROM address 021a0cac. No matching claim. */
#include "types.h"
#include "deps/021a0cac_FUN_021a0cac.h"

undefined4 FUN_021a0cac(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  piVar3 = DAT_021a0e8c;
  iVar10 = *DAT_021a0e8c;
  uVar11 = (uint)*(byte *)(iVar10 + 0x14);
  local_20 = 0;
  if (param_1 != 0) {
    bVar2 = true;
    *(undefined1 *)(iVar10 + DAT_021a0ec0) = 1;
    *(undefined1 *)(*piVar3 + DAT_021a0ec4) = 0;
    *(undefined2 *)(*piVar3 + DAT_021a0ec8) = 0;
    *(undefined4 *)(*piVar3 + DAT_021a0ecc) = 0;
    *(undefined4 *)(*piVar3 + DAT_021a0eb8) = param_2;
    goto LAB_021a0e44;
  }
  uVar12 = *(uint *)(iVar10 + DAT_021a0e90) & DAT_021a0e94;
  uVar1 = *(ushort *)(iVar10 + DAT_021a0e98);
  iVar10 = FUN_0218b248(param_3);
  if (iVar10 == 0) {
    uVar6 = FUN_021a8ed4();
    if ((uVar6 & 0xffff & DAT_021a0e94) != DAT_021a0ea4) {
      if ((uVar6 & 0xff) == 0xac) {
        uVar7 = uVar6 & 0xffff & DAT_021a0ea8;
        if ((DAT_021a0eac <= uVar7) && (uVar7 <= DAT_021a0eb0)) goto LAB_021a0d54;
      }
      if ((uVar6 & 0xff) != 0x10) {
        uVar9 = FUN_0218b27c((undefined4 *)(uintptr_t)(param_3));
        *(undefined4 *)(*DAT_021a0e8c + uVar11 * 4 + DAT_021a0e9c) = uVar9;
        uVar4 = FUN_0218b260(param_3);
        *(undefined2 *)(*DAT_021a0e8c + uVar11 * 2 + DAT_021a0ea0) = uVar4;
        bVar2 = false;
        goto LAB_021a0d7e;
      }
    }
LAB_021a0d54:
    bVar2 = true;
  }
  else {
    iVar10 = FUN_0218b27c((undefined4 *)(uintptr_t)(param_3));
    iVar5 = FUN_0218b458(*(undefined4 *)(*DAT_021a0e8c + 0xe4));
    if (iVar10 == iVar5) {
      uVar9 = FUN_0218b244(param_3);
      *(undefined4 *)(*DAT_021a0e8c + uVar11 * 4 + DAT_021a0e9c) = uVar9;
      uVar4 = FUN_0218b228(param_3);
      *(undefined2 *)(*DAT_021a0e8c + uVar11 * 2 + DAT_021a0ea0) = uVar4;
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
LAB_021a0d7e:
  if (bVar2) {
    uVar4 = FUN_021a3448(DAT_021a0eb4);
    piVar3 = DAT_021a0e8c;
    *(undefined2 *)(*DAT_021a0e8c + DAT_021a0e98) = uVar4;
    *(uint *)(*piVar3 + DAT_021a0eb8) = uVar12 | (uint)uVar1 << 0x10;
  }
  else {
    local_1c = FUN_021a8ed4();
    local_18 = FUN_021988e4(**(undefined4 **)(*DAT_021a0e8c + 4));
    uVar9 = FUN_0218b27c((undefined4 *)(uintptr_t)(param_3));
    uVar8 = FUN_0218b260(param_3);
    iVar10 = FUN_021a0ae8(6,*(undefined4 *)(*DAT_021a0e8c + uVar11 * 4 + 0xf4),uVar9,uVar8,&local_1c
                          ,2);
    piVar3 = DAT_021a0e8c;
    *(undefined1 *)(*DAT_021a0e8c + DAT_021a0ebc) = 0;
    if (iVar10 != 0) {
      return 2;
    }
    *(undefined4 *)(*piVar3 + DAT_021a0eb8) = 0;
  }
  piVar3 = DAT_021a0e8c;
  *(undefined1 *)(*DAT_021a0e8c + DAT_021a0ec0) = 0;
  *(undefined1 *)(*piVar3 + DAT_021a0ec4) = 0;
  uVar4 = FUN_0218b260(param_3);
  *(undefined2 *)(*DAT_021a0e8c + DAT_021a0ec8) = uVar4;
  uVar9 = FUN_0218b27c((undefined4 *)(uintptr_t)(param_3));
  *(undefined4 *)(*DAT_021a0e8c + DAT_021a0ecc) = uVar9;
LAB_021a0e44:
  if (bVar2) {
    local_20 = FUN_021a0c30((char *)(uintptr_t)(*DAT_021a0e8c + DAT_021a0ec0));
  }
  else {
    iVar10 = *DAT_021a0e8c;
    uVar9 = FUN_021988d8((undefined4 *)(uintptr_t)(**(undefined4 **)(iVar10 + 4)));
    FUN_0219db18(0,uVar9,0,(char *)(uintptr_t)(iVar10 + DAT_021a0ec0));
    iVar10 = *DAT_021a0e8c;
    *(undefined4 *)(iVar10 + DAT_021a0ed0) = 0;
    *(undefined4 *)(iVar10 + DAT_021a0ed4) = 0;
  }
  return local_20;
}

