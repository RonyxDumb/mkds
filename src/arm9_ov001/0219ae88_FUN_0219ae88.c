/* Decompiled C draft; module arm9_ov001; ROM address 0219ae88. No matching claim. */
#include "types.h"
#include "deps/0219ae88_FUN_0219ae88.h"

void FUN_0219ae88(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  int local_20;
  int local_1c;
  
  piVar1 = DAT_0219af74;
  iVar6 = 0;
  *(undefined4 *)(*DAT_0219af74 + 0x34) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  *(undefined4 *)(*piVar1 + 0x3c) = 0xffffff40;
  uVar3 = (uint)*(ushort *)(*(int *)(*piVar1 + 4) + 6);
  *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 0x46) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar1 + 0x18) + uVar3 * 0x40 + 6) = 0xff40;
  puVar4 = DAT_0219af78;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar4 * 0x40 + 6) = 0xff40;
    piVar2 = DAT_0219af74;
    puVar4 = puVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  local_1c = 0;
  puVar4 = DAT_0219af7c;
  do {
    iVar6 = 0;
    puVar5 = puVar4;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x18) + (uVar3 + *puVar5) * 0x40 + 6) = 0xff40;
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    puVar4 = puVar4 + 3;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  local_20 = 0;
  puVar4 = DAT_0219af84;
  puVar5 = DAT_0219af80;
  puVar7 = DAT_0219af88;
  puVar8 = DAT_0219af8c;
  do {
    *(undefined2 *)(*(int *)(*DAT_0219af74 + 0x1c) + (uint)*puVar5 * 0x40 + 4) = 0xe0;
    *(undefined2 *)(*(int *)(*DAT_0219af74 + 0x1c) + (uint)*puVar4 * 0x40 + 4) = 0xe0;
    *(undefined2 *)(*(int *)(*DAT_0219af74 + 0x1c) + (uint)*puVar7 * 0x40 + 4) = 0xe0;
    *(undefined2 *)(*(int *)(*DAT_0219af74 + 0x1c) + (uint)*puVar8 * 0x40 + 4) = 0xe0;
    FUN_0219af90(local_20);
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 3);
  return;
}

