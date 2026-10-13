/* Decompiled C draft; module arm9; ROM address 020dccc8. No matching claim. */
#include "types.h"
#include "deps/020dccc8_func_020dccc8.h"

void func_020dccc8(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  bool bVar22;
  int local_40;
  uint local_2c;
  uint uVar13;
  uint uVar21;
  
  uVar5 = param_1 + 4U & 3;
  uVar8 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0xcU & 3;
  uVar8 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  iVar4 = func_020d849c(param_1 + 0x100);
  if (iVar4 != 0) {
    uVar5 = param_1 + 0x16cU & 3;
    uVar8 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
    uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x168U & 3;
    uVar12 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    uVar13 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
    uVar5 = uVar8 + 8 & 3;
    uVar9 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    uVar12 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
             *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) -
             (*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
             *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20);
    uVar8 = uVar13 + 8 & 3;
    uVar13 = *(uint *)(uVar13 + 8 & 0xfffffffc);
    uVar5 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) -
            (uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20);
    local_2c = 0;
    do {
      local_40 = 0;
      uVar8 = param_1 + 0x160U & 3;
      uVar13 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
      piVar14 = (int *)(uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20);
      do {
        do {
          uVar8 = param_1 + 0xf8U & 3;
          uVar13 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
          piVar6 = (int *)func_020d22d0();
          uVar13 = (uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20) - 0x2d000;
          uVar8 = local_2c;
          if (uVar13 != 0) {
            uVar8 = (uint)(piVar6 + 2) & 3;
            uVar9 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
            uVar17 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
            uVar11 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                     *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
            uVar8 = (uint)(piVar6 + 1) & 3;
            uVar10 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
            lVar2 = (ulonglong)uVar11 * (ulonglong)uVar17;
            uVar18 = (uint)lVar2;
            uVar9 = (uint)(piVar6 + 3) & 3;
            uVar16 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
            uVar19 = (uint)(piVar6 + 4) & 3;
            uVar20 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
            uVar21 = uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20;
            uVar19 = (uint)(piVar6 + 5) & 3;
            uVar20 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
            *piVar6 = uVar21 + uVar18;
            piVar6[1] = (uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20) +
                        (uVar16 >> uVar9 * 8 | uVar16 << uVar9 * -8 + 0x20) * uVar11 +
                        uVar17 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
                        (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar21,uVar18);
            if (uVar13 == 0) {
              uVar8 = (uint)(piVar6 + 1) & 3;
              uVar13 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
              uVar8 = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
            }
            else {
              uVar8 = (uint)(piVar6 + 1) & 3;
              uVar9 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
              uVar8 = (uint)((ulonglong)uVar13 *
                             (ulonglong)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) >> 0x20);
            }
          }
          piVar6 = (int *)func_020d22d0();
          uVar13 = (uint)(piVar6 + 2) & 3;
          uVar9 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
          uVar10 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
          uVar20 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                   *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
          uVar13 = (uint)(piVar6 + 1) & 3;
          uVar11 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
          local_40 = local_40 + 1;
          lVar2 = (ulonglong)uVar20 * (ulonglong)uVar10;
          uVar16 = (uint)lVar2;
          uVar9 = (uint)(piVar6 + 4) & 3;
          uVar19 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
          uVar18 = uVar19 >> uVar9 * 8 | uVar19 << uVar9 * -8 + 0x20;
          uVar9 = (uint)(piVar6 + 3) & 3;
          uVar21 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
          uVar19 = (uint)(piVar6 + 5) & 3;
          uVar17 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
          *piVar6 = uVar18 + uVar16;
          piVar6[1] = (uVar17 >> uVar19 * 8 | uVar17 << uVar19 * -8 + 0x20) +
                      (uVar21 >> uVar9 * 8 | uVar21 << uVar9 * -8 + 0x20) * uVar20 +
                      uVar10 * (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) +
                      (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar16);
          uVar13 = (uint)(piVar6 + 1) & 3;
          uVar9 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
          iVar4 = (int)((uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) >> 0x10) >> 4;
          lVar2 = (longlong)(int)(uVar8 + 0x2d000) *
                  (longlong)(int)*(short *)(iRam020dd0cc + iVar4 * 4);
          uVar13 = param_1 + 0xa0U & 3;
          uVar9 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
          *piVar14 = (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) +
                     ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
          uVar13 = param_1 + 0xa8U & 3;
          uVar9 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
          lVar2 = (longlong)(int)(uVar8 + 0x2d000) *
                  (longlong)(int)*(short *)(iRam020dd0cc + (iVar4 * 2 + 1) * 2);
          piVar14[2] = (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) +
                       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
          if (5 < local_40) goto LAB_020dcf58;
          uVar8 = param_1 + 0x16cU & 3;
          uVar13 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
          uVar10 = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
          uVar8 = (uint)(piVar14 + 2) & 3;
          uVar19 = *(uint *)((uint)(piVar14 + 2) & 0xfffffffc);
          uVar13 = uVar10 + 8 & 3;
          uVar9 = *(uint *)(uVar10 + 8 & 0xfffffffc);
          uVar8 = (uVar19 >> uVar8 * 8 | uVar19 << uVar8 * -8 + 0x20) -
                  (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20);
          uVar13 = (*(uint *)((uint)piVar14 & 0xfffffffc) >> ((uint)piVar14 & 3) * 8 |
                   *(uint *)((uint)piVar14 & 0xfffffffc) << ((uint)piVar14 & 3) * -8 + 0x20) -
                   (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                   *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20);
          lVar2 = (longlong)(int)uVar13 * (longlong)(int)uVar13 +
                  (longlong)(int)uVar8 * (longlong)(int)uVar8;
          iVar4 = (int)((ulonglong)lVar2 >> 0x20);
          bVar22 = (uint)lVar2 < 0xe9000000;
        } while ((int)(iVar4 - (bVar22 + 7)) < 0 !=
                 (SBORROW4(iVar4,7) != SBORROW4(iVar4 + -7,(uint)bVar22)));
        uVar19 = (uint)((ulonglong)uVar12 * (ulonglong)uVar13);
        uVar9 = (uint)((ulonglong)uVar5 * (ulonglong)uVar8);
        uVar9 = uVar19 + uVar9 >> 0xc |
                (((int)uVar13 >> 0x1f) * uVar12 +
                 uVar13 * ((int)uVar12 >> 0x1f) +
                 (int)((ulonglong)uVar12 * (ulonglong)uVar13 >> 0x20) +
                 ((int)uVar8 >> 0x1f) * uVar5 +
                 uVar8 * ((int)uVar5 >> 0x1f) + (int)((ulonglong)uVar5 * (ulonglong)uVar8 >> 0x20) +
                (uint)CARRY4(uVar19,uVar9)) * 0x100000;
        if (-1 < (int)uVar9) break;
        lVar2 = (ulonglong)uVar5 * (ulonglong)-uVar13;
        uVar19 = (uint)lVar2;
        uVar10 = (uint)((ulonglong)uVar12 * (ulonglong)uVar8);
        uVar8 = uVar19 + uVar10 >> 0xc |
                (-(((int)uVar13 >> 0x1f) + (uint)(uVar13 != 0)) * uVar5 +
                 -uVar13 * ((int)uVar5 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20) +
                 ((int)uVar8 >> 0x1f) * uVar12 +
                 uVar8 * ((int)uVar12 >> 0x1f) + (int)((ulonglong)uVar12 * (ulonglong)uVar8 >> 0x20)
                + (uint)CARRY4(uVar19,uVar10)) * 0x100000;
        if ((int)uVar8 < 0) {
          uVar8 = -uVar8;
        }
      } while ((int)uVar8 <= (int)-uVar9 >> 2);
