/* Decompiled C draft; module arm9_ov001; ROM address 02194a50. No matching claim. */
#include "types.h"
#include "deps/02194a50_FUN_02194a50.h"

void FUN_02194a50(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  int local_48;
  ushort *local_44;
  ushort *local_40;
  ushort *local_3c;
  ushort *local_38;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  
  piVar3 = DAT_02194c64;
  local_48 = 0;
  *(undefined4 *)(*DAT_02194c64 + 100) = 0;
  *(undefined4 *)(*piVar3 + 0x68) = 0;
  *(undefined4 *)(*piVar3 + 0x6c) = 0xffffff40;
  *(undefined4 *)(*piVar3 + 0x70) = 0xffffff00;
  iVar5 = *piVar3;
  uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + 6);
  uVar7 = (uint)*(ushort *)(*(int *)(iVar5 + 0x1c) + 6);
  uVar2 = (undefined2)DAT_02194c68;
  *(undefined2 *)(*(int *)(iVar5 + 0x50) + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x50) + 0x44) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x50) + (uint)uVar1 * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x54) + DAT_02194c6c) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x54) + DAT_02194c70) = uVar2;
  local_44 = DAT_02194c74;
  local_40 = DAT_02194c78;
  local_3c = DAT_02194c7c;
  local_38 = DAT_02194c80;
  local_34 = DAT_02194c84;
  local_30 = DAT_02194c88;
  local_2c = DAT_02194c8c;
  local_28 = DAT_02194c90;
  local_24 = DAT_02194c94;
  do {
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*local_44 * 0x40 + 4) = uVar2;
    *(short *)(*(int *)(*piVar3 + 0x54) + (uint)*local_44 * 0x40 + 6) =
         (short)*(undefined4 *)(*piVar3 + 0x74);
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*local_40 * 0x40 + 4) = uVar2;
    *(short *)(*(int *)(*piVar3 + 0x54) + (uint)*local_40 * 0x40 + 6) =
         (short)*(undefined4 *)(*piVar3 + 0x74);
    iVar5 = 0;
    puVar6 = local_3c;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar6 * 0x40 + 4) = uVar2;
      *(short *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar6 * 0x40 + 6) =
           (short)*(undefined4 *)(*piVar3 + 0x74);
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*local_38 * 0x40 + 4) = uVar2;
    *(short *)(*(int *)(*piVar3 + 0x54) + (uint)*local_38 * 0x40 + 6) =
         (short)*(undefined4 *)(*piVar3 + 0x74);
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uVar7 + *local_34) * 0x40 + 4) = uVar2;
    *(short *)(*(int *)(*piVar3 + 0x54) + (uVar7 + *local_34) * 0x40 + 6) =
         (short)*(undefined4 *)(*piVar3 + 0x74);
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uVar7 + *local_30) * 0x40 + 4) = uVar2;
    *(short *)(*(int *)(*piVar3 + 0x54) + (uVar7 + *local_30) * 0x40 + 6) =
         (short)*(undefined4 *)(*piVar3 + 0x74);
    *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uVar7 + *local_2c) * 0x40 + 4) = uVar2;
    *(short *)(*(int *)(*piVar3 + 0x54) + (uVar7 + *local_2c) * 0x40 + 6) =
         (short)*(undefined4 *)(*piVar3 + 0x74);
    iVar5 = 0;
    puVar6 = local_28;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar6 * 0x40 + 4) = uVar2;
      *(short *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar6 * 0x40 + 6) =
           (short)*(undefined4 *)(*piVar3 + 0x74);
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    iVar5 = 0;
    puVar6 = local_24;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar6 * 0x40 + 4) = uVar2;
      *(short *)(*(int *)(*piVar3 + 0x54) + (uint)*puVar6 * 0x40 + 6) =
           (short)*(undefined4 *)(*piVar3 + 0x74);
      piVar4 = DAT_02194c64;
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    local_44 = local_44 + 1;
    local_40 = local_40 + 1;
    local_3c = local_3c + 3;
    local_38 = local_38 + 1;
    local_34 = local_34 + 1;
    local_30 = local_30 + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 3;
    local_24 = local_24 + 2;
    local_48 = local_48 + 1;
  } while (local_48 < 4);
  iVar5 = 0;
  puVar6 = DAT_02194c98;
  do {
    *(undefined4 *)(*(int *)(*piVar4 + 0x54) + (uint)*puVar6 * 0x40) = 0;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

