/* Decompiled C draft; module arm9_ov003; ROM address 021bcf1c. No matching claim. */
#include "types.h"
#include "deps/021bcf1c_FUN_021bcf1c.h"

int FUN_021bcf1c(void)

{
  undefined1 uVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_74;
  int local_70;
  int local_48;
  int local_38;
  undefined2 local_34;
  undefined2 uStack_32;
  undefined4 local_30;
  undefined1 local_2c [8];
  int local_24;
  undefined1 auStack_20 [4];
  undefined4 local_1c [2];
  
  puVar3 = DAT_021bd2a4;
  iVar10 = 0;
  local_74 = -5;
  local_38 = 0;
  local_70 = 0;
  bVar2 = false;
  *DAT_021bd2a4 = 1;
  do {
    if ((bVar2) || (*DAT_021bd334 != 0)) {
      if (iVar10 != 0) {
        func_0x021a9008(iVar10);
      }
      if (*DAT_021bd334 != 0) {
        local_74 = -8;
      }
      return local_74;
    }
    func_0x0200dc3c(DAT_021bd2a8);
    switch(*puVar3) {
    case 1:
      local_74 = FUN_021bdd3c();
      if (local_74 == 1) {
        *DAT_021bd2ac = 3;
        FUN_021bb03c();
        *puVar3 = 2;
      }
      else {
        bVar2 = true;
      }
      break;
    case 2:
      local_74 = FUN_021be264();
      if (local_74 == 1) {
        *puVar3 = 3;
      }
      else {
        bVar2 = true;
      }
      break;
    case 3:
      iVar10 = func_0x021a918c(2,2,0);
      if (iVar10 < 0) {
        local_74 = -2;
        bVar2 = true;
      }
      else {
        _local_34 = CONCAT22((short)DAT_021bd2b0,0x208);
        local_30 = 0;
        local_74 = func_0x021a916c(iVar10,&local_34);
        if (local_74 < 0) {
          local_74 = -2;
          bVar2 = true;
        }
        else {
          *puVar3 = 4;
        }
      }
      break;
    case 4:
      uVar8 = FUN_021bb354();
      if (uVar8 < *DAT_021bd2b4) {
        local_2c[0] = 8;
        FUN_021bd768(DAT_021bd2b8,local_2c);
        iVar6 = func_0x021a90a0(iVar10,DAT_021bd2bc,DAT_021bd2c0,4,local_2c);
        if ((0 < iVar6) && (iVar6 = FUN_021bd998(DAT_021bd2bc,(undefined4 *)(uintptr_t)(DAT_021bd2c4)), iVar6 != 0)) {
          iVar6 = FUN_021bb354();
          *DAT_021bd2b4 = iVar6 + DAT_021bd2c8;
          *puVar3 = 5;
          *DAT_021bd2ac = 4;
          FUN_021bb03c();
        }
      }
      else {
        func_0x021a9008(iVar10);
        local_74 = -3;
        bVar2 = true;
      }
      break;
    case 5:
      uVar7 = FUN_021bd894(DAT_021bd2bc);
      *DAT_021bd2cc = uVar7;
      FUN_021bdccc(iVar10,local_2c,DAT_021bd2bc);
      local_38 = FUN_021bb354();
      *puVar3 = 6;
      break;
    case 6:
      uVar8 = FUN_021bb354();
      if (uVar8 < *DAT_021bd2b4) {
        iVar6 = func_0x021a90a0(iVar10,DAT_021bd2bc,DAT_021bd2c0,4,local_2c);
        if ((iVar6 < 1) ||
           (iVar6 = FUN_021bd938(DAT_021bd2bc,3,DAT_021bd2d0,DAT_021bd2b8), iVar6 == 0)) {
          uVar8 = FUN_021bb354();
          if ((uint)(local_38 + DAT_021bd2e0) <= uVar8) {
            *puVar3 = 5;
          }
        }
        else {
          puVar5 = (undefined1 *)FUN_021bdbd0((ushort *)(uintptr_t)(DAT_021bd2d0),(undefined4)(uintptr_t)(&local_24),(undefined4)(uintptr_t)(auStack_20));
          if (local_24 == DAT_021bd2d4) {
            local_1c[0] = FUN_021bb354();
            iVar6 = 8;
            puVar9 = DAT_021bd2d8;
            do {
              uVar1 = *puVar5;
              puVar5 = puVar5 + 1;
              *puVar9 = uVar1;
              puVar9 = puVar9 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            FUN_021bb378(DAT_021bd2dc,local_1c,4);
            local_70 = 0;
            *puVar3 = 7;
            *DAT_021bd2ac = 5;
            *DAT_021bd2b4 = 0xffffffff;
            FUN_021bb03c();
          }
        }
      }
      else {
        func_0x021a9008(iVar10);
        local_74 = -4;
        bVar2 = true;
      }
      break;
    case 7:
      iVar6 = FUN_021bda78(DAT_021bd2d0,DAT_021bd2e4,DAT_021bd2dc,8);
      *DAT_021bd2e8 = iVar6;
      uVar7 = FUN_021bdb0c(DAT_021bd2bc,4,DAT_021bd2d0,*DAT_021bd2e8,DAT_021bd2b8);
      *DAT_021bd2cc = uVar7;
      FUN_021bdccc(iVar10,local_2c,DAT_021bd2bc);
      local_38 = FUN_021bb354();
      local_48 = 0x12;
      puVar4 = DAT_021bd2ec;
      do {
        puVar11 = puVar4;
        *puVar11 = 0;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11[3] = 0;
        puVar11[4] = 0;
        puVar11[5] = 0;
        puVar11[6] = 0;
        puVar11[7] = 0;
        local_48 = local_48 + -1;
        puVar4 = puVar11 + 8;
      } while (local_48 != 0);
      puVar11[8] = 0;
      puVar11[9] = 0;
      puVar11[10] = 0;
      puVar11[0xb] = 0;
      puVar11[0xc] = 0;
      *puVar3 = 8;
      break;
    case 8:
      iVar6 = func_0x021a90a0(iVar10,DAT_021bd2bc,DAT_021bd2c0,4,local_2c);
      if (0 < iVar6) {
        iVar6 = FUN_021bd938(DAT_021bd2bc,5,DAT_021bd2d0,DAT_021bd2d8);
        *DAT_021bd2e8 = iVar6;
        if ((iVar6 != 0) && (iVar6 = FUN_021bd59c(DAT_021bd2d0), iVar6 != 0)) {
          if (*DAT_021bd2f0 == '\0') {
            *DAT_021bd2f4 = 0;
          }
          else {
            *DAT_021bd2f4 = 1;
          }
          local_70 = 0;
          *puVar3 = 9;
          break;
        }
      }
      uVar8 = FUN_021bb354();
      if ((uint)(local_38 + DAT_021bd2e0) <= uVar8) {
        local_70 = local_70 + 1;
        if (local_70 < 10) {
          *puVar3 = 7;
        }
        else {
          func_0x021a9008(iVar10);
          local_74 = -2;
          bVar2 = true;
        }
      }
      break;
    case 9:
      iVar6 = FUN_021bda78(DAT_021bd2d0,DAT_021bd2f8,DAT_021bd2f4,1);
      *DAT_021bd2e8 = iVar6;
      uVar7 = FUN_021bdb0c(DAT_021bd2bc,6,DAT_021bd2d0,*DAT_021bd2e8,DAT_021bd2d8);
      *DAT_021bd2cc = uVar7;
      iVar6 = FUN_021be604();
      if (iVar6 == 7) {
        FUN_021bdccc(iVar10,local_2c,DAT_021bd2bc,*DAT_021bd2cc);
        local_38 = FUN_021bb354();
        *puVar3 = 10;
      }
      else {
        local_38 = FUN_021bb354();
        local_38 = local_38 + DAT_021bd2e0;
        local_70 = 10;
        *puVar3 = 10;
      }
      break;
    case 10:
      uVar8 = FUN_021bb354();
      if ((uint)(local_38 + DAT_021bd2e0) <= uVar8) {
        local_70 = local_70 + 1;
        if (local_70 < 10) {
          *puVar3 = 9;
        }
        else {
          bVar2 = true;
          local_74 = FUN_021bd338();
        }
      }
    }
  } while( true );
}

