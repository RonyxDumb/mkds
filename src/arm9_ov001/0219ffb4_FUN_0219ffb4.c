/* Decompiled C draft; module arm9_ov001; ROM address 0219ffb4. No matching claim. */
#include "types.h"
#include "deps/0219ffb4_FUN_0219ffb4.h"

void FUN_0219ffb4(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *local_2c;
  ushort *local_28;
  int local_24;
  
  func_0x021055b0(*(undefined4 *)(*DAT_021a00f0 + 0xa8));
  piVar4 = DAT_021a00f0;
  iVar5 = *DAT_021a00f0;
  uVar1 = *(ushort *)(*(int *)(iVar5 + 4) + 6);
  uVar2 = *(ushort *)(*(int *)(iVar5 + 0x10) + 6);
  *(int *)(iVar5 + 0x68) = *(int *)(iVar5 + 0x68) + 1;
  uVar6 = func_0x020ae4c0(1,DAT_021a00f4,0,*(undefined4 *)(*piVar4 + 0x68),10);
  uVar7 = func_0x020ae4c0(1,0xffffff40,0,*(undefined4 *)(*DAT_021a00f0 + 0x68),10);
  piVar4 = DAT_021a00f0;
  *(undefined4 *)(*DAT_021a00f0 + 0x90) = uVar6;
  *(undefined4 *)(*piVar4 + 0x98) = uVar7;
  uVar3 = (undefined2)uVar6;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + 4) = uVar3;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + 0x44) = uVar3;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + DAT_021a00f8) = uVar3;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + DAT_021a00fc) = uVar3;
  iVar5 = 0;
  puVar8 = DAT_021a0100;
  do {
    *(undefined2 *)(*(int *)(*piVar4 + 0x40) + (uint)*puVar8 * 0x40 + 4) = uVar3;
    puVar8 = puVar8 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  *(undefined2 *)(*(int *)(*piVar4 + 0x44) + DAT_021a0104) = uVar3;
  piVar4 = DAT_021a00f0;
  iVar5 = 0;
  puVar8 = DAT_021a0108;
  do {
    *(undefined2 *)(*(int *)(*piVar4 + 0x40) + (uint)*puVar8 * 0x40 + 4) = uVar3;
    puVar8 = puVar8 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + (uint)uVar1 * 0x40 + 4) = uVar3;
  piVar4 = DAT_021a00f0;
  local_24 = 0;
  local_2c = DAT_021a0110;
  local_28 = DAT_021a0114;
  puVar8 = DAT_021a010c;
  do {
    *(undefined2 *)(*(int *)(*piVar4 + 0x40) + (uint)*puVar8 * 0x40 + 4) = uVar3;
    iVar5 = 0;
    puVar9 = local_2c;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x44) + (uint)*puVar9 * 0x40 + 4) = uVar3;
      puVar9 = puVar9 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 9);
    iVar5 = 0;
    puVar9 = local_28;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x44) + ((uint)uVar2 + (uint)*puVar9) * 0x40 + 4) = uVar3;
      puVar9 = puVar9 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    puVar8 = puVar8 + 1;
    local_2c = local_2c + 9;
    local_28 = local_28 + 2;
    local_24 = local_24 + 1;
  } while (local_24 < 9);
  if (9 < *(int *)(*piVar4 + 0x68)) {
    FUN_021a04c0();
  }
  return;
}

