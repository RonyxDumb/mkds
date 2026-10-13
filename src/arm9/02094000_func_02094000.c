/* Decompiled C draft; module arm9; ROM address 02094000. No matching claim. */
#include "types.h"
#include "deps/02094000_func_02094000.h"

void func_02094000(undefined4 *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  uint uVar17;
  uint uVar19;
  uint uVar20;
  uint uVar15;
  uint uVar18;
  
  func_02100138(uRam0209469c);
  iVar3 = func_0209bbfc();
  if (iVar3 != 0) {
    *(undefined2 *)(iVar3 + 0xac) = 0;
    uVar7 = param_1[1];
    uVar9 = param_1[2];
    *(undefined4 *)(iVar3 + 0xa0) = *param_1;
    *(undefined4 *)(iVar3 + 0xa4) = uVar7;
    *(undefined4 *)(iVar3 + 0xa8) = uVar9;
    iVar4 = func_02061818();
    if (iVar4 == 0) {
      iVar4 = GetGlobalHD5();
      uVar10 = *(uint *)(uRam020946a0 & 0xfffffffc) >> (uRam020946a0 & 3) * 8 |
               *(uint *)(uRam020946a0 & 0xfffffffc) << (uRam020946a0 & 3) * -8 + 0x20;
      iVar8 = uVar10 + iRam020946a4;
      uVar6 = iVar8 + 8U & 3;
      uVar14 = *(uint *)(iVar8 + 8U & 0xfffffffc);
      uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar13 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar8 + 4U & 3;
      uVar11 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar13 * (ulonglong)uVar15;
      uVar16 = (uint)lVar2;
      uVar14 = iVar8 + 0xcU & 3;
      uVar12 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
      uVar5 = iVar8 + 0x10U & 3;
      uVar17 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
      uVar18 = uVar17 >> uVar5 * 8 | uVar17 << uVar5 * -8 + 0x20;
      uVar5 = iVar8 + 0x14U & 3;
      uVar17 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar18 + uVar16;
      *(uint *)(iVar8 + 4) =
           (uVar17 >> uVar5 * 8 | uVar17 << uVar5 * -8 + 0x20) +
           (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) * uVar13 +
           uVar15 * (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar16);
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar17 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar8 + 8U & 3;
      uVar14 = *(uint *)(iVar8 + 8U & 0xfffffffc);
      uVar11 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar8 + 4U & 3;
      uVar14 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      uVar18 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      lVar2 = (ulonglong)uVar17 * (ulonglong)uVar11;
      uVar12 = (uint)lVar2;
      uVar6 = iVar8 + 0x10U & 3;
      uVar14 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
      uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar8 + 0xcU & 3;
      uVar13 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
      uVar14 = iVar8 + 0x14U & 3;
      uVar5 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar15 + uVar12;
      *(uint *)(iVar8 + 4) =
           (uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20) +
           (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) * uVar17 +
           uVar11 * uVar18 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar15,uVar12);
      uVar6 = iVar8 + 4U & 3;
      uVar14 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      uVar19 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar13 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar8 + 8U & 3;
      uVar14 = *(uint *)(iVar8 + 8U & 0xfffffffc);
      uVar5 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar8 + 0xcU & 3;
      uVar15 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
      lVar2 = (ulonglong)uVar13 * (ulonglong)uVar5;
      uVar17 = (uint)lVar2;
      uVar14 = iVar8 + 0x10U & 3;
      uVar11 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
      uVar12 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
      uVar14 = iVar8 + 0x14U & 3;
      uVar11 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar12 + uVar17;
      *(uint *)(iVar8 + 4) =
           (uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) +
           (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) * uVar13 +
           uVar5 * uVar19 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar12,uVar17);
      uVar6 = iVar8 + 4U & 3;
      uVar17 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      uVar14 = iVar4 + 0x20U & 3;
      uVar13 = *(uint *)(iVar4 + 0x20U & 0xfffffffc);
      uVar1 = (ulonglong)uRam020946a8;
      uVar5 = iVar4 + 0x18U & 3;
      uVar16 = *(uint *)(iVar4 + 0x18U & 0xfffffffc);
      uVar10 = iVar4 + 0x2cU & 3;
      uVar12 = *(uint *)(iVar4 + 0x2cU & 0xfffffffc);
      uVar11 = iVar4 + 0x24U & 3;
      uVar15 = *(uint *)(iVar4 + 0x24U & 0xfffffffc);
      iVar4 = FX_Atan2((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) -
                       (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20),
                       (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) -
                       (uVar15 >> uVar11 * 8 | uVar15 << uVar11 * -8 + 0x20));
      uVar16 = *(uint *)(uRam020946a0 & 0xfffffffc) >> (uRam020946a0 & 3) * 8 |
               *(uint *)(uRam020946a0 & 0xfffffffc) << (uRam020946a0 & 3) * -8 + 0x20;
      iVar8 = iVar4 + ((uint)(uVar1 * (uVar17 >> uVar6 * 8 | uVar17 << uVar6 * -8 + 0x20) >> 0x20) &
                      0xffff) + iRam020946ac;
      uVar6 = uVar16 + 0x498 & 3;
      uVar14 = *(uint *)(uVar16 + 0x498 & 0xfffffffc);
      uVar11 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      iVar4 = uVar16 + iRam020946a4;
      uVar6 = iVar4 + 8U & 3;
      uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
      uVar12 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 4U & 3;
      uVar10 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar11 * (ulonglong)uVar12;
      uVar13 = (uint)lVar2;
      uVar14 = iVar4 + 0xcU & 3;
      uVar20 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
      uVar5 = iVar4 + 0x10U & 3;
      uVar15 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
      uVar17 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
      uVar5 = iVar4 + 0x14U & 3;
      uVar15 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(uVar16 + 0x498) = uVar17 + uVar13;
      *(uint *)(iVar4 + 4) =
           (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) +
           (uVar20 >> uVar14 * 8 | uVar20 << uVar14 * -8 + 0x20) * uVar11 +
           uVar12 * (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar13);
      uVar6 = iVar4 + 4U & 3;
      uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      *(ushort *)(iVar3 + 0xbc) =
           (ushort)((uVar14 >> uVar6 * 8) >> 0x10) | (ushort)((uVar14 << uVar6 * -8 + 0x20) >> 0x10)
      ;
      *(int *)(iVar3 + 200) = iVar8;
      *(int *)(iVar3 + 0xcc) = (short)(ushort)(uVar19 >> 0x14) + 0x1000;
      *(undefined4 *)(iVar3 + 0xd0) = 0;
      *(int *)(iVar3 + 0xd4) = (int)((ulonglong)uVar18 * 0x30 >> 0x20) + 0x60;
      *(undefined4 *)(iVar3 + 0xd8) = 0;
    }
    else {
      uVar10 = *(uint *)(uRam020946a0 & 0xfffffffc) >> (uRam020946a0 & 3) * 8 |
               *(uint *)(uRam020946a0 & 0xfffffffc) << (uRam020946a0 & 3) * -8 + 0x20;
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      iVar4 = uVar10 + iRam020946a4;
      uVar6 = iVar4 + 8U & 3;
      uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
      uVar17 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 4U & 3;
      uVar11 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar15 * (ulonglong)uVar17;
      uVar18 = (uint)lVar2;
      uVar14 = iVar4 + 0xcU & 3;
      uVar12 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
      uVar5 = iVar4 + 0x10U & 3;
      uVar13 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
      uVar16 = uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20;
      uVar5 = iVar4 + 0x14U & 3;
      uVar13 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar16 + uVar18;
      *(uint *)(iVar4 + 4) =
           (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) +
           (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) * uVar15 +
           uVar17 * (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar18);
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar16 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 8U & 3;
      uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
      uVar11 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 4U & 3;
      uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      uVar5 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      lVar2 = (ulonglong)uVar16 * (ulonglong)uVar11;
      uVar13 = (uint)lVar2;
      uVar6 = iVar4 + 0xcU & 3;
      uVar12 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
      uVar14 = iVar4 + 0x10U & 3;
      uVar15 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
      uVar17 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20;
      uVar14 = iVar4 + 0x14U & 3;
      uVar15 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar17 + uVar13;
      *(uint *)(iVar4 + 4) =
           (uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) +
           (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * uVar16 +
           uVar11 * uVar5 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar13);
      uVar6 = iVar4 + 4U & 3;
      uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      uVar18 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar16 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 8U & 3;
      uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
      uVar12 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 0xcU & 3;
      uVar11 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
      lVar2 = (ulonglong)uVar16 * (ulonglong)uVar12;
      uVar13 = (uint)lVar2;
      uVar14 = iVar4 + 0x10U & 3;
      uVar15 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
      uVar17 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20;
      uVar14 = iVar4 + 0x14U & 3;
      uVar15 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar17 + uVar13;
      *(uint *)(iVar4 + 4) =
           (uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) +
           (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * uVar16 +
           uVar12 * uVar18 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar13);
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar16 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 8U & 3;
      uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
      uVar12 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 4U & 3;
      uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      uVar19 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      lVar2 = (ulonglong)uVar16 * (ulonglong)uVar12;
      uVar13 = (uint)lVar2;
      uVar6 = iVar4 + 0xcU & 3;
      uVar11 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
      uVar14 = iVar4 + 0x10U & 3;
      uVar15 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
      uVar17 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20;
      uVar14 = iVar4 + 0x14U & 3;
      uVar15 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar17 + uVar13;
      *(uint *)(iVar4 + 4) =
           (uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) +
           (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * uVar16 +
           uVar12 * uVar19 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar13);
      uVar6 = iVar4 + 4U & 3;
      uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      *(ushort *)(iVar3 + 0xbc) =
           (ushort)((uVar14 >> uVar6 * 8) >> 0x10) | (ushort)((uVar14 << uVar6 * -8 + 0x20) >> 0x10)
      ;
      *(uint *)(iVar3 + 200) = uVar19 >> 0x10;
      *(int *)(iVar3 + 0xcc) = (short)(ushort)(uVar18 >> 0x14) + 0x1000;
      *(undefined4 *)(iVar3 + 0xd0) = 0;
      *(int *)(iVar3 + 0xd4) = (int)((ulonglong)uVar5 * 0x30 >> 0x20) + 0x60;
      *(undefined4 *)(iVar3 + 0xd8) = 0;
    }
    uVar18 = *(uint *)(uRam020946a0 & 0xfffffffc) >> (uRam020946a0 & 3) * 8 |
             *(uint *)(uRam020946a0 & 0xfffffffc) << (uRam020946a0 & 3) * -8 + 0x20;
    uVar6 = uVar18 + 0x498 & 3;
    uVar14 = *(uint *)(uVar18 + 0x498 & 0xfffffffc);
    uVar13 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    iVar4 = uVar18 + iRam020946a4;
    uVar6 = iVar4 + 8U & 3;
    uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 4U & 3;
    uVar10 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    lVar2 = (ulonglong)uVar13 * (ulonglong)uVar15;
    uVar16 = (uint)lVar2;
    uVar14 = iVar4 + 0xcU & 3;
    uVar11 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar5 = iVar4 + 0x10U & 3;
    uVar12 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar17 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
    uVar5 = iVar4 + 0x14U & 3;
    uVar12 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar18 + 0x498) = uVar17 + uVar16;
    *(uint *)(iVar4 + 4) =
         (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) +
         (uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) * uVar13 +
         uVar15 * (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
         (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar16);
    uVar6 = uVar18 + 0x498 & 3;
    uVar14 = *(uint *)(uVar18 + 0x498 & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 8U & 3;
    uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar5 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 4U & 3;
    uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    uVar17 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    lVar2 = (ulonglong)uVar15 * (ulonglong)uVar5;
    uVar11 = (uint)lVar2;
    uVar6 = iVar4 + 0xcU & 3;
    uVar10 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar14 = iVar4 + 0x10U & 3;
    uVar12 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar13 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
    uVar14 = iVar4 + 0x14U & 3;
    uVar12 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar18 + 0x498) = uVar13 + uVar11;
    *(uint *)(iVar4 + 4) =
         (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) +
         (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar15 +
         uVar5 * uVar17 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar11);
    uVar6 = iVar4 + 4U & 3;
    uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = uVar18 + 0x498 & 3;
    uVar14 = *(uint *)(uVar18 + 0x498 & 0xfffffffc);
    uVar13 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 8U & 3;
    uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar5 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    lVar2 = (ulonglong)uVar13 * (ulonglong)uVar5;
    uVar10 = (uint)lVar2;
    uVar6 = iVar4 + 0xcU & 3;
    uVar16 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar14 = iVar4 + 0x10U & 3;
    uVar11 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar12 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
    uVar14 = iVar4 + 0x14U & 3;
    uVar11 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar18 + 0x498) = uVar12 + uVar10;
    *(uint *)(iVar4 + 4) =
         (uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) +
         (uVar16 >> uVar6 * 8 | uVar16 << uVar6 * -8 + 0x20) * uVar13 +
         uVar5 * uVar15 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar12,uVar10);
    uVar6 = iVar4 + 4U & 3;
    uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    *(undefined2 *)(iVar3 + 0xdc) = 0;
    *(int *)(iVar3 + 0xe8) =
         (int)((ulonglong)(uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) * 0x19000 >> 0x20) +
         0x19000;
    iVar4 = iRam020946a4;
    *(int *)(iVar3 + 0xec) = (int)((ulonglong)uVar15 * 0xa000 >> 0x20) + 0xa000;
    *(undefined4 *)(iVar3 + 0xf0) = 0;
    *(uint *)(iVar3 + 0xf4) = (uVar17 >> 0x19) + 0x100;
    uVar14 = uRam020946a0;
    *(undefined4 *)(iVar3 + 0xf8) = 0;
    uVar6 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    uVar10 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    iVar4 = uVar10 + iVar4;
    uVar6 = iVar4 + 8U & 3;
    uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = uVar10 + 0x498 & 3;
    uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
    uVar12 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 4U & 3;
    uVar11 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    lVar2 = (ulonglong)uVar12 * (ulonglong)uVar15;
    uVar17 = (uint)lVar2;
    uVar14 = iVar4 + 0xcU & 3;
    uVar13 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar5 = iVar4 + 0x10U & 3;
    uVar16 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar18 = uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20;
    uVar5 = iVar4 + 0x14U & 3;
    uVar16 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar10 + 0x498) = uVar18 + uVar17;
    *(uint *)(iVar4 + 4) =
         (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) +
         (uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) * uVar12 +
         uVar15 * (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
         (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar17);
    uVar6 = iVar4 + 4U & 3;
    uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    *(int *)(iVar3 + 0x10c) =
         (int)((ulonglong)(uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) * 0x3c000 >> 0x20) +
         0x3c000;
    uVar13 = *(uint *)(uRam020946a0 & 0xfffffffc) >> (uRam020946a0 & 3) * 8 |
             *(uint *)(uRam020946a0 & 0xfffffffc) << (uRam020946a0 & 3) * -8 + 0x20;
    uVar6 = uVar13 + 0x498 & 3;
    uVar14 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
    uVar11 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    iVar4 = uVar13 + iRam020946a4;
    uVar6 = iVar4 + 8U & 3;
    uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 4U & 3;
    uVar10 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    lVar2 = (ulonglong)uVar11 * (ulonglong)uVar15;
    uVar17 = (uint)lVar2;
    uVar14 = iVar4 + 0xcU & 3;
    uVar12 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar5 = iVar4 + 0x10U & 3;
    uVar16 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar18 = uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20;
    uVar5 = iVar4 + 0x14U & 3;
    uVar16 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar13 + 0x498) = uVar18 + uVar17;
    *(uint *)(iVar4 + 4) =
         (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) +
         (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) * uVar11 +
         uVar15 * (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
         (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar17);
    uVar6 = iVar4 + 4U & 3;
    uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    uVar11 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = uVar13 + 0x498 & 3;
    uVar14 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
    uVar10 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 8U & 3;
    uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 0xcU & 3;
    uVar12 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    lVar2 = (ulonglong)uVar10 * (ulonglong)uVar15;
    uVar17 = (uint)lVar2;
    uVar14 = iVar4 + 0x10U & 3;
    uVar5 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar5 = uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20;
    uVar14 = iVar4 + 0x14U & 3;
    uVar16 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar13 + 0x498) = uVar5 + uVar17;
    *(uint *)(iVar4 + 4) =
         (uVar16 >> uVar14 * 8 | uVar16 << uVar14 * -8 + 0x20) +
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * uVar10 +
         uVar15 * uVar11 + (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar5,uVar17);
    uVar6 = iVar4 + 4U & 3;
    uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    *(undefined4 *)(iVar3 + 0xfc) = 0;
    *(uint *)(iVar3 + 0x100) = ((uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) >> 0x17) + 0x400
    ;
    *(undefined4 *)(iVar3 + 0x104) = 0x2000;
    *(int *)(iVar3 + 0x108) = (int)((ulonglong)uVar11 * 0xc000 >> 0x20) + 0xe000;
    iVar8 = func_02061818();
    uVar7 = uRam020946b0;
    iVar4 = iRam020946a4;
    uVar6 = uRam020946a0;
    if (iVar8 == 2) {
      *(undefined4 *)(iVar3 + 0xb4) = 0;
      *(undefined4 *)(iVar3 + 0xb8) = uVar7;
      *(undefined4 *)(iVar3 + 0x110) = 0;
    }
    else {
      uVar11 = *(uint *)(uRam020946a0 & 0xfffffffc) >> (uRam020946a0 & 3) * 8 |
               *(uint *)(uRam020946a0 & 0xfffffffc) << (uRam020946a0 & 3) * -8 + 0x20;
      iVar8 = uVar11 + iRam020946a4;
      uVar14 = iVar8 + 8U & 3;
      uVar5 = *(uint *)(iVar8 + 8U & 0xfffffffc);
      uVar16 = uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20;
      uVar14 = uVar11 + 0x498 & 3;
      uVar5 = *(uint *)(uVar11 + 0x498 & 0xfffffffc);
      uVar17 = uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20;
      uVar14 = iVar8 + 4U & 3;
      uVar12 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar17 * (ulonglong)uVar16;
      uVar19 = (uint)lVar2;
      uVar5 = iVar8 + 0xcU & 3;
      uVar13 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
      uVar10 = iVar8 + 0x10U & 3;
      uVar15 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
      uVar18 = uVar15 >> uVar10 * 8 | uVar15 << uVar10 * -8 + 0x20;
      uVar10 = iVar8 + 0x14U & 3;
      uVar15 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
      *(uint *)(uVar11 + 0x498) = uVar18 + uVar19;
      *(uint *)(iVar8 + 4) =
           (uVar15 >> uVar10 * 8 | uVar15 << uVar10 * -8 + 0x20) +
           (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) * uVar17 +
           uVar16 * (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar19);
      uVar14 = iVar8 + 4U & 3;
      uVar5 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      *(int *)(iVar3 + 0xb4) =
           (int)((ulonglong)(uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20) * 0x4b >> 0x20);
      uVar14 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar10 = uVar6 >> uVar14 * 8 | uVar6 << uVar14 * -8 + 0x20;
      iVar4 = uVar10 + iVar4;
      uVar6 = iVar4 + 8U & 3;
      uVar14 = *(uint *)(iVar4 + 8U & 0xfffffffc);
      uVar17 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = uVar10 + 0x498 & 3;
      uVar14 = *(uint *)(uVar10 + 0x498 & 0xfffffffc);
      uVar13 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 4U & 3;
      uVar11 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar13 * (ulonglong)uVar17;
      uVar18 = (uint)lVar2;
      uVar14 = iVar4 + 0xcU & 3;
      uVar12 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
      uVar5 = iVar4 + 0x10U & 3;
      uVar15 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
      uVar16 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
      uVar5 = iVar4 + 0x14U & 3;
      uVar15 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x498) = uVar16 + uVar18;
      *(uint *)(iVar4 + 4) =
           (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) +
           (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) * uVar13 +
           uVar17 * (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar18);
      uVar6 = iVar4 + 4U & 3;
      uVar14 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      *(int *)(iVar3 + 0xb8) =
           (int)((ulonglong)(uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) * 0x96 >> 0x20) +
           300;
      *(undefined4 *)(iVar3 + 0x110) = 1;
    }
    *piRam020946b4 =
         (*(uint *)((uint)piRam020946b4 & 0xfffffffc) >> ((uint)piRam020946b4 & 3) * 8 |
         *(uint *)((uint)piRam020946b4 & 0xfffffffc) << ((uint)piRam020946b4 & 3) * -8 + 0x20) + 1;
    return;
  }
  return;
}

