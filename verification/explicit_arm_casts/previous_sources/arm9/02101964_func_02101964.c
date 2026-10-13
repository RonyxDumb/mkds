/* Decompiled C draft; module arm9; ROM address 02101964. No matching claim. */
#include "types.h"
#include "deps/02101964_func_02101964.h"

void func_02101964(int param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  int *piVar19;
  uint uVar20;
  uint uVar22;
  uint local_28;
  uint local_20;
  uint uVar15;
  uint uVar21;
  
  uVar18 = param_1 + 0x168U & 3;
  uVar20 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar21 = uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20;
  iVar7 = GetGlobalHD4();
  uVar18 = uVar21 + 0x180 & 3;
  uVar20 = *(uint *)(uVar21 + 0x180 & 0xfffffffc);
  bVar5 = true;
  bVar4 = true;
  piVar19 = (int *)(param_1 + 0x50);
  if (((int)(uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20) < 4) &&
     (uVar18 = uVar21 + 0x7c & 3, uVar20 = *(uint *)(uVar21 + 0x7c & 0xfffffffc),
     ((uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20) & uRam02101c74) == 0)) {
    bVar4 = false;
  }
  if ((!bVar4) &&
     (uVar18 = uVar21 + 0x4c & 3, uVar20 = *(uint *)(uVar21 + 0x4c & 0xfffffffc),
     ((uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20) & uRam02101c78) == 0)) {
    bVar5 = false;
  }
  if (bVar5) {
    uVar18 = param_1 + 0x144U & 3;
    uVar20 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    if (((uVar20 >> uVar18 * 8 == 0 && uVar20 << uVar18 * -8 + 0x20 == 0) &&
        (uVar18 = param_1 + 0x74U & 3, uVar20 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
        ((uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20) & 0x8000000) != 0)) &&
       (uVar18 = param_1 + 0x24cU & 3, uVar20 = *(uint *)(param_1 + 0x24cU & 0xfffffffc),
       uVar20 >> uVar18 * 8 != 0 || uVar20 << uVar18 * -8 + 0x20 != 0)) {
      *(undefined4 *)(param_1 + 0x144) = 1;
      func_020fe694(0xb,(int)*(short *)(param_1 + 0x4e),1,*(ushort *)(param_1 + 0x13a) & 0xff);
    }
    else {
      *(undefined4 *)(param_1 + 0x144) = 1;
    }
  }
  uVar11 = *(uint *)((uint)piVar19 & 0xfffffffc);
  uVar18 = param_1 + 0x5cU & 3;
  uVar8 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar20 = param_1 + 0x58U & 3;
  uVar12 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar1 = param_1 + 100U & 3;
  uVar9 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar15 = param_1 + 0x144U & 3;
  uVar10 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar10 >> uVar15 * 8 == 0 && uVar10 << uVar15 * -8 + 0x20 == 0) {
    uVar13 = *(undefined4 *)(uVar21 + 0x9c);
    uVar16 = *(undefined4 *)(uVar21 + 0xa0);
    *piVar19 = *(int *)(uVar21 + 0x98);
    *(undefined4 *)(param_1 + 0x54) = uVar13;
    *(undefined4 *)(param_1 + 0x58) = uVar16;
    VecFx32_Subtract(piVar19,param_1 + 0x184,param_1 + 400);
    *(int *)(param_1 + 0x184) = *piVar19;
    *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_1 + 0x58);
    uVar15 = param_1 + 0x54U & 3;
    uVar22 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    uVar10 = uVar21 + 700 & 3;
    uVar14 = *(uint *)(uVar21 + 700 & 0xfffffffc);
    *(uint *)(param_1 + 0x54) =
         (uVar22 >> uVar15 * 8 | uVar22 << uVar15 * -8 + 0x20) -
         (uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20);
  }
  else {
    VecFx32_Add(param_1 + 0x184,param_1 + 400,param_1 + 0x184);
    uVar10 = uRam02101c7c;
    uVar15 = param_1 + 400U & 3;
    uVar14 = *(uint *)(param_1 + 400U & 0xfffffffc);
    uVar15 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
    lVar3 = (ulonglong)uRam02101c7c * (ulonglong)uVar15;
    *(uint *)(param_1 + 400) =
         (uint)lVar3 >> 0xc |
         (((int)uVar15 >> 0x1f) * uRam02101c7c + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    uVar15 = param_1 + 0x194U & 3;
    uVar14 = *(uint *)(param_1 + 0x194U & 0xfffffffc);
    uVar15 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
    lVar3 = (ulonglong)uVar10 * (ulonglong)uVar15;
    *(uint *)(param_1 + 0x194) =
         (uint)lVar3 >> 0xc |
         (((int)uVar15 >> 0x1f) * uVar10 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    uVar15 = param_1 + 0x198U & 3;
    uVar14 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
    uVar15 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
    lVar3 = (ulonglong)uVar10 * (ulonglong)uVar15;
    *(uint *)(param_1 + 0x198) =
         (uint)lVar3 >> 0xc |
         (((int)uVar15 >> 0x1f) * uVar10 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    *piVar19 = *(int *)(param_1 + 0x184);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x188);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x18c);
  }
  VecFx32_Add(piVar19,param_1 + 0x16c);
  uVar15 = param_1 + 0x15cU & 3;
  uVar10 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  uVar14 = iVar7 + 0xc;
  if (uVar10 >> uVar15 * 8 == 0 && uVar10 << uVar15 * -8 + 0x20 == 0) {
    iVar17 = 0x800;
    local_20 = 0x400;
  }
  else {
    local_20 = 0x800;
    iVar17 = iRam02101c80;
  }
  if (param_2 != 0) {
    uVar15 = uVar21 + 0x2cc & 3;
    uVar10 = *(uint *)(uVar21 + 0x2cc & 0xfffffffc);
    uVar10 = uVar10 >> uVar15 * 8 | uVar10 << uVar15 * -8 + 0x20;
    uVar15 = uVar21 + 0xc4 & 3;
    uVar22 = *(uint *)(uVar21 + 0xc4 & 0xfffffffc);
    uVar21 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    lVar3 = (longlong)(int)(uVar10 >> uVar21 * 8 | uVar10 << uVar21 * -8 + 0x20) *
            (longlong)(int)(uVar22 >> uVar15 * 8 | uVar22 << uVar15 * -8 + 0x20) + 0x800;
    iVar6 = -((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000);
    lVar3 = (longlong)iVar6 *
            (longlong)
            (int)(*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                 *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20);
    *piVar19 = (*(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
               *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    uVar21 = iVar7 + 0x14U & 3;
    uVar10 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
    uVar15 = param_1 + 0x58U & 3;
    uVar22 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    lVar3 = (longlong)iVar6 * (longlong)(int)(uVar10 >> uVar21 * 8 | uVar10 << uVar21 * -8 + 0x20);
    *(uint *)(param_1 + 0x58) =
         (uVar22 >> uVar15 * 8 | uVar22 << uVar15 * -8 + 0x20) +
         ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  }
  uVar21 = param_1 + 0x58U & 3;
  uVar10 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar15 = iVar7 + 0x14U & 3;
  uVar22 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
  uVar14 = *(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
           *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20;
  lVar3 = (longlong)
          (int)(((uVar11 >> ((uint)piVar19 & 3) * 8 | uVar11 << ((uint)piVar19 & 3) * -8 + 0x20) -
                (uVar8 >> uVar18 * 8 | uVar8 << uVar18 * -8 + 0x20)) -
               (*(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
               *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20)) *
          (longlong)(int)uVar14 +
          (longlong)(int)(uVar22 >> uVar15 * 8 | uVar22 << uVar15 * -8 + 0x20) *
          (longlong)
          (int)(((uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20) -
                (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20)) -
               (uVar10 >> uVar21 * 8 | uVar10 << uVar21 * -8 + 0x20));
  uVar21 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  lVar3 = (longlong)(int)uVar14 * (longlong)(int)uVar21;
  uVar18 = iVar7 + 0x14U & 3;
  uVar20 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
  lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14) *
          (longlong)iVar17;
  lVar2 = (longlong)(int)(uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20) *
          (longlong)(int)uVar21;
  lVar2 = (longlong)(int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14) *
          (longlong)iVar17;
  uVar20 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar18 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  local_28 = local_20;
  if (((int)uVar20 <= (int)local_20) &&
     (local_28 = uVar20, (int)(uVar20 + local_20) < 0 != SBORROW4(uVar20,-local_20))) {
    local_28 = -local_20;
  }
  if (((int)uVar18 <= (int)local_20) &&
     (uVar20 = -local_20, iVar7 = uVar18 + local_20, local_20 = uVar18,
     iVar7 < 0 != SBORROW4(uVar18,uVar20))) {
    local_20 = uVar20;
  }
  uVar18 = param_1 + 0x16cU & 3;
  uVar20 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  *(uint *)(param_1 + 0x16c) = local_28 + (uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20);
  uVar18 = param_1 + 0x174U & 3;
  uVar20 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  *(uint *)(param_1 + 0x174) = local_20 + (uVar20 >> uVar18 * 8 | uVar20 << uVar18 * -8 + 0x20);
  return;
}

