/* Decompiled C draft; module arm9; ROM address 020a3fa8. No matching claim. */
#include "types.h"
#include "deps/020a3fa8_func_020a3fa8.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020a3fa8(undefined4 param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *unaff_r5;
  uint uVar15;
  int iVar16;
  int *piVar17;
  ushort *puStack_bc;
  ushort *puStack_a0;
  ushort *puStack_9c;
  ushort *puStack_98;
  ushort *puStack_7c;
  ushort *puStack_78;
  ushort *puStack_74;
  ushort *puStack_70;
  int iStack_6c;
  int iStack_68;
  uint uStack_60;
  ushort *puStack_5c;
  ushort *puStack_50;
  ushort *puStack_4c;
  uint uStack_48;
  int iStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  uVar5 = param_2 + 0xa0U & 3;
  uVar11 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar11 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
  uVar5 = (uint)*(byte *)((*(uint *)(DAT_020a49b4 & 0xfffffffc) >> (DAT_020a49b4 & 3) * 8 |
                          *(uint *)(DAT_020a49b4 & 0xfffffffc) << (DAT_020a49b4 & 3) * -8 + 0x20) +
                         0x3d0);
  if ((int)uVar11 < 1) {
    uVar11 = 0;
    if (uVar5 != 0) {
      uVar1 = *DAT_020a49b8;
      puStack_5c = (ushort *)0x0;
      uVar2 = *DAT_020a49bc;
      puStack_4c = (ushort *)0x0;
      iStack_6c = 0;
      uVar3 = *DAT_020a49c0;
      iStack_68 = 0;
      piVar17 = (int *)(param_2 + 0xa4);
      puStack_78 = (ushort *)0x12c;
      puStack_7c = (ushort *)0x258;
      puStack_70 = (ushort *)0x64;
      puStack_74 = (ushort *)0xc8;
      puStack_98 = (ushort *)0xe;
      puStack_9c = (ushort *)0x29;
      puStack_a0 = (ushort *)&DataAbort;
      puStack_bc = (ushort *)0xcd;
      puStack_50 = (ushort *)0x0;
      uStack_60 = 0;
      puVar14 = DAT_020a49bc;
      do {
        GetGlobalHD5();
        iVar16 = GetDriverEntry(uVar11 & 0xffff);
        uVar6 = iVar16 + 0x80U & 3;
        uVar7 = *(uint *)(iVar16 + 0x80U & 0xfffffffc);
        uStack_48 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        iVar12 = func_020a23a0();
        uVar6 = iVar16 + 0x84U & 3;
        uVar7 = *(uint *)(iVar16 + 0x84U & 0xfffffffc);
        iStack_44 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + iVar12 + DAT_020a49c4;
        uVar6 = iVar16 + 0x88U & 3;
        uVar7 = *(uint *)(iVar16 + 0x88U & 0xfffffffc);
        uStack_40 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        uVar6 = (uint)(piVar17 + 0xd) & 3;
        uVar7 = *(uint *)((uint)(piVar17 + 0xd) & 0xfffffffc);
        switch(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) {
        case 0:
          uVar6 = *(uint *)((uint)piVar17 & 0xfffffffc) >> ((uint)piVar17 & 3) * 8 |
                  *(uint *)((uint)piVar17 & 0xfffffffc) << ((uint)piVar17 & 3) * -8 + 0x20;
          if ((int)uVar6 < 1) {
            iVar12 = func_020a10d4(uVar11 & 0xffff);
            if ((((iVar12 != 0) && (uVar6 = func_020a1154(uVar11 & 0xffff), uVar6 < 3)) &&
                ((iVar12 = func_020a2264(uVar11 & 0xffff), 0 < iVar12 ||
                 (iVar12 = func_020a223c(uVar11 & 0xffff), 0 < iVar12)))) &&
               (unaff_r5 = (ushort *)func_020a2fe4((short)piVar17[0xc],&uStack_48),
               unaff_r5 != (ushort *)0x0)) {
              iVar12 = func_020a1154(uVar11 & 0xffff);
              piVar17[iVar12 + 4] = (int)unaff_r5;
              puVar14 = puStack_bc;
              func_020a2f9c(unaff_r5,uVar11 & 0xffff);
              piVar17[0xd] = 2;
              func_020a2220(uVar11 & 0xffff,1);
              func_020a10ac(uVar11 & 0xffff,0xffffffff);
            }
          }
          else {
            *piVar17 = uVar6 - 1;
          }
          break;
        case 1:
          iVar12 = func_020a2204(uVar11 & 0xffff);
          if (iVar12 == 0) {
            iVar12 = func_020a10d4(uVar11 & 0xffff);
            if ((iVar12 == 0) || (uVar6 = func_020a1154(uVar11 & 0xffff), 2 < uVar6)) {
              piVar17[0xd] = 0;
            }
            else {
              uVar6 = (uint)(piVar17 + 1) & 3;
              uVar7 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
              if ((0 < (int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20)) &&
                 (unaff_r5 = (ushort *)func_020a2fe4((short)piVar17[0xc],&uStack_48),
                 unaff_r5 != (ushort *)0x0)) {
                iVar12 = func_020a1154(uVar11 & 0xffff);
                piVar17[iVar12 + 4] = (int)unaff_r5;
                puVar14 = DAT_020a49c8;
                func_020a2f9c(unaff_r5,uVar11 & 0xffff);
                func_020a2220(uVar11 & 0xffff,1);
                func_020a10ac(uVar11 & 0xffff,0xffffffff);
                uVar6 = (uint)(piVar17 + 1) & 3;
                uVar7 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
                piVar17[1] = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) - 1;
              }
            }
          }
          else {
            iVar12 = func_020a1154(uVar11 & 0xffff);
            uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
            uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
            puVar14 = DAT_020a49c8;
            func_020a2f9c(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar11 & 0xffff);
          }
          break;
        case 2:
          iVar12 = func_020a2264(uVar11 & 0xffff);
          if (iVar12 < 0) {
            piVar17[0xd] = 4;
          }
          else {
            iVar12 = func_020a1154(uVar11 & 0xffff);
            uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
            uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
            unaff_r5 = (ushort *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
            puVar14 = puStack_bc;
            func_020a2f9c(unaff_r5,uVar11 & 0xffff);
            iVar12 = func_020a2e60((int)(uintptr_t)(unaff_r5));
            if (0x7ff < iVar12) {
              piVar17[0xd] = 3;
            }
          }
          break;
        case 3:
          iVar12 = func_020a2264(uVar11 & 0xffff);
          if (iVar12 < 0) {
            piVar17[0xd] = 4;
          }
          else {
            iVar12 = func_020a223c(uVar11 & 0xffff);
            if (iVar12 < 1) {
              iVar12 = func_020a2264(uVar11 & 0xffff);
              if (iVar12 < 1) {
                iVar12 = func_020a1154(uVar11 & 0xffff);
                uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
                uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
                unaff_r5 = (ushort *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
                puVar14 = puStack_98;
                func_020a2f30(unaff_r5,uVar11 & 0xffff);
                iVar12 = func_020a2e60((int)(uintptr_t)(unaff_r5));
                if (iVar12 < 0x401) {
                  piVar17[0xd] = 4;
                }
              }
              else {
                iVar12 = func_020a1154(uVar11 & 0xffff);
                uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
                uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
                puVar14 = puStack_9c;
                func_020a2f9c(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar11 & 0xffff);
              }
            }
            else {
              iVar12 = func_020a1154(uVar11 & 0xffff);
              uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
              uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
              puVar14 = puStack_a0;
              func_020a2f9c(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar11 & 0xffff);
            }
          }
          break;
        case 4:
          iVar12 = func_020a1154(uVar11 & 0xffff);
          uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
          uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
          puVar14 = DAT_020a49cc;
          func_020a2f30(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,uVar11 & 0xffff);
        }
        iVar12 = func_020a2204(uVar11 & 0xffff);
        if (iVar12 == 0) {
          uVar6 = (uint)(piVar17 + 1) & 3;
          uVar7 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
          if ((int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) < 1) {
            piVar17[0xd] = 0;
          }
        }
        else {
          iVar12 = func_020a1154(uVar11 & 0xffff);
          uVar6 = (uint)(piVar17 + iVar12 + 4) & 3;
          uVar7 = *(uint *)((uint)(piVar17 + iVar12 + 4) & 0xfffffffc);
          unaff_r5 = (ushort *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
          iVar12 = func_020a2e60((int)(uintptr_t)(unaff_r5));
          if (iVar12 < 1) {
            iVar12 = func_020a1154(uVar11 & 0xffff);
            piVar17[iVar12 + 4] = 0;
            func_020a2220(uVar11 & 0xffff,0);
            func_020a10ac(uVar11 & 0xffff,1);
            *piVar17 = 0;
            piVar17[0xd] = 0;
          }
          else {
            iVar12 = func_020a2e60((int)(uintptr_t)(unaff_r5));
            if (0xfff < iVar12) {
              func_020a2220(uVar11 & 0xffff,0);
              MaybeUpdateDriverBalloonShineCount(uVar11 & 0xffff,1);
              uVar6 = (uint)(piVar17 + 1) & 3;
              uVar7 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
              if ((int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) < 1) {
                *piVar17 = 0x1e;
                piVar17[0xd] = 0;
              }
              uVar8 = GetDriverEntry(uVar11 & 0xffff);
              func_020d26ec(uVar8,DAT_020a49d0);
            }
          }
        }
        if (uVar11 == (int)*(char *)((*(uint *)(DAT_020a49b4 & 0xfffffffc) >> (DAT_020a49b4 & 3) * 8
                                     | *(uint *)(DAT_020a49b4 & 0xfffffffc) <<
                                       (DAT_020a49b4 & 3) * -8 + 0x20) + 0x62)) {
          iVar12 = func_020a2264(uVar11 & 0xffff);
          if ((iVar12 < 1) && (iVar12 = func_020a223c(uVar11 & 0xffff), iVar12 < 1)) {
            uVar6 = func_020a1154(uVar11 & 0xffff);
            if (2 < uVar6) {
              puVar14 = puStack_7c;
            }
            uVar7 = (uint)(piVar17 + 2) & 3;
            uVar15 = *(uint *)((uint)(piVar17 + 2) & 0xfffffffc);
            uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
            if (2 >= uVar6) {
              puVar14 = puStack_78;
            }
            if ((int)uVar7 < 0) {
              iVar12 = iStack_68;
              if (uVar7 == -(int)puVar14 ||
                  (int)(uVar7 + (int)puVar14) < 0 != SBORROW4(uVar7,-(int)puVar14)) {
                iVar12 = uVar7 + (int)puVar14;
              }
              piVar17[2] = iVar12;
            }
            else {
              iVar12 = iStack_6c;
              if ((int)puVar14 <= (int)uVar7) {
                iVar12 = uVar7 - (int)puVar14;
              }
              piVar17[2] = iVar12;
            }
          }
          else {
            uVar6 = func_020a1154(uVar11 & 0xffff);
            if (2 < uVar6) {
              unaff_r5 = puStack_7c;
            }
            if (2 >= uVar6) {
              unaff_r5 = puStack_78;
            }
            uVar6 = func_020a1154(uVar11 & 0xffff);
            if (2 < uVar6) {
              puVar14 = puStack_74;
            }
            uVar7 = (uint)(piVar17 + 2) & 3;
            uVar13 = *(uint *)((uint)(piVar17 + 2) & 0xfffffffc);
            uVar15 = (uint)(piVar17 + 3) & 3;
            uVar9 = *(uint *)((uint)(piVar17 + 3) & 0xfffffffc);
            if (2 >= uVar6) {
              puVar14 = puStack_70;
            }
            piVar17[2] = (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) +
                         (uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20);
            uVar6 = (uint)(piVar17 + 2) & 3;
            uVar7 = *(uint *)((uint)(piVar17 + 2) & 0xfffffffc);
            if ((int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) < 0) {
              uVar6 = (uint)(piVar17 + 3) & 3;
              uVar7 = *(uint *)((uint)(piVar17 + 3) & 0xfffffffc);
              uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
              if ((int)uVar6 < 0) {
                piVar17[3] = uVar6 + (int)puVar14;
              }
              else {
                piVar17[3] = (int)unaff_r5;
              }
            }
            else {
              uVar6 = (uint)(piVar17 + 3) & 3;
              uVar7 = *(uint *)((uint)(piVar17 + 3) & 0xfffffffc);
              uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
              if ((int)uVar6 < 0) {
                piVar17[3] = -(int)unaff_r5;
              }
              else {
                piVar17[3] = uVar6 - (int)puVar14;
              }
            }
          }
          iVar12 = func_020a2204(uVar11 & 0xffff);
          iVar10 = func_020a1154(uVar11 & 0xffff);
          iVar10 = iVar10 + (int)(uint)(iVar12 != 0);
          unaff_r5 = (ushort *)(uint)(iVar12 != 0);
          if (0 < iVar10) {
            uVar6 = uStack_60;
            do {
              uVar7 = (uint)(piVar17 + uVar6 + 4) & 3;
              uVar15 = *(uint *)((uint)(piVar17 + uVar6 + 4) & 0xfffffffc);
              unaff_r5 = (ushort *)(uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20);
              uVar15 = (uint)(piVar17 + 2) & 3;
              uVar13 = *(uint *)((uint)(piVar17 + 2) & 0xfffffffc);
              uVar7 = param_2 + (iVar10 + -1) * 0x20 + uVar6 * 4 + 0x264;
              uVar9 = uVar7 & 3;
              uVar7 = *(uint *)(uVar7 & 0xfffffffc);
              iVar12 = (uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20) +
                       (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20);
              if (iVar12 != 0) {
                uVar7 = iVar16 + 0x150U & 3;
                uVar15 = *(uint *)(iVar16 + 0x150U & 0xfffffffc);
                lVar4 = (longlong)(int)(uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20) *
                        (longlong)iVar12;
                uStack_3c = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
                uVar7 = iVar16 + 0x154U & 3;
                uVar15 = *(uint *)(iVar16 + 0x154U & 0xfffffffc);
                lVar4 = (longlong)(int)(uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20) *
                        (longlong)iVar12;
                uStack_38 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
                uVar7 = iVar16 + 0x158U & 3;
                uVar15 = *(uint *)(iVar16 + 0x158U & 0xfffffffc);
                lVar4 = (longlong)(int)(uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20) *
                        (longlong)iVar12;
                uStack_34 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
                func_020a2e74((int)(uintptr_t)(unaff_r5),(undefined4)(uintptr_t)(&uStack_3c));
              }
              if ((uVar6 & 1) == 1) {
                uVar7 = iVar16 + 0x168U & 3;
                uVar15 = *(uint *)(iVar16 + 0x168U & 0xfffffffc);
                uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
                uStack_30 = (uint)((ulonglong)uVar7 * 0xffffff33) >> 0xc |
                            (((int)uVar7 >> 0x1f) * -0xcd +
                            ((int)((ulonglong)uVar7 * 0xffffff33 >> 0x20) - uVar7)) * 0x100000;
                uVar7 = iVar16 + 0x16cU & 3;
                uVar15 = *(uint *)(iVar16 + 0x16cU & 0xfffffffc);
                uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
                uStack_2c = (uint)((ulonglong)uVar7 * 0xffffff33) >> 0xc |
                            (((int)uVar7 >> 0x1f) * -0xcd +
                            ((int)((ulonglong)uVar7 * 0xffffff33 >> 0x20) - uVar7)) * 0x100000;
                uVar7 = iVar16 + 0x170U & 3;
                uVar15 = *(uint *)(iVar16 + 0x170U & 0xfffffffc);
                uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
                uStack_28 = (uint)((ulonglong)uVar7 * 0xffffff33) >> 0xc |
                            (((int)uVar7 >> 0x1f) * -0xcd +
                            ((int)((ulonglong)uVar7 * 0xffffff33 >> 0x20) - uVar7)) * 0x100000;
                func_020a2e74((int)(uintptr_t)(unaff_r5),(undefined4)(uintptr_t)(&uStack_30));
              }
              func_020a2e88(unaff_r5,&uStack_48,iVar16 + 0xa4);
              func_020a2e58(unaff_r5,uVar11 & 0xffff);
              puVar14 = puStack_5c;
              func_020a2e4c(unaff_r5,1);
              uVar6 = uVar6 + 1;
              unaff_r5[1] = unaff_r5[1] & 0xfffb;
              unaff_r5[1] = unaff_r5[1] & 0xfffd;
              unaff_r5[1] = unaff_r5[1] & 0xfff7;
              unaff_r5[0x33] = 0x1f;
            } while ((int)uVar6 < iVar10);
          }
        }
        else {
          iVar12 = func_020a2204(uVar11 & 0xffff);
          iVar10 = func_020a1154(uVar11 & 0xffff);
          uVar6 = iVar10 + (uint)(iVar12 != 0);
          unaff_r5 = puStack_50;
          if (0 < (int)uVar6) {
            do {
              uVar7 = (uint)(piVar17 + (int)(unaff_r5 + 2)) & 3;
              uVar15 = *(uint *)((uint)(piVar17 + (int)(unaff_r5 + 2)) & 0xfffffffc);
              uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
              func_020a2e88(uVar7,&uStack_48,iVar16 + 0xa4);
              func_020a2e58(uVar7,uVar11 & 0xffff);
              if (unaff_r5 == (ushort *)0x0) {
                puVar14 = (ushort *)(piVar17 + 4);
                func_020a2e4c(uVar7,uVar6 & 0xffff);
                *(ushort *)(uVar7 + 2) = *(ushort *)(uVar7 + 2) & 0xfffb;
                *(ushort *)(uVar7 + 2) = *(ushort *)(uVar7 + 2) & 0xfffd;
                *(ushort *)(uVar7 + 2) = *(ushort *)(uVar7 + 2) & 0xfff7;
                *(undefined2 *)(uVar7 + 0x66) = 0x1f;
              }
              else {
                puVar14 = puStack_4c;
                func_020a2e4c(uVar7);
                *(ushort *)(uVar7 + 2) = *(ushort *)(uVar7 + 2) | uVar1;
                *(ushort *)(uVar7 + 2) = *(ushort *)(uVar7 + 2) | uVar2;
                *(ushort *)(uVar7 + 2) = *(ushort *)(uVar7 + 2) | uVar3;
              }
              unaff_r5 = (ushort *)((int)unaff_r5 + 1);
            } while ((int)unaff_r5 < (int)uVar6);
          }
        }
        uVar11 = uVar11 + 1;
        piVar17 = piVar17 + 0xe;
      } while ((int)uVar11 < (int)uVar5);
      return;
    }
    return;
  }
  *(uint *)(param_2 + 0xa0) = uVar11 - 1;
  uVar11 = param_2 + 0xa0U & 3;
  uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  if ((int)(uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) < 1) {
    uVar11 = 0;
    if (uVar5 != 0) {
      iVar16 = param_2 + 0xa4;
      do {
        GetDriverEntry(uVar11 & 0xffff);
        *(undefined4 *)(iVar16 + 0x34) = 1;
        uVar6 = param_2 + 0x9cU & 3;
        uVar7 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        iVar12 = (int)*(short *)(uVar6 + 0x28);
        if ((iVar12 == 0) && (*(short *)(uVar6 + 0x2a) == 0)) {
          *(undefined4 *)(iVar16 + 4) = 1;
          func_020a10ac(uVar11 & 0xffff,5);
        }
        else {
          *(int *)(iVar16 + 4) = iVar12;
          uVar6 = param_2 + 0x9cU & 3;
          uVar7 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
          uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
          func_020a10ac(uVar11 & 0xffff,
                        (int)*(short *)(uVar6 + 0x28) + (int)*(short *)(uVar6 + 0x2a));
        }
        uVar11 = uVar11 + 1;
        iVar16 = iVar16 + 0x38;
      } while ((int)uVar11 < (int)uVar5);
      return;
    }
    return;
  }
  return;
}

