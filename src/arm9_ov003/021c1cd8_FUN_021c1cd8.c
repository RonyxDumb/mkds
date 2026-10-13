/* Decompiled C draft; module arm9_ov003; ROM address 021c1cd8. No matching claim. */
#include "types.h"
#include "deps/021c1cd8_FUN_021c1cd8.h"

void FUN_021c1cd8(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  int iVar11;
  undefined2 *puVar12;
  int iVar13;
  undefined1 *puVar14;
  int local_50;
  int local_4c;
  int local_40;
  int local_2c;
  short local_24;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  
  uVar1 = *(undefined2 *)(DAT_021c1eec + 2);
  uVar2 = *DAT_021c1ef0;
  uVar3 = DAT_021c1ef0[1];
  iVar8 = FUN_021d283c(0x6c,4);
  piVar6 = DAT_021c1ef4;
  *DAT_021c1ef4 = iVar8;
  *(undefined1 *)(iVar8 + 0x60) = 0x1f;
  iVar13 = 0;
  *(undefined1 *)(*piVar6 + 99) = 0;
  *(undefined1 *)(*piVar6 + 0x66) = 1;
  *(undefined1 *)(*piVar6 + 0x67) = 1;
  *(undefined1 *)(*piVar6 + 0x68) = 1;
  iVar8 = 0;
  do {
    uVar9 = FUN_021d1c18(0,0x36);
    *(undefined4 *)(*piVar6 + iVar8 + 0x10) = uVar9;
    puVar10 = *(uint **)(*piVar6 + iVar8 + 0x10);
    *puVar10 = *puVar10 & DAT_021c1ef8 | DAT_021c1efc;
    iVar11 = *(int *)(*piVar6 + iVar8 + 0x10);
    *(ushort *)(iVar11 + 4) = *(ushort *)(iVar11 + 4) & (ushort)DAT_021c1f00 | (ushort)DAT_021c1f04;
    piVar7 = DAT_021c1ef4;
    iVar8 = iVar8 + 4;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 10);
  iVar13 = 0;
  iVar8 = 0;
  puVar14 = DAT_021c1f08;
  do {
    uVar9 = FUN_021d1c18(0,*puVar14);
    *(undefined4 *)(*piVar7 + iVar8 + 0x38) = uVar9;
    puVar10 = *(uint **)(*piVar7 + iVar8 + 0x38);
    *puVar10 = *puVar10 & DAT_021c1ef8 | DAT_021c1efc;
    iVar11 = *(int *)(*piVar7 + iVar8 + 0x38);
    *(ushort *)(iVar11 + 4) = *(ushort *)(iVar11 + 4) & (ushort)DAT_021c1f00 | (ushort)DAT_021c1f04;
    puVar14 = puVar14 + 1;
    iVar8 = iVar8 + 4;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 2);
  iVar13 = 0;
  iVar8 = 0;
  puVar14 = DAT_021c1f0c;
  do {
    uVar9 = FUN_021d1be4(0,*puVar14,1);
    *(undefined4 *)(*DAT_021c1ef4 + iVar8 + 0x40) = uVar9;
    FUN_021d18f0(*(undefined4 *)(*DAT_021c1ef4 + iVar8 + 0x40),0xffffffff,DAT_021c1efc,0);
    FUN_021d1790(*(undefined4 *)(*DAT_021c1ef4 + iVar8 + 0x40),0xffffffff,3);
    puVar14 = puVar14 + 1;
    iVar8 = iVar8 + 4;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 2);
  local_40 = 0;
  local_16 = 0;
  local_50 = 0;
  local_4c = 0;
  uVar4 = DAT_021c1f10[1];
  uVar5 = *DAT_021c1f10;
  local_2c = 0;
  do {
    uVar9 = FUN_021d23b0(0,uVar5,uVar4,0,&local_1c,0);
    *(undefined4 *)(*DAT_021c1ef4 + local_50) = uVar9;
    local_24 = 0;
    puVar12 = (undefined2 *)(DAT_021c1f14 + local_4c * 2);
    iVar8 = local_2c;
    do {
      local_18 = *puVar12;
      FUN_021d2070(*(undefined4 *)(local_50 + *DAT_021c1ef4),local_24,uVar1,uVar2,uVar3,2,
                   DAT_021c1f18,&local_18);
      iVar8 = iVar8 + 1;
      puVar12 = puVar12 + 1;
      local_24 = local_24 + 0x20;
    } while (iVar8 < 3);
    uVar9 = FUN_021d19e0(0,local_1c,0);
    *(undefined4 *)(*DAT_021c1ef4 + local_50 + 0x48) = uVar9;
    local_50 = local_50 + 4;
    local_4c = local_4c + 3;
    local_40 = local_40 + 1;
  } while (local_40 < 4);
  uVar9 = FUN_021d1be4(0,0x44,1);
  piVar6 = DAT_021c1ef4;
  *(undefined4 *)(*DAT_021c1ef4 + 0x58) = uVar9;
  FUN_021d18f0(*(undefined4 *)(*piVar6 + 0x58),0xffffffff,DAT_021c1efc);
  FUN_021d1790(*(undefined4 *)(*DAT_021c1ef4 + 0x58),0xffffffff,2);
  uVar9 = FUN_021d3544(0,DAT_021c1f1c,0,0x78);
  *(undefined4 *)(*DAT_021c1ef4 + 0x5c) = uVar9;
  FUN_021c1364(0,0xc0);
  return;
}

