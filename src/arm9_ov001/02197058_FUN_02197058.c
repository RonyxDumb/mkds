/* Decompiled C draft; module arm9_ov001; ROM address 02197058. No matching claim. */
#include "types.h"
#include "deps/02197058_FUN_02197058.h"

void FUN_02197058(void)

{
  undefined2 uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  int local_20;
  ushort *local_1c;
  ushort *local_18;
  
  piVar2 = DAT_021971d0;
  *(undefined4 *)(*DAT_021971d0 + 0x54) = 0;
  *(undefined4 *)(*piVar2 + 0x58) = 0;
  *(undefined4 *)(*piVar2 + 0x5c) = 0xffffff40;
  *(undefined4 *)(*piVar2 + 0x60) = 0xffffff00;
  *(undefined4 *)(*piVar2 + 100) = 0xffffff40;
  *(undefined4 *)(*piVar2 + 0x68) = 0xffffff00;
  iVar7 = *piVar2;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar7 + 8) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(iVar7 + 0x1c) + 6);
  *(undefined2 *)(*(int *)(iVar7 + 0x38) + 6) = 0xff40;
  uVar1 = (undefined2)DAT_021971d4;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x44) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x84) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0xc4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_021971d8) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_021971dc) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_021971e0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + uVar4 * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 1) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 2) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 3) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 4) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021971e4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021971e8) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021971ec) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021971f0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021971f4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + 8) * 0x40 + 4) = uVar1;
  local_20 = 1;
  local_1c = DAT_02197200;
  local_18 = DAT_02197204;
  puVar8 = DAT_021971f8;
  puVar9 = DAT_021971fc;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + *puVar9) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + *local_1c) * 0x40 + 4) = uVar1;
    iVar7 = 0;
    puVar6 = local_18;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar1;
      piVar3 = DAT_021971d0;
      puVar6 = puVar6 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
    local_1c = local_1c + 1;
    local_18 = local_18 + 2;
    local_20 = local_20 + 1;
  } while (local_20 < 5);
  iVar7 = 0;
  puVar8 = DAT_02197208;
  do {
    *(undefined4 *)(*(int *)(*piVar3 + 0x3c) + (uint)*puVar8 * 0x40) = 0;
    puVar8 = puVar8 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  *(undefined4 *)(*(int *)(*piVar3 + 0x3c) + DAT_0219720c) = 0;
  return;
}

