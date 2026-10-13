/* Decompiled C draft; module arm9; ROM address 02092b5c. No matching claim. */
#include "types.h"
#include "deps/02092b5c_func_02092b5c.h"

/* WARNING: Removing unreachable block (ram,0x02092f10) */

void func_02092b5c(undefined4 param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar23;
  uint uVar24;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  uint uVar4;
  uint uVar17;
  uint uVar22;
  
  uVar4 = param_2 + 0xacU & 3;
  uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    if (uVar4 != 1) {
      return;
    }
    if (*(short *)(param_2 + 0xa0) == 0x14) {
      iVar14 = 0;
      do {
        uVar4 = param_2 + 0xcU & 3;
        uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
        uVar3 = param_2 + 4U & 3;
        uVar15 = *(uint *)(param_2 + 4U & 0xfffffffc);
        uVar20 = param_2 + 8U & 3;
        uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
        piVar7 = (int *)func_020d22d0();
        uVar19 = (uint)(piVar7 + 2) & 3;
        uVar16 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
        uVar17 = uVar16 >> uVar19 * 8 | uVar16 << uVar19 * -8 + 0x20;
        uVar23 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                 *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
        uVar19 = (uint)(piVar7 + 1) & 3;
        uVar12 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar23 * (ulonglong)uVar17;
        uVar18 = (uint)lVar2;
        uVar16 = (uint)(piVar7 + 3) & 3;
        uVar24 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
        uVar13 = (uint)(piVar7 + 4) & 3;
        uVar21 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
        uVar22 = uVar21 >> uVar13 * 8 | uVar21 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(piVar7 + 5) & 3;
        uVar21 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
        *piVar7 = uVar22 + uVar18;
        piVar7[1] = (uVar21 >> uVar13 * 8 | uVar21 << uVar13 * -8 + 0x20) +
                    (uVar24 >> uVar16 * 8 | uVar24 << uVar16 * -8 + 0x20) * uVar23 +
                    uVar17 * (uVar12 >> uVar19 * 8 | uVar12 << uVar19 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar22,uVar18);
        uVar19 = (uint)(piVar7 + 1) & 3;
        uVar16 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
        local_3c = ((uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) - 0x5000) +
                   (int)((ulonglong)(uVar16 >> uVar19 * 8 | uVar16 << uVar19 * -8 + 0x20) * 0xa000
                        >> 0x20);
        piVar7 = (int *)func_020d22d0();
        uVar3 = (uint)(piVar7 + 2) & 3;
        uVar19 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
        uVar17 = uVar19 >> uVar3 * 8 | uVar19 << uVar3 * -8 + 0x20;
        uVar12 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                 *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
        uVar3 = (uint)(piVar7 + 1) & 3;
        uVar13 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar12 * (ulonglong)uVar17;
        uVar18 = (uint)lVar2;
        uVar19 = (uint)(piVar7 + 3) & 3;
        uVar15 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
        uVar16 = (uint)(piVar7 + 4) & 3;
        uVar21 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
        uVar22 = uVar21 >> uVar16 * 8 | uVar21 << uVar16 * -8 + 0x20;
        uVar16 = (uint)(piVar7 + 5) & 3;
        uVar21 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
        *piVar7 = uVar22 + uVar18;
        piVar7[1] = (uVar21 >> uVar16 * 8 | uVar21 << uVar16 * -8 + 0x20) +
                    (uVar15 >> uVar19 * 8 | uVar15 << uVar19 * -8 + 0x20) * uVar12 +
                    uVar17 * (uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar22,uVar18);
        uVar3 = (uint)(piVar7 + 1) & 3;
        uVar19 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
        local_38 = (uVar6 >> uVar20 * 8 | uVar6 << uVar20 * -8 + 0x20) + 0x1e000 +
                   (int)((ulonglong)(uVar19 >> uVar3 * 8 | uVar19 << uVar3 * -8 + 0x20) * 0xa000 >>
                        0x20);
        piVar7 = (int *)func_020d22d0();
        uVar3 = (uint)(piVar7 + 2) & 3;
        uVar20 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
        uVar12 = uVar20 >> uVar3 * 8 | uVar20 << uVar3 * -8 + 0x20;
        uVar13 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                 *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
        uVar3 = (uint)(piVar7 + 1) & 3;
        uVar16 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar13 * (ulonglong)uVar12;
        uVar15 = (uint)lVar2;
        uVar20 = (uint)(piVar7 + 3) & 3;
        uVar6 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
        uVar19 = (uint)(piVar7 + 4) & 3;
        uVar17 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
        uVar18 = uVar17 >> uVar19 * 8 | uVar17 << uVar19 * -8 + 0x20;
        uVar19 = (uint)(piVar7 + 5) & 3;
        uVar17 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
        *piVar7 = uVar18 + uVar15;
        piVar7[1] = (uVar17 >> uVar19 * 8 | uVar17 << uVar19 * -8 + 0x20) +
                    (uVar6 >> uVar20 * 8 | uVar6 << uVar20 * -8 + 0x20) * uVar13 +
                    uVar12 * (uVar16 >> uVar3 * 8 | uVar16 << uVar3 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar15);
        uVar3 = (uint)(piVar7 + 1) & 3;
        uVar20 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
        local_34 = ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) - 0x28000) +
                   (int)((ulonglong)(uVar20 >> uVar3 * 8 | uVar20 << uVar3 * -8 + 0x20) * 0x50000 >>
                        0x20);
        uVar1 = *(ushort *)(param_2 + 0x7e);
        uVar8 = func_020d22d0();
        iVar9 = func_02091f6c((int *)(uintptr_t)(uVar8),0x1000);
        uVar8 = func_020d22d0();
        iVar10 = func_02046524((int *)(uintptr_t)(uVar8),uRam02093078);
        uVar4 = (uint)uVar1 + iRam0209307c + iVar10 & 0xffff;
        uVar8 = Maybe_get_15d4b4_2(uVar4);
        local_30 = func_020930a0(iVar9 + 0x2000,uVar8);
        uVar8 = func_020d22d0();
        local_2c = func_02091f6c((int *)(uintptr_t)(uVar8),0x400);
        local_2c = local_2c + -0xa00;
        uVar8 = Maybe_helper_093080(uVar4);
        local_28 = func_020930a0(iVar9 + 0x2000,uVar8);
        if ((iVar14 == 0) &&
           (uVar4 = param_2 + 0xa8U & 3, uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc),
           uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0)) {
          func_0209219c(0x8c,&local_3c,&local_30,0xf);
        }
        else {
          func_0209219c(0x8c,&local_3c,&local_30,0xf);
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < 2);
      uVar4 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1;
      uVar4 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      if (2 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
        *(undefined4 *)(param_2 + 0xa8) = 0;
      }
    }
    uVar4 = *(ushort *)(param_2 + 0xa0) + 1;
    if (0x31 < uVar4) {
      uVar4 = 0;
    }
    *(short *)(param_2 + 0xa0) = (short)uVar4;
    if (*(short *)(param_2 + 0xa0) != 0) {
      return;
    }
    uVar4 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar4 - 1;
    if (0 < (int)uVar4) {
      return;
    }
    *(undefined4 *)(param_2 + 0xa8) = 0;
    *(undefined4 *)(param_2 + 0xac) = 0;
    if ((*(ushort *)(param_2 + 2) & 0x800) == 0) {
      return;
    }
    piVar7 = (int *)func_020d22d0();
    uVar4 = (uint)(piVar7 + 2) & 3;
    uVar3 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
    uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar13 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
             *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
    uVar4 = (uint)(piVar7 + 1) & 3;
    uVar19 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar13 * (ulonglong)uVar5;
    uVar12 = (uint)lVar2;
    uVar3 = (uint)(piVar7 + 4) & 3;
    uVar20 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
    uVar15 = uVar20 >> uVar3 * 8 | uVar20 << uVar3 * -8 + 0x20;
    uVar3 = (uint)(piVar7 + 3) & 3;
    uVar16 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
    uVar20 = (uint)(piVar7 + 5) & 3;
    uVar6 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
    *piVar7 = uVar15 + uVar12;
    piVar7[1] = (uVar6 >> uVar20 * 8 | uVar6 << uVar20 * -8 + 0x20) +
                (uVar16 >> uVar3 * 8 | uVar16 << uVar3 * -8 + 0x20) * uVar13 +
                uVar5 * (uVar19 >> uVar4 * 8 | uVar19 << uVar4 * -8 + 0x20) +
                (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar15,uVar12);
    uVar4 = (uint)(piVar7 + 1) & 3;
    uVar3 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    *(int *)(param_2 + 0xa4) =
         (int)((ulonglong)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x19 >> 0x20) + 200;
    return;
  }
  iVar14 = func_02061818();
  uVar4 = uRam02093070;
  if (iVar14 == 2) {
    *(undefined4 *)(param_2 + 0xac) = 1;
    return;
  }
  if ((*(ushort *)(param_2 + 2) & 0x800) != 0) {
    uVar4 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar4 - 1;
    if ((int)uVar4 < 1) {
      *(undefined4 *)(param_2 + 0xa4) = 4;
      *(undefined4 *)(param_2 + 0xac) = 1;
    }
    return;
  }
  uVar1 = *(ushort *)(param_2 + 0x7e);
  uVar3 = *(uint *)(uRam02093070 & 0xfffffffc) >> (uRam02093070 & 3) * 8 |
          *(uint *)(uRam02093070 & 0xfffffffc) << (uRam02093070 & 3) * -8 + 0x20;
  uVar20 = 0;
  if (*(char *)(uVar3 + 0x3d0) != '\0') {
    do {
      uVar19 = (uVar20 & 0xffff) * 0x30 + uVar3 + 0x70;
      uVar16 = uVar19 & 3;
      uVar19 = *(uint *)(uVar19 & 0xfffffffc);
      uVar19 = uVar19 >> uVar16 * 8 | uVar19 << uVar16 * -8 + 0x20;
      bVar11 = false;
      if ((uVar19 < 4) && ((1 << (uVar19 & 0xff) & 0xdU) != 0)) {
        bVar11 = true;
      }
      if (((bVar11) || (uVar20 == (int)*(char *)(uVar3 + 0x62))) &&
         (iVar14 = GetDriverEntry(uVar20 & 0xffff), uVar3 = iVar14 + 0x88U & 3,
         uVar6 = *(uint *)(iVar14 + 0x88U & 0xfffffffc), uVar19 = param_2 + 0xcU & 3,
         uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc), uVar16 = iVar14 + 0x80U & 3,
         uVar13 = *(uint *)(iVar14 + 0x80U & 0xfffffffc),
         iVar10 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
                  (uVar5 >> uVar19 * 8 | uVar5 << uVar19 * -8 + 0x20), uVar3 = param_2 + 4U & 3,
         uVar19 = *(uint *)(param_2 + 4U & 0xfffffffc),
         iVar9 = (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) -
                 (uVar19 >> uVar3 * 8 | uVar19 << uVar3 * -8 + 0x20),
         (int)((ulonglong)((longlong)iVar9 * (longlong)iVar9 + (longlong)iVar10 * (longlong)iVar10)
              >> 0x20) < iRam02093074)) {
        uVar3 = iVar14 + 0x80U & 3;
        uVar15 = *(uint *)(iVar14 + 0x80U & 0xfffffffc);
        uVar19 = param_2 + 4U & 3;
        uVar12 = *(uint *)(param_2 + 4U & 0xfffffffc);
        uVar16 = iVar14 + 0x88U & 3;
        uVar6 = *(uint *)(iVar14 + 0x88U & 0xfffffffc);
        uVar13 = param_2 + 0xcU & 3;
        uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
        iVar14 = FX_Atan2((uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) -
                          (uVar12 >> uVar19 * 8 | uVar12 << uVar19 * -8 + 0x20),
                          (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) -
                          (uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20));
        iVar14 = iVar14 - (uint)uVar1;
        if ((-0x1f41 < iVar14) && (iVar14 < 0x1f41)) {
          bVar11 = true;
          goto LAB_02092cd8;
        }
      }
      uVar3 = uVar4 & 3;
      uVar19 = *(uint *)(uVar4 & 0xfffffffc);
      uVar3 = uVar19 >> uVar3 * 8 | uVar19 << uVar3 * -8 + 0x20;
      uVar20 = uVar20 + 1;
    } while ((int)uVar20 < (int)(uint)*(byte *)(uVar3 + 0x3d0));
  }
  bVar11 = false;
LAB_02092cd8:
  if (bVar11) {
    *(undefined4 *)(param_2 + 0xa4) = 4;
    *(undefined4 *)(param_2 + 0xac) = 1;
  }
  return;
}

