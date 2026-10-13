/* Decompiled C draft; module arm9_ov001; ROM address 0219a9a0. No matching claim. */
#include "types.h"
#include "deps/0219a9a0_FUN_0219a9a0.h"

void FUN_0219a9a0(undefined4 param_1)

{
  short sVar1;
  ushort *puVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  short *psVar11;
  undefined2 *puVar12;
  uint *puVar13;
  undefined2 *puVar14;
  int local_84;
  uint *local_80;
  undefined2 *local_7c;
  undefined2 *local_78;
  undefined2 *local_74;
  short *local_70;
  int local_68;
  int local_64;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 auStack_34 [32];
  
  puVar2 = DAT_0219ac58;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  *DAT_0219ac58 = *DAT_0219ac58 & 0xfffc | 1;
  *puVar2 = *puVar2 & 0x43 | (ushort)DAT_0219ac5c;
  *DAT_0219ac60 = *DAT_0219ac60 & 0x43 | (ushort)DAT_0219ac64;
  iVar5 = func_0x02036bec(param_1,0x48);
  piVar9 = DAT_0219ac68;
  *DAT_0219ac68 = iVar5;
  *(undefined4 *)(iVar5 + 0x2c) = param_1;
  *(undefined4 *)(*piVar9 + 0x30) = 0;
  uVar6 = func_0x0211147c();
  switch(uVar6) {
  case 1:
  case 5:
    *(undefined4 *)(*DAT_0219ac68 + 0x40) = 0;
    break;
  case 2:
    *(undefined4 *)(*DAT_0219ac68 + 0x40) = 1;
    break;
  case 3:
    iVar5 = func_0x021143b4();
    if (iVar5 == 0) {
      *(undefined4 *)(*DAT_0219ac68 + 0x40) = 0;
    }
    else {
      *(undefined4 *)(*DAT_0219ac68 + 0x40) = 2;
    }
  }
  FUN_0219b000();
  piVar9 = DAT_0219ac68;
  iVar5 = 0;
  puVar12 = DAT_0219ac6c;
  do {
    func_0x02124a98(*puVar12,1,*(undefined4 *)(*piVar9 + 0xc),*(undefined4 *)(*piVar9 + 0x10));
    puVar12 = puVar12 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  uVar6 = func_0x02111318();
  uVar7 = func_0x0211130c();
  func_0x020ae6d4(uVar6,uVar7);
  iVar5 = *DAT_0219ac68;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8),iVar5 + 0x18);
  func_0x02124ed0(param_1,*(undefined4 *)(*DAT_0219ac68 + 0x10),0,*DAT_0219ac68 + 0x1c);
  uVar6 = func_0x02047a28(DAT_0219ac70);
  *(undefined4 *)(*DAT_0219ac68 + 0x20) = uVar6;
  uVar6 = func_0x0204799c(DAT_0219ac74);
  piVar9 = DAT_0219ac68;
  *(undefined4 *)(*DAT_0219ac68 + 0x24) = uVar6;
  iVar5 = DAT_0219ac78;
  puVar10 = (undefined4 *)*piVar9;
  iVar8 = func_0x021243ac(param_1,0,puVar10[2],0xaa,0xe,0,*puVar10,puVar10[1],puVar10[6],
                          DAT_0219ac78);
  iVar5 = iVar5 - iVar8;
  iVar8 = *DAT_0219ac68;
  uVar6 = func_0x020b3f7c(*(undefined4 *)(iVar8 + 0x24),9);
  func_0x0212426c(0,0,*(undefined4 *)(*DAT_0219ac68 + 8),uVar6,*(undefined4 *)(iVar8 + 4),
                  *(undefined4 *)(iVar8 + 0x18));
  sVar4 = 1;
  sVar1 = *(short *)(*(int *)(*DAT_0219ac68 + 4) + 6);
  local_64 = 0;
  local_78 = DAT_0219ac7c;
  local_74 = DAT_0219ac80;
  local_70 = DAT_0219ac84;
  do {
    local_84 = 0;
    psVar11 = local_70;
    puVar12 = local_78;
    puVar14 = local_74;
    do {
      puVar10 = (undefined4 *)*DAT_0219ac68;
      iVar8 = func_0x021243ac(param_1,*psVar11,puVar10[2],*puVar14,*puVar12,sVar4,*puVar10,
                              puVar10[1],puVar10[6],iVar5);
      iVar5 = iVar5 - iVar8;
      sVar4 = sVar1 + *psVar11;
      puVar12 = puVar12 + 1;
      puVar14 = puVar14 + 1;
      psVar11 = psVar11 + 1;
      local_84 = local_84 + 1;
    } while (local_84 < 3);
    local_78 = local_78 + 3;
    local_74 = local_74 + 3;
    local_70 = local_70 + 3;
    local_64 = local_64 + 1;
  } while (local_64 < 3);
  iVar5 = 0;
  psVar11 = DAT_0219ac84;
  puVar12 = DAT_0219ac88;
  do {
    iVar8 = *DAT_0219ac68;
    uVar6 = func_0x020b3f7c(*(undefined4 *)(iVar8 + 0x24),*puVar12);
    func_0x0212426c(0,*psVar11,*(undefined4 *)(*DAT_0219ac68 + 8),uVar6,*(undefined4 *)(iVar8 + 4),
                    *(undefined4 *)(iVar8 + 0x18));
    uVar3 = DAT_0219ac94;
    puVar12 = puVar12 + 1;
    psVar11 = psVar11 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  piVar9 = (int *)*DAT_0219ac8c;
  local_4c = *(uint *)(*piVar9 + 0x34);
  local_40 = *(undefined4 *)(*piVar9 + 0x38);
  local_48 = *(undefined4 *)(*piVar9 + 0x3c);
  local_3c = *(undefined4 *)(*piVar9 + 0x40);
  local_44 = *(undefined4 *)(*piVar9 + 0x44);
  local_38 = *(undefined4 *)(*piVar9 + 0x48);
  local_68 = 1;
  local_80 = &local_4c;
  local_7c = DAT_0219ac90;
  do {
    iVar5 = 0;
    puVar12 = local_7c;
    puVar13 = local_80;
    do {
      if (uVar3 < *puVar13) {
        *puVar13 = uVar3;
      }
      func_0x02124fac(*puVar13,auStack_34);
      iVar8 = *DAT_0219ac68;
      func_0x02124248(0,*puVar12,*(undefined4 *)(iVar8 + 8),auStack_34,*(undefined4 *)(iVar8 + 4),
                      *(undefined4 *)(iVar8 + 0x18),6);
      puVar13 = puVar13 + 1;
      puVar12 = puVar12 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    local_80 = local_80 + 3;
    local_7c = local_7c + 3;
    local_68 = local_68 + 1;
  } while (local_68 < 3);
  FUN_0219ac98();
  FUN_0219ae88();
  FUN_0219afc8(*(undefined4 *)(*DAT_0219ac68 + 0x40));
  return;
}

