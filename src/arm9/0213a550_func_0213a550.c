/* Decompiled C draft; module arm9; ROM address 0213a550. No matching claim. */
#include "types.h"
#include "deps/0213a550_func_0213a550.h"

/* WARNING: Removing unreachable block (ram,0x0213b220) */
/* WARNING: Removing unreachable block (ram,0x0213a6b0) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8
func_0213a550(int param_1,code *param_2,undefined4 param_3,int *param_4,undefined4 *param_5)

{
  undefined2 uVar1;
  bool bVar2;
  undefined2 *puVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  undefined2 *puVar15;
  uint *puVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  bool bVar22;
  undefined8 uVar23;
  int local_100;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  uint *local_e8;
  uint local_e4;
  uint local_e0;
  int local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  undefined4 local_8c;
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined1 uStack_86;
  undefined4 local_85;
  undefined1 local_81;
  byte bStack_80;
  undefined1 uStack_7f;
  undefined1 uStack_7e;
  undefined1 uStack_7d;
  undefined1 local_7c [2];
  undefined1 uStack_7a;
  undefined1 uStack_79;
  undefined1 local_78;
  undefined1 uStack_77;
  undefined1 uStack_76;
  undefined1 auStack_75 [4];
  undefined1 uStack_71;
  undefined1 local_70 [2];
  undefined2 auStack_6e [16];
  uint local_4e [2];
  undefined1 local_45 [2];
  undefined1 auStack_43 [31];
  
  local_100 = 0;
  iVar5 = 4;
  puVar3 = (undefined2 *)(auStack_75 + 1);
  do {
    puVar15 = puVar3;
    *puVar15 = 0;
    puVar15[1] = 0;
    puVar15[2] = 0;
    puVar15[3] = 0;
    iVar5 = iVar5 + -1;
    puVar3 = puVar15 + 4;
  } while (iVar5 != 0);
  bVar2 = false;
  puVar15[4] = 0;
  puVar15[5] = 0;
  local_f8 = 0;
  puVar15[6] = 0;
  *param_5 = 0;
  iVar5 = 1;
  uVar6 = (*param_2)(param_3);
  local_d0 = 1;
  local_a0 = 0x800;
  local_9c = 0x100;
  local_a4 = 0x80;
  local_c0 = 0x1000;
  local_a8 = 0x40;
  local_ac = 0x20;
  local_bc = 0x10;
  local_b0 = 8;
  local_b4 = 4;
  local_c4 = 2;
  local_94 = 0x400;
  local_98 = 0x200;
  local_b8 = 0x8000;
  local_c8 = 0x2000;
  local_cc = 0x4000;
  uVar14 = 1;
  uVar10 = 0;
  local_f4 = local_f8;
  local_f0 = local_f8;
  local_ec = local_f8;
  local_e0 = local_f8;
  local_d8 = local_f8;
  local_d4 = local_f8;
LAB_0213b83c:
  do {
    uVar19 = uVar10;
    uVar18 = uVar14;
    if (((param_1 < iVar5) || (uVar6 == 0xffffffff)) || ((uVar18 & 0x1800) != 0)) {
      if (uVar18 == 0x8000) {
        if ((iVar5 + -1 < 3) || ((uVar19 & DAT_0213bf80) == 0)) {
          bVar22 = true;
        }
        else {
          bVar22 = false;
        }
      }
      else {
        bVar22 = (uVar18 & DAT_0213bf7c) == 0;
      }
      if (bVar22) {
        *param_4 = 0;
      }
      else {
        *param_4 = iVar5 + -1 + local_100;
      }
      (*param_2)(param_3,uVar6,1);
      if (uVar19 != 0) {
        bVar22 = local_d8 != 0;
        if (bVar22) {
          local_d8 = local_e0;
        }
        uVar14 = 0;
        if (bVar22) {
          local_e0 = -local_d8;
        }
        local_e0 = local_e0 + local_d4 * 4;
        for (; (uVar14 < 4 &&
               ((CONCAT12(MKDS_SLICE_1(local_8c,2),CONCAT11(MKDS_SLICE_1(local_8c,1),(undefined1)local_8c)) & 0xff &
                0x80 >> (uVar14 & 0xff)) == 0)); uVar14 = uVar14 + 1) {
          local_e0 = local_e0 + -1;
        }
        uVar14 = uVar14 + 1;
        if (uVar14 != 0) {
          uVar10 = 0;
          if (&local_8c <= &local_85) {
            local_e8 = &local_85;
            do {
              uVar19 = (*(uint *)((uint)local_e8 & 0xfffffffc) >> ((uint)local_e8 & 3) * 8 |
                       *(uint *)((uint)local_e8 & 0xfffffffc) << ((uint)local_e8 & 3) * -8 + 0x20) &
                       0xff;
              uVar18 = uVar10 | uVar19 << (uVar14 & 0xff) & 0xff |
                       (*(uint *)((uint)local_e8 & 0xfffffffc) >> ((uint)local_e8 & 3) * 8 |
                       *(uint *)((uint)local_e8 & 0xfffffffc) << ((uint)local_e8 & 3) * -8 + 0x20) &
                       0xffffff00;
              uVar6 = (4 - ((uint)local_e8 & 3)) * 8 & 0x1f;
              uVar10 = (int)uVar19 >> (8 - uVar14 & 0xff) & 0xff;
              puVar16 = (uint *)((int)local_e8 + -1);
              *local_e8 = uVar18 >> uVar6 | uVar18 << 0x20 - uVar6;
              local_e8 = puVar16;
            } while (&local_8c <= puVar16);
          }
        }
        uVar10 = (uint)CONCAT12(uStack_79,CONCAT11(uStack_7a,local_7c[1])) << 8;
        uVar18 = 0;
        uVar14 = (uint)(local_7c + 1) & 3;
        uVar10 = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)(local_7c + 1) & 3)) * 8 & 0x1f;
        uVar14 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
        local_7c[1] = (undefined1)uVar14;
        uVar10 = (uint)(local_7c + 2) & 3;
        uVar14 = uVar14 << 8;
        uVar10 = (uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)(local_7c + 2) & 3)) * 8 & 0x1f;
        uVar14 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
        uStack_7a = (undefined1)uVar14;
        uStack_79 = (undefined1)(uVar14 >> 8);
        uVar14 = (uint)(local_7c + 3) & 3;
        uVar10 = (uint)CONCAT12(uStack_79,CONCAT11(uStack_7a,local_7c[1])) << 8;
        uVar10 = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)(local_7c + 3) & 3)) * 8 & 0x1f;
        uVar14 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
        uStack_79 = (undefined1)uVar14;
        uVar10 = CONCAT13(auStack_75[0],(int3)(uVar14 >> 8)) & 0xffffff00;
        uVar14 = (uint)&uStack_77 & 3;
        uVar10 = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)&uStack_77 & 3)) * 8 & 0x1f;
        uVar14 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
        uStack_77 = (undefined1)uVar14;
        uVar10 = (uint)&uStack_76 & 3;
        uVar14 = uVar14 << 8;
        uVar10 = (uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)&uStack_76 & 3)) * 8 & 0x1f;
        uVar14 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
        uStack_76 = (undefined1)uVar14;
        auStack_75[0] = (byte)(uVar14 >> 8);
        uVar14 = (uint)auStack_75 & 3;
        uVar10 = (uint)CONCAT12(auStack_75[0],CONCAT11(uStack_76,uStack_77)) << 8;
        uVar6 = 0xc;
        uVar10 = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)auStack_75 & 3)) * 8 & 0x1f;
        auStack_75[0] = (byte)(uVar10 >> uVar14) | (byte)(uVar10 << 0x20 - uVar14);
        iVar17 = 0;
        iVar5 = 1;
        do {
          uVar14 = (int)&local_8c + iVar17 & 3;
          uVar10 = *(uint *)((int)&local_8c + iVar17 & 0xfffffffc);
          uVar14 = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) & 0xff;
          if (0x34 < uVar18 + 8) {
            uVar14 = uVar14 & 0xff << (0x34 - uVar18 & 0xff);
          }
          uVar19 = uVar6 & 7;
          uVar10 = (uint)(local_7c + iVar5) & 3;
          uVar20 = *(uint *)((uint)(local_7c + iVar5) & 0xfffffffc);
          puVar16 = (uint *)(local_7c + iVar5);
          uVar20 = (uVar20 >> uVar10 * 8 | uVar20 << uVar10 * -8 + 0x20) & 0xff |
                   (int)uVar14 >> uVar19 & 0xffU |
                   (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                   *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar10 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar20 >> uVar10 | uVar20 << 0x20 - uVar10;
          uVar6 = uVar6 + 8;
          uVar10 = (uint)(local_7c + iVar5 + 1) & 3;
          uVar20 = *(uint *)((uint)(local_7c + iVar5 + 1) & 0xfffffffc);
          uVar18 = uVar18 + 8;
          puVar16 = (uint *)(local_7c + iVar5 + 1);
          iVar17 = iVar17 + 1;
          uVar10 = (uVar20 >> uVar10 * 8 | uVar20 << uVar10 * -8 + 0x20) & 0xff |
                   uVar14 << (8 - uVar19 & 0xff) & 0xff |
                   (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                   *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
          iVar5 = iVar5 + 1;
        } while (uVar18 < 0x34);
        if ((local_e0 + DAT_0213bf8c & 0xfffff800) != 0) {
          *param_5 = 1;
          return 0;
        }
        uVar14 = (local_e0 + DAT_0213bf8c) * 0x200000;
        uVar6 = uVar14 >> 0x19 | (uint)CONCAT12(uStack_79,CONCAT11(uStack_7a,local_7c[1])) << 8;
        local_7c[0] = (byte)(uVar14 >> 0x19);
        uVar10 = (uint)(local_7c + 1) & 3;
        uVar10 = (uVar6 >> ((uint)(local_7c + 1) & 3) * 8 |
                 uVar6 << ((uint)(local_7c + 1) & 3) * -8 + 0x20) & 0xff | uVar14 >> 0x11 & 0xff |
                 (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)(local_7c + 1) & 3)) * 8 & 0x1f;
        uVar14 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
        local_7c[1] = (undefined1)uVar14;
        uStack_7a = (undefined1)(uVar14 >> 8);
        uStack_79 = (undefined1)(uVar14 >> 0x10);
        local_78 = (undefined1)(uVar14 >> 0x18);
        if (bVar2) {
          uVar1 = CONCAT11(local_7c[1],local_7c[0]);
          local_7c[0] = local_7c[0] | 0x80;
          uVar14 = CONCAT13(uStack_79,CONCAT12(uStack_7a,uVar1)) & 0xffffff00;
          local_7c[1] = (undefined1)(uVar14 >> 8);
          uStack_7a = (undefined1)(uVar14 >> 0x10);
          uStack_79 = (undefined1)(uVar14 >> 0x18);
        }
        iVar5 = 0;
        do {
          uVar10 = (uint)(local_7c + iVar5) & 3;
          uVar18 = *(uint *)((uint)(local_7c + iVar5) & 0xfffffffc);
          uVar14 = (uint)(auStack_75 + -iVar5) & 3;
          uVar6 = *(uint *)((uint)(auStack_75 + -iVar5) & 0xfffffffc);
          puVar16 = (uint *)(local_7c + iVar5);
          uVar6 = (uVar6 >> uVar14 * 8 | uVar6 << uVar14 * -8 + 0x20) & 0xff |
                  (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                  *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar6 >> uVar14 | uVar6 << 0x20 - uVar14;
          puVar16 = (uint *)(auStack_75 + -iVar5);
          uVar10 = (uVar18 >> uVar10 * 8 | uVar18 << uVar10 * -8 + 0x20) & 0xff |
                   (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                   *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 4);
        return CONCAT44(CONCAT13(auStack_75[0],CONCAT12(uStack_76,CONCAT11(uStack_77,local_78))),
                        CONCAT13(uStack_79,CONCAT12(uStack_7a,CONCAT11(local_7c[1],local_7c[0]))));
      }
      if (local_f8 != 0) {
        local_f4 = -local_f4;
      }
      puVar9 = local_70 + (_local_70 & 0xff) + 1;
      uVar14 = _local_70 & 0xff;
      while ((uVar14 != 0 &&
             (puVar9 = puVar9 + -1,
             ((*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
              *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xff) ==
             0x30))) {
        local_f0 = local_f0 + 1;
        uVar14 = uVar14 - 1;
      }
      uVar10 = _local_70 & 0xffffff00;
      _local_70 = uVar14 & 0xff | uVar10;
      if ((uVar14 & 0xff) == 0) {
        _local_70 = uVar10 | 1;
      }
      iVar5 = local_f4 + local_f0;
      if ((iVar5 < -0x8000) || (DAT_0213b750 < iVar5)) {
        *param_5 = 1;
      }
      if (*(uint *)((uint)param_5 & 0xfffffffc) >> ((uint)param_5 & 3) * 8 == 0 &&
          *(uint *)((uint)param_5 & 0xfffffffc) << ((uint)param_5 & 3) * -8 + 0x20 == 0) {
        auStack_75[3] = (undefined1)iVar5;
        uStack_71 = (undefined1)((uint)iVar5 >> 8);
        uVar23 = func_0214049c((undefined2 *)(void *)(auStack_75 + 1));
        uVar11 = (undefined4)((ulonglong)uVar23 >> 0x20);
        uVar8 = (undefined4)uVar23;
        iVar5 = FUN_02131b74(0,0,uVar8,uVar11);
        if ((iVar5 == 0) || (iVar5 = FUN_02131ce8(uVar8,uVar11,0,0x100000), iVar5 == 0)) {
          iVar5 = FUN_02131e60(uVar8,uVar11,0xffffffff,DAT_0213bf88);
          uVar14 = DAT_0213bf84;
          if (iVar5 != 0) {
            *param_5 = 1;
            uVar10 = uVar14 + 4 & 3;
            uVar6 = *(uint *)(uVar14 + 4 & 0xfffffffc);
            uVar23 = CONCAT44(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,
                              *(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                              *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20);
          }
        }
        else {
          *param_5 = 1;
        }
        if ((bVar2) && ((uVar18 & DAT_0213bf7c) != 0)) {
          uVar23 = func_02130ccc(0,0,(int)uVar23,(int)((ulonglong)uVar23 >> 0x20));
        }
        return uVar23;
      }
      if (local_f8 != 0) {
        return 0;
      }
      if (!bVar2) {
        uVar14 = DAT_0213bf84 + 4 & 3;
        uVar10 = *(uint *)(DAT_0213bf84 + 4 & 0xfffffffc);
        return CONCAT44(uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20,
                        *(uint *)(DAT_0213bf84 & 0xfffffffc) >> (DAT_0213bf84 & 3) * 8 |
                        *(uint *)(DAT_0213bf84 & 0xfffffffc) << (DAT_0213bf84 & 3) * -8 + 0x20);
      }
      uVar14 = DAT_0213bf84 + 4 & 3;
      uVar10 = *(uint *)(DAT_0213bf84 + 4 & 0xfffffffc);
      uVar23 = func_02130ccc(0,0,*(uint *)(DAT_0213bf84 & 0xfffffffc) >> (DAT_0213bf84 & 3) * 8 |
                                 *(uint *)(DAT_0213bf84 & 0xfffffffc) <<
                                 (DAT_0213bf84 & 3) * -8 + 0x20,
                             uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20);
      return uVar23;
    }
    uVar14 = uVar18;
    uVar10 = uVar19;
    if (uVar18 < 0x101) {
      if (0xff < uVar18) {
        if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
        }
        uVar14 = local_c0;
        if ((uVar4 != 0) && (uVar14 = local_94, uVar6 == 0x30)) {
          iVar5 = iVar5 + 1;
          uVar6 = (*param_2)(param_3,0);
          uVar14 = local_98;
        }
        goto LAB_0213b83c;
      }
      if (uVar18 < 0x21) {
        if (uVar18 < 0x20) {
          switch(uVar18) {
          case 0:
            break;
          case 1:
            if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 0x100;
            }
            if (uVar4 != 0) {
              uVar6 = (*param_2)(param_3,0);
              local_100 = local_100 + 1;
              break;
            }
            uVar19 = uVar6;
            if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
              uVar14 = DAT_0213b740 + uVar6 & 3;
              uVar19 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
              uVar19 = (uVar19 >> uVar14 * 8 | uVar19 << uVar14 * -8 + 0x20) & 0xff;
            }
            if ((int)uVar19 < 0x4a) {
              if ((int)uVar19 < 0x49) {
                uVar14 = local_c4;
                if (((int)uVar19 < 0x2e) && (uVar14 = local_c4, 0x2a < (int)uVar19)) {
                  if (uVar19 != 0x2b) {
                    uVar14 = local_c4;
                    if (uVar19 != 0x2d) break;
                    bVar2 = true;
                  }
                  iVar5 = iVar5 + 1;
                  uVar6 = (*param_2)(param_3,0);
                  local_ec = 1;
                  uVar14 = uVar18;
                  break;
                }
              }
              else {
                iVar5 = iVar5 + 1;
                uVar6 = (*param_2)(param_3,0);
                uVar14 = local_cc;
              }
            }
            else {
              uVar14 = local_c4;
              if (uVar19 == 0x4e) {
                iVar5 = iVar5 + 1;
                uVar6 = (*param_2)(param_3,0);
                uVar14 = local_c8;
              }
            }
            break;
          case 2:
            if (uVar6 == 0x2e) {
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
              uVar14 = local_bc;
            }
            else {
              if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
              }
              uVar14 = local_c0;
              if ((uVar4 != 0) && (uVar14 = local_b0, uVar6 == 0x30)) {
                iVar5 = iVar5 + 1;
                uVar6 = (*param_2)(param_3,0);
                uVar18 = uVar6;
                if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
                  uVar14 = DAT_0213b740 + uVar6 & 3;
                  uVar10 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
                  uVar18 = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) & 0xff;
                }
                uVar14 = local_b8;
                uVar10 = local_d0;
                if (uVar18 != 0x58) {
                  uVar14 = local_b4;
                  uVar10 = uVar19;
                }
              }
            }
            break;
          case 3:
            break;
          case 4:
            uVar14 = local_b0;
            if (uVar6 == 0x30) {
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
              uVar14 = uVar18;
            }
            break;
          case 5:
            break;
          case 6:
            break;
          case 7:
            break;
          case 8:
            if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
            }
            if (uVar4 == 0) {
              uVar14 = local_a8;
              if (uVar6 == 0x2e) {
                iVar5 = iVar5 + 1;
                uVar6 = (*param_2)(param_3,0);
                uVar14 = local_ac;
              }
            }
            else {
              uVar18 = _local_70 & 0xff;
              if (uVar18 < 0x14) {
                _local_70 = uVar18 + 1 & 0xff | _local_70 & 0xffffff00;
                puVar16 = (uint *)(local_70 + uVar18 + 1);
                uVar18 = uVar6 & 0xff |
                         (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                         *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                         0xffffff00;
                uVar6 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
                *puVar16 = uVar18 >> uVar6 | uVar18 << 0x20 - uVar6;
              }
              else {
                local_f0 = local_f0 + 1;
              }
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
            }
            break;
          default:
            if (uVar18 == 0x10) {
              if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
              }
              uVar14 = local_c0;
              if (uVar4 != 0) {
                uVar14 = local_ac;
              }
            }
          }
        }
        else {
          if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
            uVar4 = 0;
          }
          else {
            uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
          }
          uVar14 = local_a8;
          if (uVar4 != 0) {
            uVar14 = _local_70 & 0xff;
            if (uVar14 < 0x14) {
              if ((uVar6 != 0x30) || (uVar14 != 0)) {
                puVar16 = (uint *)(local_70 + uVar14 + 1);
                _local_70 = (_local_70 & 0xff) + 1 & 0xff | _local_70 & 0xffffff00;
                uVar6 = uVar6 & 0xff |
                        (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                        *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                        0xffffff00;
                uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
                *puVar16 = uVar6 >> uVar14 | uVar6 << 0x20 - uVar14;
              }
              local_f0 = local_f0 - 1;
            }
            iVar5 = iVar5 + 1;
            uVar6 = (*param_2)(param_3,0);
            uVar14 = uVar18;
          }
        }
      }
      else if (uVar18 < 0x41) {
        if (uVar18 == 0x40) {
          uVar18 = uVar6;
          if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
            uVar14 = DAT_0213b740 + uVar6 & 3;
            uVar18 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
            uVar18 = (uVar18 >> uVar14 * 8 | uVar18 << uVar14 * -8 + 0x20) & 0xff;
          }
          uVar14 = local_a0;
          if (uVar18 == 0x45) {
            iVar5 = iVar5 + 1;
            uVar6 = (*param_2)(param_3,0);
            uVar14 = local_a4;
          }
        }
      }
      else if (uVar18 == 0x80) {
        if (uVar6 == 0x2b) {
          iVar5 = iVar5 + 1;
          uVar6 = (*param_2)(param_3,0);
          uVar14 = local_9c;
        }
        else {
          uVar14 = local_9c;
          if (uVar6 == 0x2d) {
            iVar5 = iVar5 + 1;
            uVar6 = (*param_2)(param_3,0);
            local_f8 = 1;
            uVar14 = local_9c;
          }
        }
      }
      goto LAB_0213b83c;
    }
    if (uVar18 < 0x2001) {
      if (uVar18 < 0x2000) {
        if (uVar18 < 0x201) {
          if ((uVar18 == 0x200) && (uVar14 = local_94, uVar6 == 0x30)) {
            iVar5 = iVar5 + 1;
            uVar6 = (*param_2)(param_3,0);
            uVar14 = uVar18;
          }
        }
        else if (uVar18 == 0x400) {
          if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
            uVar4 = 0;
          }
          else {
            uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
          }
          uVar14 = local_a0;
          if (uVar4 != 0) {
            local_f4 = local_f4 * 10 + (uVar6 - 0x30);
            if (DAT_0213b750 < (int)local_f4) {
              *param_5 = 1;
            }
            iVar5 = iVar5 + 1;
            uVar6 = (*param_2)(param_3,0);
            uVar14 = uVar18;
          }
        }
      }
      else {
        iVar17 = 0;
        uVar18 = *(uint *)(DAT_0213b74c & 0xfffffffc) >> (DAT_0213b74c & 3) * 8 |
                 *(uint *)(DAT_0213b74c & 0xfffffffc) << (DAT_0213b74c & 3) * -8 + 0x20;
        uVar14 = DAT_0213b74c + 1 & 3;
        uVar19 = *(uint *)(DAT_0213b74c + 1 & 0xfffffffc);
        uVar20 = uVar18 & 0xff |
                 CONCAT13(local_81,CONCAT12(MKDS_SLICE_1(local_85,3),CONCAT11(MKDS_SLICE_1(local_85,2),MKDS_SLICE_1(local_85,1))))
                 & 0xffffff00;
        MKDS_SLICE_1(local_85,1) = (undefined1)uVar18;
        uVar18 = (uint)((int)&local_85 + 2U) & 3;
        uVar18 = (uVar19 >> uVar14 * 8 | uVar19 << uVar14 * -8 + 0x20) & 0xff |
                 (uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)((int)&local_85 + 2U) & 3)) * 8 & 0x1f;
        uVar14 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
        MKDS_SLICE_1(local_85,2) = (undefined1)uVar14;
        MKDS_SLICE_1(local_85,3) = (undefined1)(uVar14 >> 8);
        local_81 = (undefined1)(uVar14 >> 0x10);
        uVar14 = DAT_0213b74c + 2 & 3;
        uVar12 = *(uint *)(DAT_0213b74c + 2 & 0xfffffffc);
        uVar18 = DAT_0213b74c + 3 & 3;
        uVar7 = *(uint *)(DAT_0213b74c + 3 & 0xfffffffc);
        uVar19 = (uint)((int)&local_85 + 3U) & 3;
        uVar20 = CONCAT13(local_81,CONCAT12(MKDS_SLICE_1(local_85,3),CONCAT11(MKDS_SLICE_1(local_85,2),MKDS_SLICE_1(local_85,1))))
        ;
        uVar19 = (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) & 0xff |
                 (uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20) & 0xffffff00;
        uVar14 = (4 - ((uint)((int)&local_85 + 3U) & 3)) * 8 & 0x1f;
        uVar14 = uVar19 >> uVar14 | uVar19 << 0x20 - uVar14;
        MKDS_SLICE_1(local_85,3) = (undefined1)uVar14;
        local_81 = (undefined1)(uVar14 >> 8);
        uVar14 = CONCAT13(local_81,CONCAT12(MKDS_SLICE_1(local_85,3),CONCAT11(MKDS_SLICE_1(local_85,2),MKDS_SLICE_1(local_85,1))))
        ;
        uVar18 = (uVar7 >> uVar18 * 8 | uVar7 << uVar18 * -8 + 0x20) & 0xff |
                 (uVar14 >> ((uint)&local_81 & 3) * 8 | uVar14 << ((uint)&local_81 & 3) * -8 + 0x20)
                 & 0xffffff00;
        uVar14 = (4 - ((uint)&local_81 & 3)) * 8 & 0x1f;
        uVar14 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
        local_81 = (undefined1)uVar14;
        uVar18 = DAT_0213b74c + 4 & 3;
        uVar19 = *(uint *)(DAT_0213b74c + 4 & 0xfffffffc);
        bStack_80 = (byte)(uVar19 >> uVar18 * 8) | (byte)(uVar19 << uVar18 * -8 + 0x20);
        uVar14 = CONCAT13(uStack_7d,(int3)(uVar14 >> 8)) & 0xffffff00;
        uStack_7f = (undefined1)(uVar14 >> 8);
        uStack_7e = (undefined1)(uVar14 >> 0x10);
        uStack_7d = (undefined1)(uVar14 >> 0x18);
        puVar16 = (uint *)local_45;
        iVar21 = 8;
        do {
          uVar18 = (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                   *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
          puVar13 = (uint *)((int)puVar16 + 1);
          uVar18 = (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                   *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar13 & 3)) * 8 & 0x1f;
          *puVar13 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
          puVar13 = (uint *)((int)puVar16 + 2);
          uVar18 = (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                   *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar13 & 3)) * 8 & 0x1f;
          *puVar13 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
          puVar13 = (uint *)((int)puVar16 + 3);
          iVar21 = iVar21 + -1;
          uVar18 = (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                   *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar13 & 3)) * 8 & 0x1f;
          puVar16 = puVar16 + 1;
          *puVar13 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
        } while (iVar21 != 0);
        puVar9 = (undefined1 *)((int)&local_85 + 2);
        for (uVar18 = local_d0; (int)uVar18 < 4; uVar18 = uVar18 + 1) {
          uVar14 = uVar6;
          if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
            uVar14 = DAT_0213b740 + uVar6 & 3;
            uVar19 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
            uVar14 = (uVar19 >> uVar14 * 8 | uVar19 << uVar14 * -8 + 0x20) & 0xff;
          }
          if (((*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
               *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xff) !=
              uVar14) break;
          puVar9 = puVar9 + 1;
          iVar5 = iVar5 + 1;
          uVar6 = (*param_2)(param_3,0);
        }
        uVar14 = local_c0;
        if (uVar18 - 3 < 2) {
          if (uVar18 == 4) {
            for (; iVar17 < 0x20; iVar17 = iVar17 + 1) {
              if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
              }
              if (uVar4 == 0) {
                if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
                  uVar4 = 0;
                }
                else {
                  uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 1;
                }
                if ((uVar4 == 0) && (uVar6 != 0x2e)) break;
              }
              puVar16 = (uint *)(local_45 + iVar17);
              uVar6 = uVar6 & 0xff |
                      (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                      *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                      0xffffff00;
              uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
              *puVar16 = uVar6 >> uVar14 | uVar6 << 0x20 - uVar14;
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
            }
            uVar14 = local_c0;
            if (uVar6 != 0x29) goto LAB_0213b83c;
            iVar17 = iVar17 + 1;
          }
          puVar16 = (uint *)(local_45 + iVar17);
          uVar10 = (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                   *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar10 >> uVar14 | uVar10 << 0x20 - uVar14;
          if (bVar2) {
            uVar23 = Maybe_get_16ec9c();
            uVar23 = func_02130ccc(0,0,(int)uVar23,(int)((ulonglong)uVar23 >> 0x20));
          }
          else {
            uVar23 = Maybe_get_16ec9c();
          }
          *param_4 = local_ec + iVar17 + local_100 + uVar18;
          return uVar23;
        }
      }
      goto LAB_0213b83c;
    }
    if (uVar18 < 0x4001) {
      if (uVar18 == 0x4000) {
        puVar16 = local_4e;
        iVar17 = 4;
        uVar14 = DAT_0213b744;
        do {
          puVar13 = (uint *)(uVar14 & 0xfffffffc);
          uVar18 = uVar14 & 3;
          uVar19 = uVar14 + 1 & 3;
          uVar20 = *(uint *)(uVar14 + 1 & 0xfffffffc);
          uVar14 = uVar14 + 2;
          iVar17 = iVar17 + -1;
          uVar7 = (*puVar13 >> uVar18 * 8 | *puVar13 << uVar18 * -8 + 0x20) & 0xff |
                  (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                  *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar18 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
          *puVar16 = uVar7 >> uVar18 | uVar7 << 0x20 - uVar18;
          puVar13 = (uint *)((int)puVar16 + 1);
          uVar19 = (uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20) & 0xff |
                   (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                   *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) &
                   0xffffff00;
          uVar18 = (4 - ((uint)puVar13 & 3)) * 8 & 0x1f;
          puVar16 = (uint *)((int)puVar16 + 2);
          *puVar13 = uVar19 >> uVar18 | uVar19 << 0x20 - uVar18;
        } while (iVar17 != 0);
        uVar18 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                 *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) & 0xff |
                 (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                 *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                 0xffffff00;
        uVar14 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
        *puVar16 = uVar18 >> uVar14 | uVar18 << 0x20 - uVar14;
        puVar16 = local_4e;
        for (uVar18 = local_d0; puVar16 = (uint *)((int)puVar16 + 1), (int)uVar18 < 8;
            uVar18 = uVar18 + 1) {
          uVar14 = uVar6;
          if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
            uVar14 = DAT_0213b740 + uVar6 & 3;
            uVar19 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
            uVar14 = (uVar19 >> uVar14 * 8 | uVar19 << uVar14 * -8 + 0x20) & 0xff;
          }
          if (((*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
               *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) & 0xff) !=
              uVar14) break;
          iVar5 = iVar5 + 1;
          uVar6 = (*param_2)(param_3,0);
        }
        if ((uVar18 == 3) || (uVar14 = local_c0, uVar18 == 8)) {
          if (bVar2) {
            func_021329f8(0,*(uint *)(DAT_0213b748 & 0xfffffffc) >> (DAT_0213b748 & 3) * 8 |
                            *(uint *)(DAT_0213b748 & 0xfffffffc) << (DAT_0213b748 & 3) * -8 + 0x20);
            uVar23 = func_02132200();
          }
          else {
            uVar23 = func_02132200(*(uint *)(DAT_0213b748 & 0xfffffffc) >> (DAT_0213b748 & 3) * 8 |
                                   *(uint *)(DAT_0213b748 & 0xfffffffc) <<
                                   (DAT_0213b748 & 3) * -8 + 0x20);
          }
          *param_4 = local_ec + local_100 + uVar18;
          return uVar23;
        }
      }
    }
    else if (uVar18 == 0x8000) {
      if (uVar19 < 0x21) {
        if (uVar19 < 0x20) {
          if (uVar19 < 9) {
            uVar18 = local_dc >> 0x1f;
            switch(uVar19) {
            case 0:
              break;
            case 1:
              uVar6 = CONCAT13(MKDS_SLICE_1(local_8c,3),
                               CONCAT12(MKDS_SLICE_1(local_8c,2),CONCAT11(MKDS_SLICE_1(local_8c,1),(undefined1)local_8c)
                                       )) & 0xffffff00;
              MKDS_SLICE_1(local_8c,0) = 0;
              uVar10 = (int)&local_8c + 1U & 3;
              uVar6 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) & 0xffffff00;
              uVar10 = (4 - ((int)&local_8c + 1U & 3)) * 8 & 0x1f;
              uVar10 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
              MKDS_SLICE_1(local_8c,1) = (undefined1)uVar10;
              uVar6 = (int)&local_8c + 2U & 3;
              uVar10 = uVar10 << 8;
              local_e8 = &local_8c;
              uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) & 0xffffff00;
              uVar10 = (4 - ((int)&local_8c + 2U & 3)) * 8 & 0x1f;
              uVar10 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
              MKDS_SLICE_1(local_8c,2) = (undefined1)uVar10;
              MKDS_SLICE_1(local_8c,3) = (undefined1)(uVar10 >> 8);
              uVar10 = (int)&local_8c + 3U & 3;
              uVar6 = (uint)CONCAT12(MKDS_SLICE_1(local_8c,3),CONCAT11(MKDS_SLICE_1(local_8c,2),MKDS_SLICE_1(local_8c,1))) << 8;
              uVar6 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) & 0xffffff00;
              uVar10 = (4 - ((int)&local_8c + 3U & 3)) * 8 & 0x1f;
              uVar10 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
              MKDS_SLICE_1(local_8c,3) = (undefined1)uVar10;
              uVar6 = CONCAT13((undefined1)local_85,(int3)(uVar10 >> 8)) & 0xffffff00;
              uStack_88 = 0;
              uVar10 = (uint)&uStack_87 & 3;
              uVar6 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) & 0xffffff00;
              uVar10 = (4 - ((uint)&uStack_87 & 3)) * 8 & 0x1f;
              uVar10 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
              uStack_87 = (undefined1)uVar10;
              uVar6 = (uint)&uStack_86 & 3;
              uVar10 = uVar10 << 8;
              uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) & 0xffffff00;
              uVar10 = (4 - ((uint)&uStack_86 & 3)) * 8 & 0x1f;
              uVar10 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
              uStack_86 = (undefined1)uVar10;
              MKDS_SLICE_1(local_85,0) = (undefined1)(uVar10 >> 8);
              uVar10 = (uint)&local_85 & 3;
              uVar6 = (uint)CONCAT12((undefined1)local_85,CONCAT11(uStack_86,uStack_87)) << 8;
              local_e4 = 0xe;
              uVar6 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) & 0xffffff00;
              uVar10 = (4 - ((uint)&local_85 & 3)) * 8 & 0x1f;
              uVar10 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
              MKDS_SLICE_1(local_85,0) = (undefined1)uVar10;
              MKDS_SLICE_1(local_85,1) = (undefined1)(uVar10 >> 8);
              MKDS_SLICE_1(local_85,2) = (undefined1)(uVar10 >> 0x10);
              MKDS_SLICE_1(local_85,3) = (undefined1)(uVar10 >> 0x18);
              local_d4 = 0;
              local_dc = 0;
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
              uVar10 = local_c4;
              break;
            case 2:
              uVar10 = local_b4;
              if (uVar6 == 0x30) {
                iVar5 = iVar5 + 1;
                uVar6 = (*param_2)(param_3,0);
                uVar10 = uVar19;
              }
              break;
            case 3:
              break;
            case 4:
              if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 0x400;
              }
              if (uVar4 == 0) {
                uVar10 = local_bc;
                if (uVar6 == 0x2e) {
                  iVar5 = iVar5 + 1;
                  uVar6 = (*param_2)(param_3,0);
                  uVar10 = local_b0;
                }
              }
              else if (local_d4 < local_e4) {
                local_d4 = local_d4 + 1;
                uVar19 = (int)local_e8 + local_dc / 2;
                uVar20 = uVar19 & 3;
                uVar19 = *(uint *)(uVar19 & 0xfffffffc);
                if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
                  uVar7 = DAT_0213b740 + uVar6 & 3;
                  uVar6 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
                  uVar6 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xff;
                }
                if ((int)uVar6 < 0x41) {
                  uVar6 = uVar6 - 0x30;
                }
                else {
                  uVar6 = uVar6 - 0x37;
                }
                uVar7 = uVar6 & 0xff;
                if ((local_dc * -0x80000000 + uVar18 >> 0x1f | uVar18 << 1) == uVar18) {
                  uVar7 = (uVar6 & 0xf) << 4;
                }
                iVar5 = iVar5 + 1;
                puVar16 = (uint *)((int)local_e8 + local_dc / 2);
                local_dc = local_dc + 1;
                uVar18 = (uVar19 >> uVar20 * 8 | uVar19 << uVar20 * -8 + 0x20) & 0xff | uVar7 |
                         (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                         *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20) &
                         0xffffff00;
                uVar6 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
                *puVar16 = uVar18 >> uVar6 | uVar18 << 0x20 - uVar6;
                uVar6 = (*param_2)(param_3,0);
              }
              else {
                iVar5 = iVar5 + 1;
                uVar6 = (*param_2)(param_3,0);
              }
              break;
            case 5:
              break;
            case 6:
              break;
            case 7:
              break;
            case 8:
              if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 0x400;
              }
              uVar10 = local_bc;
              if (uVar4 != 0) {
                if (local_d4 < local_e4) {
                  uVar10 = (int)local_e8 + local_dc / 2;
                  uVar20 = uVar10 & 3;
                  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
                  if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
                    uVar7 = DAT_0213b740 + uVar6 & 3;
                    uVar6 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
                    uVar6 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xff;
                  }
                  if ((int)uVar6 < 0x41) {
                    uVar6 = uVar6 - 0x30;
                  }
                  else {
                    uVar6 = uVar6 - 0x37;
                  }
                  uVar7 = uVar6 & 0xff;
                  if ((local_dc * -0x80000000 + uVar18 >> 0x1f | uVar18 << 1) == uVar18) {
                    uVar7 = (uVar6 & 0xf) << 4;
                  }
                  iVar5 = iVar5 + 1;
                  puVar16 = (uint *)((int)local_e8 + local_dc / 2);
                  local_dc = local_dc + 1;
                  uVar6 = (uVar10 >> uVar20 * 8 | uVar10 << uVar20 * -8 + 0x20) & 0xff | uVar7 |
                          (*(uint *)((uint)puVar16 & 0xfffffffc) >> ((uint)puVar16 & 3) * 8 |
                          *(uint *)((uint)puVar16 & 0xfffffffc) << ((uint)puVar16 & 3) * -8 + 0x20)
                          & 0xffffff00;
                  uVar10 = (4 - ((uint)puVar16 & 3)) * 8 & 0x1f;
                  *puVar16 = uVar6 >> uVar10 | uVar6 << 0x20 - uVar10;
                  uVar6 = (*param_2)(param_3,0);
                  uVar10 = uVar19;
                }
                else {
                  iVar5 = iVar5 + 1;
                  uVar6 = (*param_2)(param_3,0);
                  uVar10 = uVar19;
                }
              }
            }
          }
          else if (uVar19 == 0x10) {
            uVar19 = uVar6;
            if ((-1 < (int)uVar6) && ((int)uVar6 < 0x80)) {
              uVar14 = DAT_0213b740 + uVar6 & 3;
              uVar19 = *(uint *)(DAT_0213b740 + uVar6 & 0xfffffffc);
              uVar19 = (uVar19 >> uVar14 * 8 | uVar19 << uVar14 * -8 + 0x20) & 0xff;
            }
            uVar14 = local_a0;
            if (uVar19 == 0x50) {
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
              uVar14 = uVar18;
              uVar10 = local_ac;
            }
          }
        }
        else {
          if (uVar6 == 0x2d) {
            local_d8 = 1;
          }
          else if (uVar6 != 0x2b) {
            (*param_2)(param_3,uVar6,1);
            iVar5 = iVar5 + -1;
          }
          iVar5 = iVar5 + 1;
          uVar6 = (*param_2)(param_3,0);
          uVar10 = local_a8;
        }
      }
      else if (uVar19 < 0x81) {
        if (uVar19 < 0x80) {
          if (uVar19 == 0x40) {
            if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
            }
            uVar14 = local_c0;
            if ((uVar4 != 0) && (uVar14 = uVar18, uVar10 = local_9c, uVar6 == 0x30)) {
              iVar5 = iVar5 + 1;
              uVar6 = (*param_2)(param_3,0);
              uVar10 = local_a4;
            }
          }
        }
        else {
          uVar10 = local_9c;
          if (uVar6 == 0x30) {
            iVar5 = iVar5 + 1;
            uVar6 = (*param_2)(param_3,0);
            uVar10 = uVar19;
          }
        }
      }
      else if (uVar19 == 0x100) {
        if (((int)uVar6 < 0) || (0x7f < (int)uVar6)) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(DAT_0213b73c + uVar6 * 2) & 8;
        }
        uVar14 = local_a0;
        if (uVar4 != 0) {
          iVar5 = iVar5 + 1;
          local_e0 = local_e0 * 10 + (uVar6 - 0x30);
          if (DAT_0213b750 < (int)local_f4) {
            *param_5 = 1;
          }
          uVar6 = (*param_2)(param_3,0);
          uVar14 = uVar18;
        }
      }
    }
  } while( true );
}

