/* Decompiled C draft; module arm9_ov001; ROM address 021a04f0. No matching claim. */
#include "types.h"
#include "deps/021a04f0_FUN_021a04f0.h"

void FUN_021a04f0(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  ushort *local_28;
  ushort *local_24;
  int local_20;
  
  piVar4 = DAT_021a05f8;
  iVar6 = *DAT_021a05f8;
  uVar1 = *(ushort *)(*(int *)(iVar6 + 4) + 6);
  uVar2 = *(ushort *)(*(int *)(iVar6 + 0x10) + 6);
  iVar8 = 0;
  *(undefined4 *)(iVar6 + 100) = 0;
  *(undefined4 *)(*piVar4 + 0x68) = 0;
  uVar5 = DAT_021a05fc;
  *(undefined4 *)(*piVar4 + 0x90) = DAT_021a05fc;
  *(undefined4 *)(*piVar4 + 0x94) = 0;
  *(undefined4 *)(*piVar4 + 0x98) = 0xffffff40;
  uVar3 = (undefined2)uVar5;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + 4) = uVar3;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + 0x44) = uVar3;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + DAT_021a0600) = uVar3;
  *(undefined2 *)(*(int *)(*piVar4 + 0x40) + DAT_021a0604) = uVar3;
  puVar7 = DAT_021a0608;
  do {
    *(undefined2 *)(*(int *)(*piVar4 + 0x40) + (uint)*puVar7 * 0x40 + 4) = uVar3;
    puVar7 = puVar7 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 7);
  *(undefined2 *)(*(int *)(*piVar4 + 0x44) + DAT_021a060c) = uVar3;
  uVar5 = DAT_021a05fc;
  piVar4 = DAT_021a05f8;
  iVar6 = 0;
  puVar7 = DAT_021a0610;
  do {
    *(short *)(*(int *)(*piVar4 + 0x40) + (uint)*puVar7 * 0x40 + 4) = (short)uVar5;
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 6);
  *(short *)(*(int *)(*piVar4 + 0x40) + (uint)uVar1 * 0x40 + 4) = (short)uVar5;
  uVar5 = DAT_021a05fc;
  piVar4 = DAT_021a05f8;
  local_20 = 0;
  local_28 = DAT_021a0618;
  local_24 = DAT_021a061c;
  puVar7 = DAT_021a0614;
  do {
    uVar3 = (undefined2)uVar5;
    *(undefined2 *)(*(int *)(*piVar4 + 0x40) + (uint)*puVar7 * 0x40 + 4) = uVar3;
    iVar6 = 0;
    puVar9 = local_28;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x44) + (uint)*puVar9 * 0x40 + 4) = uVar3;
      puVar9 = puVar9 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    iVar6 = 0;
    puVar9 = local_24;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x44) + ((uint)uVar2 + (uint)*puVar9) * 0x40 + 4) = uVar3;
      puVar9 = puVar9 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    puVar7 = puVar7 + 1;
    local_28 = local_28 + 9;
    local_24 = local_24 + 2;
    local_20 = local_20 + 1;
  } while (local_20 < 9);
  return;
}

