/* Decompiled C draft; module arm9_ov001; ROM address 0219a3a0. No matching claim. */
#include "types.h"
#include "deps/0219a3a0_FUN_0219a3a0.h"

void FUN_0219a3a0(void)

{
  undefined2 uVar1;
  int *piVar2;
  int *piVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *local_24;
  int local_20;
  int local_1c;
  
  iVar5 = func_0x0211145c();
  if ((iVar5 == -1) && (*(int *)(*DAT_0219a4e0 + 0x44) == 5)) {
    func_0x02111450(0);
  }
  piVar2 = DAT_0219a4e0;
  *(int *)(*DAT_0219a4e0 + 0x38) = *(int *)(*DAT_0219a4e0 + 0x38) + 1;
  uVar4 = func_0x020ae4c0(1,0,0xe0,*(undefined4 *)(*piVar2 + 0x38),10);
  uVar6 = func_0x020ae4c0(1,0,0xffffff40,*(undefined4 *)(*DAT_0219a4e0 + 0x38),10);
  piVar2 = DAT_0219a4e0;
  *(undefined4 *)(*DAT_0219a4e0 + 0x3c) = uVar6;
  uVar8 = (uint)*(ushort *)(*(int *)(*piVar2 + 4) + 6);
  uVar1 = (undefined2)uVar6;
  *(undefined2 *)(*(int *)(*piVar2 + 0x18) + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x18) + 0x46) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x18) + uVar8 * 0x40 + 6) = uVar1;
  iVar5 = 0;
  puVar7 = DAT_0219a4e4;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar7 * 0x40 + 6) = uVar1;
    piVar3 = DAT_0219a4e0;
    puVar7 = puVar7 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  local_1c = 0;
  local_24 = DAT_0219a4e8;
  do {
    iVar5 = 0;
    puVar7 = local_24;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uVar8 + *puVar7) * 0x40 + 6) = uVar1;
      piVar2 = DAT_0219a4e0;
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    local_24 = local_24 + 3;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  local_20 = 0;
  puVar7 = DAT_0219a4f8;
  puVar9 = DAT_0219a4f4;
  puVar10 = DAT_0219a4f0;
  puVar11 = DAT_0219a4ec;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar11 * 0x40 + 4) = uVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar10 * 0x40 + 4) = uVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar9 * 0x40 + 4) = uVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar7 * 0x40 + 4) = uVar4;
    puVar11 = puVar11 + 1;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
    puVar7 = puVar7 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 3);
  if ((9 < *(int *)(*piVar2 + 0x38)) && (iVar5 = func_0x0211145c(), iVar5 == -1)) {
    func_0x02111488(*(undefined4 *)(*DAT_0219a4e0 + 0x44));
  }
  return;
}

