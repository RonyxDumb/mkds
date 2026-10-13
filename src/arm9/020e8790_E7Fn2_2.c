/* Decompiled C draft; module arm9; ROM address 020e8790. No matching claim. */
#include "types.h"
#include "deps/020e8790_E7Fn2_2.h"

void E7Fn2_2(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  undefined2 *puVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar19;
  undefined4 *puVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar18;
  
  puVar4 = puRam020e89f8;
  puVar3 = puRam020e89f4;
  puVar2 = puRam020e89f0;
  puVar1 = puRam020e89ec;
  puVar20 = puRam020e89e8;
  *puRam020e89e4 = 2;
  *puVar20 = 1;
  *puVar1 = 0;
  *puVar2 = 0;
  *puVar3 = 0;
  *puVar4 = 0;
  uVar18 = iRam020e89fc + 0x20U & 3;
  uVar17 = *(uint *)(iRam020e89fc + 0x20U & 0xfffffffc);
  uVar18 = uVar17 >> uVar18 * 8 | uVar17 << uVar18 * -8 + 0x20;
  if (uVar18 != 0) {
    *(undefined4 *)(uVar18 + 0xc) = 0;
    uVar17 = uVar18 + 0x1c & 3;
    uVar16 = *(uint *)(uVar18 + 0x1c & 0xfffffffc);
    uVar23 = uVar18 + 0xc & 3;
    uVar19 = *(uint *)(uVar18 + 0xc & 0xfffffffc);
    uVar18 = (uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20) +
             (uint)*(ushort *)(uVar18 + 0x1a) * 4;
    uVar17 = uVar18 & 3;
    uVar18 = *(uint *)(uVar18 & 0xfffffffc);
    *(uint *)(uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20) =
         uVar19 >> uVar23 * 8 | uVar19 << uVar23 * -8 + 0x20;
  }
  uVar18 = iRam020e8a00 +
           (*(uint *)((uint)puRam020e89e4 & 0xfffffffc) >> ((uint)puRam020e89e4 & 3) * 8 |
           *(uint *)((uint)puRam020e89e4 & 0xfffffffc) << ((uint)puRam020e89e4 & 3) * -8 + 0x20) *
           0x10;
  uVar17 = uVar18 & 3;
  uVar18 = *(uint *)(uVar18 & 0xfffffffc);
  uVar18 = uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20;
  if (uVar18 != 0) {
    *(undefined4 *)(uVar18 + 0xc) = 0;
    uVar17 = uVar18 + 0x1c & 3;
    uVar16 = *(uint *)(uVar18 + 0x1c & 0xfffffffc);
    uVar23 = uVar18 + 0xc & 3;
    uVar19 = *(uint *)(uVar18 + 0xc & 0xfffffffc);
    uVar18 = (uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20) +
             (uint)*(ushort *)(uVar18 + 0x1a) * 4;
    uVar17 = uVar18 & 3;
    uVar18 = *(uint *)(uVar18 & 0xfffffffc);
    *(uint *)(uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20) =
         uVar19 >> uVar23 * 8 | uVar19 << uVar23 * -8 + 0x20;
  }
  uVar8 = uRam020e8a18;
  uVar7 = uRam020e8a14;
  uVar6 = uRam020e8a10;
  uVar5 = uRam020e8a0c;
  puVar20 = puRam020e8a08;
  *puRam020e8a08 = uRam020e8a04;
  puVar20[1] = uVar5;
  puVar20[2] = uVar6;
  puVar20[3] = uVar7;
  func_020d7d18(uVar8,0,puVar20,0x1ec);
  puVar20 = puRam020e8a28;
  piVar9 = piRam020e8a24;
  uVar23 = *(uint *)(uRam020e8a1c & 0xfffffffc) >> (uRam020e8a1c & 3) * 8 |
           *(uint *)(uRam020e8a1c & 0xfffffffc) << (uRam020e8a1c & 3) * -8 + 0x20;
  uVar17 = (uint)*psRam020e8a20;
  uVar18 = uRam020e8a1c + 8 & 3;
  uVar16 = *(uint *)(uRam020e8a1c + 8 & 0xfffffffc);
  uVar16 = uVar16 >> uVar18 * 8 | uVar16 << uVar18 * -8 + 0x20;
  uVar18 = (uint)psRam020e8a20[1];
  iVar15 = ((uint)((longlong)(int)uVar16 * (longlong)(int)uVar18) >> 0xc |
           (int)((ulonglong)((longlong)(int)uVar16 * (longlong)(int)uVar18) >> 0x20) << 0x14) -
           ((uint)((longlong)(int)uVar23 * (longlong)(int)uVar17) >> 0xc |
           (int)((ulonglong)((longlong)(int)uVar23 * (longlong)(int)uVar17) >> 0x20) << 0x14);
  *puRam020e8a28 = 0x8000;
  if (0 < iVar15) {
    puVar20 = (undefined4 *)(iVar15 * 3);
  }
  piVar9[2] = iVar15;
  if (0 < iVar15) {
    piVar9[2] = (int)puVar20;
  }
  *puRam020e8a2c = 0;
  uVar5 = uRam020e8a30;
  piVar9 = piRam020e8a24;
  uVar19 = uRam020e8a1c + 4 & 3;
  uVar22 = *(uint *)(uRam020e8a1c + 4 & 0xfffffffc);
  *piRam020e8a24 =
       ((uint)((ulonglong)uVar17 * (ulonglong)uVar16) >> 0xc |
       (((int)uVar16 >> 0x1f) * uVar17 +
       uVar16 * ((int)uVar17 >> 0x1f) + (int)((ulonglong)uVar17 * (ulonglong)uVar16 >> 0x20)) *
       0x100000) +
       ((uint)((ulonglong)uVar18 * (ulonglong)uVar23) >> 0xc |
       (((int)uVar23 >> 0x1f) * uVar18 +
       uVar23 * ((int)uVar18 >> 0x1f) + (int)((ulonglong)uVar18 * (ulonglong)uVar23 >> 0x20)) *
       0x100000);
  piVar9[1] = uVar22 >> uVar19 * 8 | uVar22 << uVar19 * -8 + 0x20;
  func_02147288((uint)(uintptr_t)(piVar9),uVar5,piVar9);
  piVar9 = piRam020e8a34;
  iVar15 = piRam020e8a24[1];
  iVar21 = piRam020e8a24[2];
  *piRam020e8a34 = *piRam020e8a24;
  piVar9[1] = iVar15;
  piVar9[2] = iVar21;
  piVar10 = piRam020e8a38;
  iVar15 = piVar9[1];
  iVar21 = piVar9[2];
  *piRam020e8a38 = *piVar9;
  piVar10[1] = iVar15;
  piVar10[2] = iVar21;
  puVar2 = puRam020e8a44;
  puVar1 = puRam020e8a40;
  puVar20 = puRam020e8a3c;
  *puRam020e8a3c = 0;
  puVar20[1] = 0;
  puVar20[2] = 0;
  puVar20 = puRam020e8a48;
  *puVar1 = 0;
  *puVar20 = 0;
  puVar20 = puRam020e8a4c;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar11 = puRam020e8a50;
  *puVar20 = 0;
  *puVar11 = 0;
  puVar20 = puRam020e8a58;
  *puRam020e8a54 = 0;
  *puVar20 = 0;
  puVar20 = puRam020e8a70;
  piVar14 = piRam020e8a68;
  piVar13 = piRam020e8a64;
  piVar12 = piRam020e8a60;
  piVar9 = piRam020e8a5c;
  *puRam020e8a6c = 1;
  *puVar20 = 1;
  iVar15 = piVar10[1];
  iVar21 = piVar10[2];
  *piVar9 = *piVar10;
  piVar9[1] = iVar15;
  piVar9[2] = iVar21;
  iVar15 = piVar9[1];
  iVar21 = piVar9[2];
  *piVar12 = *piVar9;
  piVar12[1] = iVar15;
  piVar12[2] = iVar21;
  iVar15 = piVar12[1];
  iVar21 = piVar12[2];
  *piVar13 = *piVar12;
  piVar13[1] = iVar15;
  piVar13[2] = iVar21;
  iVar15 = piVar13[1];
  iVar21 = piVar13[2];
  *piVar14 = *piVar13;
  piVar14[1] = iVar15;
  piVar14[2] = iVar21;
  *puVar2 = 0;
  return;
}

