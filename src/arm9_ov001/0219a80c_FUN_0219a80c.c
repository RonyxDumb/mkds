/* Decompiled C draft; module arm9_ov001; ROM address 0219a80c. No matching claim. */
#include "types.h"
#include "deps/0219a80c_FUN_0219a80c.h"

void FUN_0219a80c(void)

{
  undefined2 uVar1;
  int *piVar2;
  int *piVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  uint uVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  int iVar11;
  ushort *local_24;
  int local_20;
  int local_1c;
  
  piVar2 = DAT_0219a91c;
  *(int *)(*DAT_0219a91c + 0x38) = *(int *)(*DAT_0219a91c + 0x38) + 1;
  uVar4 = func_0x020ae4c0(1,0xe0,0,*(undefined4 *)(*piVar2 + 0x38),10);
  uVar5 = func_0x020ae4c0(1,0xffffff40,0,*(undefined4 *)(*DAT_0219a91c + 0x38),10);
  piVar2 = DAT_0219a91c;
  *(undefined4 *)(*DAT_0219a91c + 0x3c) = uVar5;
  uVar7 = (uint)*(ushort *)(*(int *)(*piVar2 + 4) + 6);
  uVar1 = (undefined2)uVar5;
  *(undefined2 *)(*(int *)(*piVar2 + 0x18) + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x18) + 0x46) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x18) + uVar7 * 0x40 + 6) = uVar1;
  iVar11 = 0;
  puVar6 = DAT_0219a920;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar6 * 0x40 + 6) = uVar1;
    piVar3 = DAT_0219a91c;
    puVar6 = puVar6 + 1;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 3);
  local_1c = 0;
  local_24 = DAT_0219a924;
  do {
    iVar11 = 0;
    puVar6 = local_24;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uVar7 + *puVar6) * 0x40 + 6) = uVar1;
      piVar2 = DAT_0219a91c;
      puVar6 = puVar6 + 1;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 3);
    local_24 = local_24 + 3;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  local_20 = 0;
  puVar6 = DAT_0219a934;
  puVar8 = DAT_0219a930;
  puVar9 = DAT_0219a92c;
  puVar10 = DAT_0219a928;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar10 * 0x40 + 4) = uVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar9 * 0x40 + 4) = uVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar8 * 0x40 + 4) = uVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar6 * 0x40 + 4) = uVar4;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
    puVar6 = puVar6 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 3);
  if (9 < *(int *)(*piVar2 + 0x38)) {
    FUN_0219ae60();
  }
  return;
}