LAB_020dcf58:
      uVar8 = param_1 + 0x164U & 3;
      uVar13 = *(uint *)(param_1 + 0x164U & 0xfffffffc);
      *(uint *)(param_1 + 0x160) = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
      uVar8 = param_1 + 0x168U & 3;
      uVar13 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
      *(uint *)(param_1 + 0x164) = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
      uVar8 = param_1 + 0x16cU & 3;
      uVar13 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
      *(uint *)(param_1 + 0x168) = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
      *(int **)(param_1 + 0x16c) = piVar14;
      iVar4 = func_020d7c84(param_1 + 0x100,1,param_1 + 0x160);
    } while (iVar4 != 0);
  }
  func_020d8474(param_1 + 0x100,param_1 + 4);
  if ((*(ushort *)(param_1 + 2) & 0x800) == 0) {
    uVar3 = func_02061fa4();
    iVar4 = GetDriverEntry(uVar3);
    iVar7 = StructMQRacerEntry_SomeFn_86();
    if (iVar7 == 0) {
      uVar5 = iVar4 + 0x88U & 3;
      uVar9 = *(uint *)(iVar4 + 0x88U & 0xfffffffc);
      uVar8 = param_1 + 0xa8U & 3;
      uVar13 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
      uVar12 = param_1 + 0x1dcU & 3;
      uVar19 = *(uint *)(param_1 + 0x1dcU & 0xfffffffc);
      uVar19 = uVar19 >> uVar12 * 8 | uVar19 << uVar12 * -8 + 0x20;
      iVar7 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) -
              (uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20);
      uVar5 = iVar4 + 0x80U & 3;
      uVar13 = *(uint *)(iVar4 + 0x80U & 0xfffffffc);
      uVar8 = param_1 + 0xa0U & 3;
      uVar12 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
      lVar1 = (longlong)(int)uVar19 * (longlong)(int)uVar19;
      iVar4 = (int)((ulonglong)lVar1 >> 0x20);
      iVar15 = (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) -
               (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      lVar2 = (longlong)iVar15 * (longlong)iVar15 + (longlong)iVar7 * (longlong)iVar7;
      iVar7 = (int)((ulonglong)lVar2 >> 0x20);
      bVar22 = (uint)lVar2 < (uint)lVar1;
      if ((int)(iVar7 - (iVar4 + (uint)bVar22)) < 0 !=
          (SBORROW4(iVar7,iVar4) != SBORROW4(iVar7 - iVar4,(uint)bVar22))) {
        iVar4 = GetDriverEntry(uVar3);
        *(int *)(param_1 + 0x1f0) = iVar4 + 0x80;
        iVar4 = GetDriverEntry(uVar3);
        *(int *)(param_1 + 500) = iVar4 + 0xa4;
        *(undefined2 *)(param_1 + 0x90) = 1;
        *(undefined2 *)(param_1 + 0x92) = 1;
      }
    }
  }
  uVar5 = param_1 + 4U & 3;
  uVar13 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar8 = param_1 + 0x10U & 3;
  uVar12 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) =
       (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) -
       (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
  uVar5 = param_1 + 0xcU & 3;
  uVar13 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar8 = param_1 + 0x18U & 3;
  uVar12 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) =
       (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) -
       (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
  uVar5 = param_1 + 0x18U & 3;
  uVar8 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar12 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x10U & 3;
  uVar8 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar5 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
          (longlong)(int)uVar12 * (longlong)(int)uVar12;
  if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
    uVar5 = param_1 + 0x10U & 3;
    uVar12 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar8 = param_1 + 0x18U & 3;
    uVar13 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar5 = func_02148538(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20,
                          uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20);
    func_020d7b34((((int)uVar5 >> 0x1f) * uRam020dd0d0 +
                   uVar5 * iRam020dd0d4 + (int)((ulonglong)uRam020dd0d0 * (ulonglong)uVar5 >> 0x20)
                  + 0x800) * 0x10 >> 0x10,param_1 + 0xd4);
  }
  uVar5 = param_1 + 0x84U & 3;
  uVar8 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) < 0x40) {
    uVar5 = param_1 + 0xecU & 3;
    uVar8 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
    *(uint *)(param_1 + 0xec) = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0x1c;
  }
  return;
}

