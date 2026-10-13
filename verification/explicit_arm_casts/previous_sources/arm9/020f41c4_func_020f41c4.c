/* Decompiled C draft; module arm9; ROM address 020f41c4. No matching claim. */
#include "types.h"
#include "deps/020f41c4_func_020f41c4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020f41c4(uint param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined2 *puVar16;
  uint uVar17;
  uint uVar19;
  uint uVar21;
  undefined2 *puVar22;
  int *piVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  bool bVar31;
  int local_4c;
  uint uVar11;
  uint uVar18;
  uint uVar20;
  undefined2 *puVar23;
  
  uVar15 = uRam020f45d8;
  uVar10 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar10 = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) + 0x1fc;
  uVar9 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar11 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  uVar10 = uVar11 + 0x590 & 3;
  uVar9 = *(uint *)(uVar11 + 0x590 & 0xfffffffc);
  uVar13 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  uVar10 = (*(uint *)(uRam020f45c8 & 0xfffffffc) >> (uRam020f45c8 & 3) * 8 |
           *(uint *)(uRam020f45c8 & 0xfffffffc) << (uRam020f45c8 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  bVar31 = (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) == 1;
  uVar10 = uVar13;
  if (bVar31) {
    uVar10 = uRam020f45cc;
  }
  uVar9 = *(uint *)(param_1 & 0xfffffffc);
  if (bVar31) {
    piVar24 = (int *)((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                      *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + iRam020f45d0);
  }
  else {
    piVar24 = (int *)((*(uint *)(uRam020f45cc & 0xfffffffc) >> (uRam020f45cc & 3) * 8 |
                      *(uint *)(uRam020f45cc & 0xfffffffc) << (uRam020f45cc & 3) * -8 + 0x20) +
                     iRam020f45d4);
  }
  uVar10 = (uint)(piVar24 + 2) & 3;
  uVar17 = *(uint *)((uint)(piVar24 + 2) & 0xfffffffc);
  uVar18 = uVar17 >> uVar10 * 8 | uVar17 << uVar10 * -8 + 0x20;
  uVar14 = *(uint *)((uint)piVar24 & 0xfffffffc) >> ((uint)piVar24 & 3) * 8 |
           *(uint *)((uint)piVar24 & 0xfffffffc) << ((uint)piVar24 & 3) * -8 + 0x20;
  uVar10 = (uint)(piVar24 + 1) & 3;
  uVar6 = *(uint *)((uint)(piVar24 + 1) & 0xfffffffc);
  lVar4 = (ulonglong)uVar14 * (ulonglong)uVar18;
  uVar25 = (uint)lVar4;
  uVar17 = (uint)(piVar24 + 3) & 3;
  uVar7 = *(uint *)((uint)(piVar24 + 3) & 0xfffffffc);
  uVar21 = (uint)(piVar24 + 4) & 3;
  uVar19 = *(uint *)((uint)(piVar24 + 4) & 0xfffffffc);
  uVar20 = uVar19 >> uVar21 * 8 | uVar19 << uVar21 * -8 + 0x20;
  uVar21 = (uint)(piVar24 + 5) & 3;
  uVar19 = *(uint *)((uint)(piVar24 + 5) & 0xfffffffc);
  *piVar24 = uVar20 + uVar25;
  piVar24[1] = (uVar19 >> uVar21 * 8 | uVar19 << uVar21 * -8 + 0x20) +
               (uVar7 >> uVar17 * 8 | uVar7 << uVar17 * -8 + 0x20) * uVar14 +
               uVar18 * (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) +
               (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar20,uVar25);
  uVar10 = (uVar9 >> (param_1 & 3) * 8 | uVar9 << (param_1 & 3) * -8 + 0x20) * 0x1c +
           (*(uint *)(uRam020f45dc & 0xfffffffc) >> (uRam020f45dc & 3) * 8 |
           *(uint *)(uRam020f45dc & 0xfffffffc) << (uRam020f45dc & 3) * -8 + 0x20) + 8;
  uVar9 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar17 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  uVar10 = uVar15 & 3;
  uVar9 = *(uint *)(uVar15 & 0xfffffffc);
  uVar10 = uVar17 * 0xa8 + (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) + 0x80;
  uVar9 = uVar10 & 3;
  uVar15 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = (uint)(piVar24 + 1) & 3;
  uVar21 = *(uint *)((uint)(piVar24 + 1) & 0xfffffffc);
  uVar21 = uVar21 >> uVar10 * 8 | uVar21 << uVar10 * -8 + 0x20;
  uVar10 = uVar21 & 0xffff0000;
  bVar31 = uVar15 >> uVar9 * 8 != 0;
  bVar5 = uVar15 << uVar9 * -8 + 0x20 != 0;
  iVar8 = (int)(uVar21 >> 0x10) >> 4;
  if (bVar31 || bVar5) {
    uVar10 = 0x2000;
  }
  if (!bVar31 && !bVar5) {
    uVar10 = 0x1800;
  }
  lVar4 = (longlong)(int)uVar10 * (longlong)(int)*(short *)(iRam020f45e0 + iVar8 * 4);
  lVar3 = (longlong)(int)uVar10 * (longlong)(int)*(short *)(iRam020f45e0 + (iVar8 * 2 + 1) * 2);
  uVar10 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  uVar15 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
  uVar9 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  func_020f1048(uVar17 * 0x44 +
                (*(uint *)(uRam020f45e4 & 0xfffffffc) >> (uRam020f45e4 & 3) * 8 |
                *(uint *)(uRam020f45e4 & 0xfffffffc) << (uRam020f45e4 & 3) * -8 + 0x20),uVar10,
                param_1 + 0x14,*(undefined2 *)(uVar11 + 0x74),uVar11 + 0x98);
  local_4c = 0;
  if (0 < (int)uVar10) {
    iVar8 = (uVar10 - 1) * 0x18 + iRam020f45e8;
    do {
      uVar17 = (uint)(piVar24 + 2) & 3;
      uVar21 = *(uint *)((uint)(piVar24 + 2) & 0xfffffffc);
      uVar28 = uVar21 >> uVar17 * 8 | uVar21 << uVar17 * -8 + 0x20;
      uVar17 = iVar8 + local_4c * 8;
      uVar21 = uVar17 & 3;
      uVar30 = *(uint *)(uVar17 & 0xfffffffc);
      uVar26 = *(uint *)((uint)piVar24 & 0xfffffffc) >> ((uint)piVar24 & 3) * 8 |
               *(uint *)((uint)piVar24 & 0xfffffffc) << ((uint)piVar24 & 3) * -8 + 0x20;
      uVar6 = (uint)(piVar24 + 1) & 3;
      uVar25 = *(uint *)((uint)(piVar24 + 1) & 0xfffffffc);
      uVar7 = (uint)(piVar24 + 3) & 3;
      uVar27 = *(uint *)((uint)(piVar24 + 3) & 0xfffffffc);
      lVar4 = (ulonglong)uVar26 * (ulonglong)uVar28;
      uVar29 = (uint)lVar4;
      uVar17 = iVar8 + local_4c * 8 + 4;
      uVar19 = uVar17 & 3;
      uVar14 = *(uint *)(uVar17 & 0xfffffffc);
      uVar17 = (uint)(piVar24 + 4) & 3;
      uVar18 = *(uint *)((uint)(piVar24 + 4) & 0xfffffffc);
      uVar20 = uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20;
      uVar17 = (uint)(piVar24 + 5) & 3;
      uVar18 = *(uint *)((uint)(piVar24 + 5) & 0xfffffffc);
      *piVar24 = uVar20 + uVar29;
      piVar24[1] = (uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20) +
                   (uVar27 >> uVar7 * 8 | uVar27 << uVar7 * -8 + 0x20) * uVar26 +
                   uVar28 * (uVar25 >> uVar6 * 8 | uVar25 << uVar6 * -8 + 0x20) +
                   (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar20,uVar29);
      uVar17 = (uint)(piVar24 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar24 + 1) & 0xfffffffc);
      uVar26 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
      uVar27 = *(uint *)((uint)piVar24 & 0xfffffffc) >> ((uint)piVar24 & 3) * 8 |
               *(uint *)((uint)piVar24 & 0xfffffffc) << ((uint)piVar24 & 3) * -8 + 0x20;
      lVar4 = (longlong)(int)(uVar30 >> uVar21 * 8 | uVar30 << uVar21 * -8 + 0x20) *
              (longlong)((int)((ulonglong)uRam020f45ec * (ulonglong)uVar26 >> 0x20) + 0x1000);
      uVar7 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      uVar17 = (uint)(piVar24 + 2) & 3;
      uVar21 = *(uint *)((uint)(piVar24 + 2) & 0xfffffffc);
      uVar18 = uVar21 >> uVar17 * 8 | uVar21 << uVar17 * -8 + 0x20;
      lVar4 = (ulonglong)uVar27 * (ulonglong)uVar18;
      uVar28 = (uint)lVar4;
      uVar17 = (uint)(piVar24 + 3) & 3;
      uVar6 = *(uint *)((uint)(piVar24 + 3) & 0xfffffffc);
      uVar21 = (uint)(piVar24 + 4) & 3;
      uVar20 = *(uint *)((uint)(piVar24 + 4) & 0xfffffffc);
      uVar25 = uVar20 >> uVar21 * 8 | uVar20 << uVar21 * -8 + 0x20;
      uVar21 = (uint)(piVar24 + 5) & 3;
      uVar20 = *(uint *)((uint)(piVar24 + 5) & 0xfffffffc);
      *piVar24 = uVar25 + uVar28;
      piVar24[1] = (uVar20 >> uVar21 * 8 | uVar20 << uVar21 * -8 + 0x20) +
                   (uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) * uVar27 +
                   uVar18 * uVar26 + (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar25,uVar28);
      uVar21 = (uint)(piVar24 + 1) & 3;
      uVar20 = *(uint *)((uint)(piVar24 + 1) & 0xfffffffc);
      uVar17 = param_1 + local_4c * 4 + 0x14;
      uVar6 = uVar17 & 3;
      uVar17 = *(uint *)(uVar17 & 0xfffffffc);
      uVar6 = uVar17 >> uVar6 * 8 | uVar17 << uVar6 * -8 + 0x20;
      uVar17 = uVar11 + 0x168 & 3;
      uVar18 = *(uint *)(uVar11 + 0x168 & 0xfffffffc);
      lVar4 = (longlong)(int)(uVar14 >> uVar19 * 8 | uVar14 << uVar19 * -8 + 0x20) *
              (longlong)
              ((int)((ulonglong)uRam020f45ec *
                     (ulonglong)(uVar20 >> uVar21 * 8 | uVar20 << uVar21 * -8 + 0x20) >> 0x20) +
              0x1000);
      uVar19 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      uVar21 = ((uint)((ulonglong)uVar9 * (ulonglong)uVar7) >> 0xc |
               (((int)uVar7 >> 0x1f) * uVar9 +
               uVar7 * ((int)uVar9 >> 0x1f) + (int)((ulonglong)uVar9 * (ulonglong)uVar7 >> 0x20)) *
               0x100000) -
               ((uint)((ulonglong)uVar15 * (ulonglong)uVar19) >> 0xc |
               (((int)uVar19 >> 0x1f) * uVar15 +
               uVar19 * ((int)uVar15 >> 0x1f) + (int)((ulonglong)uVar15 * (ulonglong)uVar19 >> 0x20)
               ) * 0x100000);
      lVar4 = (longlong)(int)(uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20) *
              (longlong)(int)uVar21;
      *(uint *)(uVar6 + 0x5c) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      uVar17 = uVar11 + 0x16c & 3;
      uVar7 = *(uint *)(uVar11 + 0x16c & 0xfffffffc);
      lVar4 = (longlong)(int)(uVar7 >> uVar17 * 8 | uVar7 << uVar17 * -8 + 0x20) *
              (longlong)(int)uVar21;
      *(uint *)(uVar6 + 0x60) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      uVar17 = uVar11 + 0x170 & 3;
      uVar7 = *(uint *)(uVar11 + 0x170 & 0xfffffffc);
      lVar4 = (longlong)(int)(uVar7 >> uVar17 * 8 | uVar7 << uVar17 * -8 + 0x20) *
              (longlong)(int)uVar21;
      *(uint *)(uVar6 + 100) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      VecFx32_AddScale1(((uint)((ulonglong)uVar9 * (ulonglong)uVar19) >> 0xc |
                        (((int)uVar19 >> 0x1f) * uVar9 +
                        uVar19 * ((int)uVar9 >> 0x1f) +
                        (int)((ulonglong)uVar9 * (ulonglong)uVar19 >> 0x20)) * 0x100000) +
                        ((uint)((ulonglong)uVar15 * (ulonglong)uVar21) >> 0xc |
                        (((int)uVar21 >> 0x1f) * uVar15 +
                        uVar21 * ((int)uVar15 >> 0x1f) +
                        (int)((ulonglong)uVar15 * (ulonglong)uVar21 >> 0x20)) * 0x100000),
                        uVar11 + 0x150,uVar6 + 0x5c,uVar6 + 0x5c);
      puVar16 = (undefined2 *)(uVar6 + 0x7c);
      *(undefined4 *)(uVar6 + 0x68) = 0xcd;
      *(undefined4 *)(uVar6 + 0x6c) = 0xcd;
      *(undefined4 *)(uVar6 + 0x70) = 0xcd;
      iVar12 = 4;
      puVar22 = (undefined2 *)(uVar13 + 0x40);
      do {
        puVar23 = puVar22 + 1;
        uVar1 = *puVar22;
        puVar22 = puVar22 + 2;
        uVar2 = *puVar23;
        iVar12 = iVar12 + -1;
        puVar23 = puVar16 + 1;
        *puVar16 = uVar1;
        puVar16 = puVar16 + 2;
        *puVar23 = uVar2;
      } while (iVar12 != 0);
      local_4c = local_4c + 1;
      *puVar16 = *puVar22;
    } while (local_4c < (int)uVar10);
    return;
  }
  return;
}

