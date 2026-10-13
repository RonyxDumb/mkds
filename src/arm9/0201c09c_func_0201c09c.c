/* Decompiled C draft; module arm9; ROM address 0201c09c. No matching claim. */
#include "types.h"
#include "deps/0201c09c_func_0201c09c.h"

uint func_0201c09c(int param_1,int param_2)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int *piVar20;
  undefined1 auStack_60 [60];
  uint uVar10;
  
  puVar6 = puRam0201c4d4;
  uVar13 = (uint)*(ushort *)(param_2 + 0x2e);
  uVar15 = param_1 + 0x40U & 3;
  uVar9 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar10 = uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20;
  uVar15 = uVar10 + 0x20;
  uVar9 = uVar15 & 3;
  uVar15 = *(uint *)(uVar15 & 0xfffffffc);
  uVar9 = uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20;
  uVar15 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar17 = uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20;
  iVar8 = (int)((uVar13 & 0x1f) * (((uVar13 << 0x16) >> 0x1b) + 1)) >> 5;
  uVar9 = param_1 + 0x3cU & 3;
  uVar12 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  uVar15 = uVar17 + 0x48;
  uVar7 = uVar15 & 3;
  uVar16 = *(uint *)(uVar15 & 0xfffffffc);
  sVar1 = *(short *)(uVar17 + 0x30);
  uVar17 = (uint)*(ushort *)(uVar10 + 0x72);
  uVar19 = (uint)*(short *)(param_2 + 0x34);
  uVar18 = (uint)*(ushort *)(param_2 + 0x36);
  uVar15 = param_1 + 0x44U & 3;
  uVar10 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar10 = uVar10 >> uVar15 * 8 | uVar10 << uVar15 * -8 + 0x20;
  *puRam0201c4d4 =
       uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20 | 0xc0 | ((uVar13 << 0x10) >> 0x1a) << 0x18
       | iVar8 << 0x10;
  uVar15 = ((uVar16 >> uVar7 * 8 | uVar16 << uVar7 * -8 + 0x20) << 1) >> 0x1d;
  piVar20 = (int *)auStack_60;
  if (iVar8 == 0) {
    piVar20 = (int *)&stack0xffffffdc;
  }
  uVar9 = (uint)puVar6 & 3;
  uVar7 = *(uint *)((uint)puVar6 & 0xfffffffc);
  if (iVar8 != 0) {
    uVar9 = param_2 + 0x30U & 3;
    uVar7 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
    uVar9 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    lVar2 = (longlong)(int)uVar9 * (longlong)(int)sVar1 + 0x800;
    uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    if (uVar15 == 0) {
      uVar15 = (uint)((ulonglong)uVar19 * (ulonglong)uVar9);
      lVar2 = (longlong)(int)uVar7 * (longlong)(int)uVar19 + 0x800;
      uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
      uVar9 = uVar15 + 0x800 >> 0xc |
              (((int)uVar9 >> 0x1f) * uVar19 +
               uVar9 * ((int)uVar19 >> 0x1f) + (int)((ulonglong)uVar19 * (ulonglong)uVar9 >> 0x20) +
              (uint)(0xfffff7ff < uVar15)) * 0x100000;
    }
    else if (uVar15 == 1) {
      lVar2 = (longlong)(int)uVar7 * (longlong)(int)uVar19 + 0x800;
      uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    }
    else {
      uVar15 = (uint)((ulonglong)uVar19 * (ulonglong)uVar9);
      uVar9 = uVar15 + 0x800 >> 0xc |
              (((int)uVar9 >> 0x1f) * uVar19 +
               uVar9 * ((int)uVar19 >> 0x1f) + (int)((ulonglong)uVar19 * (ulonglong)uVar9 >> 0x20) +
              (uint)(0xfffff7ff < uVar15)) * 0x100000;
    }
    uVar15 = param_1 + 0x40U & 3;
    uVar12 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar15 = (uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20) + 0x20;
    uVar12 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar12 = uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20;
    uVar15 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar15 = uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20;
    if ((int)((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
              *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) << 8) < 0) {
      uVar12 = param_2 + 8U & 3;
      uVar14 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar13 = param_2 + 0x38U & 3;
      uVar19 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
      uVar16 = uVar15 + 4 & 3;
      uVar15 = *(uint *)(uVar15 + 4 & 0xfffffffc);
      *piVar20 = ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) +
                 (uVar19 >> uVar13 * 8 | uVar19 << uVar13 * -8 + 0x20)) -
                 (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20);
      uVar15 = param_1 + 0x40U & 3;
      uVar13 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      uVar12 = param_2 + 0xcU & 3;
      uVar14 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      uVar15 = (uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20) + 0x20;
      uVar13 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      uVar16 = uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20;
      uVar13 = param_2 + 0x3cU & 3;
      uVar19 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
      uVar15 = uVar16 & 3;
      uVar16 = *(uint *)(uVar16 & 0xfffffffc);
      uVar15 = (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20) + 8;
      uVar16 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      piVar20[1] = ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) +
                   (uVar19 >> uVar13 * 8 | uVar19 << uVar13 * -8 + 0x20)) -
                   (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20);
      uVar15 = param_1 + 0x40U & 3;
      uVar13 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      uVar12 = param_2 + 0x10U & 3;
      uVar14 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      uVar15 = (uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20) + 0x20;
      uVar13 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      uVar16 = uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20;
      uVar13 = param_2 + 0x40U & 3;
      uVar19 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
      uVar15 = uVar16 & 3;
      uVar16 = *(uint *)(uVar16 & 0xfffffffc);
      uVar15 = (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20) + 0xc;
      uVar16 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      piVar20[2] = ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) +
                   (uVar19 >> uVar13 * 8 | uVar19 << uVar13 * -8 + 0x20)) -
                   (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20);
      func_02147288((uint)(uintptr_t)(piVar20),uVar10,piVar20);
      iVar8 = (int)(uint)*(ushort *)(param_2 + 0x20) >> 4;
      iVar11 = (int)*(short *)(iRam0201c4d8 + iVar8 * 4);
      iVar8 = (int)*(short *)(iRam0201c4d8 + (iVar8 * 2 + 1) * 2);
      piVar20[0xc] = *piVar20;
      piVar20[0xd] = piVar20[1];
      piVar20[0xb] = 0x1000;
      piVar20[0xe] = piVar20[2];
      lVar3 = (longlong)iVar8 * (longlong)(int)uVar7 + 0x800;
      lVar2 = (longlong)iVar11 * (longlong)(int)uVar7 + 0x800;
      lVar4 = (longlong)-iVar11 * (longlong)(int)uVar9 + 0x800;
      lVar5 = (longlong)iVar8 * (longlong)(int)uVar9 + 0x800;
      piVar20[7] = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000;
      piVar20[3] = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      piVar20[4] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
      piVar20[5] = 0;
      piVar20[6] = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      piVar20[8] = 0;
      piVar20[9] = 0;
      piVar20[10] = 0;
      *puRam0201c4dc = 0;
      puVar6 = puRam0201c4e0;
      uVar15 = param_1 + 0x40U & 3;
      uVar9 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      uVar15 = (uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20) + 0x20;
      uVar9 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      uVar9 = uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20;
      uVar15 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar10 = uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20;
      uVar15 = uVar10 + 0xc & 3;
      uVar13 = *(uint *)(uVar10 + 0xc & 0xfffffffc);
      uVar9 = uVar10 + 8 & 3;
      uVar12 = *(uint *)(uVar10 + 8 & 0xfffffffc);
      uVar7 = uVar10 + 4 & 3;
      uVar10 = *(uint *)(uVar10 + 4 & 0xfffffffc);
      *puRam0201c4e0 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
      *puVar6 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
      *puVar6 = uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20;
      G3_MultMtx43(piVar20 + 3);
    }
    else {
      uVar15 = param_2 + 8U & 3;
      uVar16 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar12 = param_2 + 0x38U & 3;
      uVar13 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
      *piVar20 = (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20) +
                 (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20);
      uVar15 = param_2 + 0xcU & 3;
      uVar16 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      uVar12 = param_2 + 0x3cU & 3;
      uVar13 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
      piVar20[1] = (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20) +
                   (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20);
      uVar15 = param_2 + 0x10U & 3;
      uVar16 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      uVar12 = param_2 + 0x40U & 3;
      uVar13 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
      piVar20[2] = (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20) +
                   (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20);
      func_02147288((uint)(uintptr_t)(piVar20),uVar10,piVar20);
      iVar8 = (int)(uint)*(ushort *)(param_2 + 0x20) >> 4;
      iVar11 = (int)*(short *)(iRam0201c4d8 + iVar8 * 4);
      iVar8 = (int)*(short *)(iRam0201c4d8 + (iVar8 * 2 + 1) * 2);
      piVar20[0xc] = *piVar20;
      piVar20[0xb] = 0x1000;
      piVar20[0xd] = piVar20[1];
      piVar20[0xe] = piVar20[2];
      lVar3 = (longlong)iVar8 * (longlong)(int)uVar7 + 0x800;
      lVar2 = (longlong)iVar11 * (longlong)(int)uVar7 + 0x800;
      lVar4 = (longlong)-iVar11 * (longlong)(int)uVar9 + 0x800;
      lVar5 = (longlong)iVar8 * (longlong)(int)uVar9 + 0x800;
      piVar20[3] = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      piVar20[4] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
      piVar20[5] = 0;
      piVar20[6] = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      piVar20[7] = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000;
      piVar20[8] = 0;
      piVar20[9] = 0;
      piVar20[10] = 0;
      *puRam0201c4dc = 0;
      G3_MultMtx43(piVar20 + 3);
    }
    *puRam0201c4e4 =
         (int)((uVar18 & 0x1f) * (uVar17 & 0x1f)) >> 5 |
         ((int)((uVar18 & 0x3e0) * (uVar17 & 0x3e0)) >> 0xf) << 5 |
         ((int)((uVar18 & 0x7c00) * (uVar17 & 0x7c00)) >> 0x19) << 10;
    uVar15 = param_1 + 0x40U & 3;
    uVar9 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar7 = uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20;
    uVar15 = uVar7 + 0x20 & 3;
    uVar9 = *(uint *)(uVar7 + 0x20 & 0xfffffffc);
    uVar9 = uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20;
    uVar15 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar15 = uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20;
    uVar15 = func_0201c690((int)*(short *)(uVar7 + 0x78),(int)*(short *)(uVar7 + 0x7a),
                           (int)*(short *)(uVar15 + 0x50),(int)*(short *)(uVar15 + 0x52));
    return uVar15;
  }
  return uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
}

