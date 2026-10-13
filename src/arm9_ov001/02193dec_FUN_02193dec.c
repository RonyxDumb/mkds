/* Decompiled C draft; module arm9_ov001; ROM address 02193dec. No matching claim. */
#include "types.h"
#include "deps/02193dec_FUN_02193dec.h"

void FUN_02193dec(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  int local_44;
  ushort *local_40;
  ushort *local_3c;
  ushort *local_38;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  
  piVar3 = DAT_02193f64;
  *(int *)(*DAT_02193f64 + 0x68) = *(int *)(*DAT_02193f64 + 0x68) + 1;
  uVar4 = func_0x020ae4c0(1,0,DAT_02193f68,*(undefined4 *)(*piVar3 + 0x68),10);
  piVar3 = DAT_02193f64;
  *(undefined4 *)(*DAT_02193f64 + 0x70) = uVar4;
  iVar6 = *piVar3;
  uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(iVar6 + 0x1c) + 6);
  uVar2 = (undefined2)uVar4;
  *(undefined2 *)(*(int *)(iVar6 + 0x50) + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x50) + 0x44) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x50) + (uint)uVar1 * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x54) + DAT_02193f6c) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x54) + DAT_02193f70) = uVar2;
  local_44 = 0;
  local_40 = DAT_02193f78;
  local_3c = DAT_02193f7c;
  local_38 = DAT_02193f80;
  local_34 = DAT_02193f84;
  local_30 = DAT_02193f88;
  local_2c = DAT_02193f8c;
  local_28 = DAT_02193f90;
  local_24 = DAT_02193f94;
  puVar8 = DAT_02193f74;
  do {
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar8 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*local_40 * 0x40 + 4) = uVar2;
    iVar6 = 0;
    puVar7 = local_3c;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar7 * 0x40 + 4) = uVar2;
      puVar7 = puVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*local_38 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uVar5 + *local_34) * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uVar5 + *local_30) * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uVar5 + *local_2c) * 0x40 + 4) = uVar2;
    iVar6 = 0;
    puVar7 = local_28;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar7 * 0x40 + 4) = uVar2;
      puVar7 = puVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    iVar6 = 0;
    puVar7 = local_24;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar7 * 0x40 + 4) = uVar2;
      puVar7 = puVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    puVar8 = puVar8 + 1;
    local_40 = local_40 + 1;
    local_3c = local_3c + 3;
    local_38 = local_38 + 1;
    local_34 = local_34 + 1;
    local_30 = local_30 + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 3;
    local_24 = local_24 + 2;
    local_44 = local_44 + 1;
  } while (local_44 < 4);
  if (9 < *(int *)(*piVar3 + 0x68)) {
    FUN_021949ac();
  }
  return;
}

