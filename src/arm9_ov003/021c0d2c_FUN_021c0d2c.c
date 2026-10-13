/* Decompiled C draft; module arm9_ov003; ROM address 021c0d2c. No matching claim. */
#include "types.h"
#include "deps/021c0d2c_FUN_021c0d2c.h"

void FUN_021c0d2c(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  int local_68;
  int local_64;
  int *local_60;
  int local_54;
  int local_50;
  int local_48;
  int local_30;
  short local_28;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  
  uVar1 = *DAT_021c0f84;
  uVar2 = DAT_021c0f84[1];
  iVar7 = FUN_021d283c(DAT_021c0f88,4);
  piVar5 = DAT_021c0f8c;
  *DAT_021c0f8c = iVar7;
  *(undefined1 *)(iVar7 + DAT_021c0f90) = 0xff;
  iVar11 = 0;
  *(undefined1 *)(*piVar5 + DAT_021c0f94) = 0;
  *(undefined1 *)(*piVar5 + DAT_021c0f98) = 1;
  *(undefined1 *)(*piVar5 + DAT_021c0f9c) = 1;
  iVar7 = 0;
  do {
    uVar8 = FUN_021d1c18(0,0x34);
    *(undefined4 *)(*piVar5 + iVar7 + 0x30) = uVar8;
    puVar9 = *(uint **)(*piVar5 + iVar7 + 0x30);
    *puVar9 = *puVar9 & DAT_021c0fa0 | DAT_021c0fa4;
    iVar10 = *(int *)(*piVar5 + iVar7 + 0x30);
    *(ushort *)(iVar10 + 4) = *(ushort *)(iVar10 + 4) & (ushort)DAT_021c0fa8 | (ushort)DAT_021c0fac;
    piVar6 = DAT_021c0f8c;
    iVar7 = iVar7 + 4;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0x2f);
  iVar11 = 0;
  iVar7 = 0;
  puVar12 = DAT_021c0fb0;
  do {
    uVar8 = FUN_021d1c18(0,*puVar12);
    *(undefined4 *)(*piVar6 + iVar7 + 0xec) = uVar8;
    puVar9 = *(uint **)(*piVar6 + iVar7 + 0xec);
    *puVar9 = *puVar9 & DAT_021c0fa0 | DAT_021c0fa4;
    iVar10 = *(int *)(*piVar6 + iVar7 + 0xec);
    *(ushort *)(iVar10 + 4) = *(ushort *)(iVar10 + 4) & (ushort)DAT_021c0fa8 | (ushort)DAT_021c0fac;
    puVar12 = puVar12 + 1;
    iVar7 = iVar7 + 4;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 4);
  iVar11 = 0;
  iVar7 = 0;
  puVar12 = DAT_021c0fb4;
  do {
    uVar8 = FUN_021d1be4(0,*puVar12,1);
    *(undefined4 *)(*DAT_021c0f8c + iVar7 + 0xfc) = uVar8;
    FUN_021d18f0(*(undefined4 *)(*DAT_021c0f8c + iVar7 + 0xfc),0xffffffff,DAT_021c0fa4,0);
    FUN_021d1790(*(undefined4 *)(*DAT_021c0f8c + iVar7 + 0xfc),0xffffffff,3);
    puVar12 = puVar12 + 1;
    iVar7 = iVar7 + 4;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 2);
  local_48 = 0;
  local_1a = 0;
  local_64 = 0;
  local_60 = DAT_021c0fb8;
  uVar3 = DAT_021c0fbc[1];
  uVar4 = *DAT_021c0fbc;
  local_30 = 0;
  do {
    local_68 = 0;
    local_54 = 0;
    local_50 = 0;
    do {
      uVar8 = FUN_021d23b0(0,uVar4,uVar3,0,&local_20,0);
      *(undefined4 *)(local_54 + local_64 + *DAT_021c0f8c) = uVar8;
      local_28 = 0;
      iVar11 = local_50 << 1;
      iVar7 = local_30;
      do {
        local_1c = *(undefined2 *)(*local_60 + iVar11);
        FUN_021d2070(*(undefined4 *)(local_64 + local_54 + *DAT_021c0f8c),local_28,0,uVar1,uVar2,2,
                     DAT_021c0fc0,&local_1c);
        iVar7 = iVar7 + 1;
        iVar11 = iVar11 + 2;
        local_28 = local_28 + 0x12;
      } while (iVar7 < 0xc);
      if (local_48 == 0) {
        uVar8 = FUN_021d19e0(0,local_20,1);
        *(undefined4 *)(*DAT_021c0f8c + local_54 + DAT_021c0fc4) = uVar8;
      }
      local_54 = local_54 + 4;
      local_50 = local_50 + 0xc;
      local_68 = local_68 + 1;
    } while (local_68 < 4);
    local_64 = local_64 + 0x10;
    local_60 = local_60 + 1;
    local_48 = local_48 + 1;
  } while (local_48 < 3);
  uVar8 = FUN_021d1be4(0,0x40,1);
  iVar7 = DAT_021c0fc8;
  piVar5 = DAT_021c0f8c;
  *(undefined4 *)(*DAT_021c0f8c + DAT_021c0fc8) = uVar8;
  FUN_021d18f0(*(undefined4 *)(*piVar5 + iVar7),0xffffffff,DAT_021c0fa4);
  FUN_021d1790(*(undefined4 *)(*DAT_021c0f8c + DAT_021c0fc8),0xffffffff,2);
  uVar8 = FUN_021d3544(0,DAT_021c0fcc,0,0x78);
  piVar5 = DAT_021c0f8c;
  *(undefined4 *)(*DAT_021c0f8c + DAT_021c0fd0) = uVar8;
  FUN_021c0154(*(undefined1 *)(*piVar5 + DAT_021c0fd4),0,0xc0);
  return;
}

