/* Decompiled C draft; module arm9; ROM address 020ff6d8. No matching claim. */
#include "types.h"
#include "deps/020ff6d8_func_020ff6d8.h"

void func_020ff6d8(int param_1,undefined4 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  
  uVar15 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if ((((uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) & 0x80000) != 0) &&
     (iVar4 = IsRaceOptionMenuOn_from_thumb(), iVar4 == 0)) {
    uVar15 = param_1 + 0x130U & 3;
    uVar3 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
    uVar12 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
    uVar15 = param_1 + 0x138U & 3;
    uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
    uVar14 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
    uVar15 = param_1 + 0x9cU & 3;
    uVar7 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
    uVar11 = (uint)((ulonglong)uVar12 * 0xa4) >> 0xc |
             (((int)uVar12 >> 0x1f) * 0xa4 + (int)((ulonglong)uVar12 * 0xa4 >> 0x20)) * 0x100000;
    uVar3 = param_1 + 0xb4U & 3;
    uVar16 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
    uVar10 = param_1 + 0x94U & 3;
    uVar17 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar13 = param_1 + 0xacU & 3;
    uVar18 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
    lVar1 = (longlong)(int)uVar12 *
            (longlong)(int)(uVar17 >> uVar10 * 8 | uVar17 << uVar10 * -8 + 0x20) +
            (longlong)(int)(uVar7 >> uVar15 * 8 | uVar7 << uVar15 * -8 + 0x20) *
            (longlong)(int)uVar14;
    lVar2 = (longlong)(int)uVar12 *
            (longlong)(int)(uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20) +
            (longlong)(int)(uVar16 >> uVar3 * 8 | uVar16 << uVar3 * -8 + 0x20) *
            (longlong)(int)uVar14;
    uVar13 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar15 = param_1 + 0xa0U & 3;
    uVar3 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
    uVar10 = (uint)((ulonglong)uVar14 * 0xa4) >> 0xc |
             (((int)uVar14 >> 0x1f) * 0xa4 + (int)((ulonglong)uVar14 * 0xa4 >> 0x20)) * 0x100000;
    *(uint *)(param_1 + 0xa0) = (uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) + uVar11;
    uVar15 = param_1 + 0xa8U & 3;
    uVar3 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
    *(uint *)(param_1 + 0xa8) = (uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) + uVar10;
    uVar15 = param_1 + 0xa4U & 3;
    uVar3 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
    uVar12 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
    uVar15 = param_1 + 0xa0U & 3;
    uVar3 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
    uVar3 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
    uVar15 = param_1 + 0xa8U & 3;
    uVar7 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
    uVar15 = uVar7 >> uVar15 * 8 | uVar7 << uVar15 * -8 + 0x20;
    lVar2 = (longlong)(int)uVar15 * (longlong)(int)uVar15 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar12 * (longlong)(int)uVar12;
    uVar15 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
      Vector3_MaybeNormalize(param_1 + 0xa0,param_1 + 0xa0);
    }
    iVar5 = uVar15 * uVar15;
    iVar4 = uVar13 * uVar13;
    if (iVar5 - iVar4 == 0 || iVar5 < iVar4) {
      uVar15 = param_1 + 0x94U & 3;
      uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
      *(uint *)(param_1 + 0x94) = (uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) - uVar11;
      uVar15 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      *(uint *)(param_1 + 0x9c) = (uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) - uVar10;
      Vector3_Cross(param_1 + 0x94,param_1 + 0xa0,param_1 + 0xac);
      uVar15 = param_1 + 0xb0U & 3;
      uVar3 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
      uVar10 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
      uVar15 = param_1 + 0xacU & 3;
      uVar3 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
      uVar3 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
      uVar15 = param_1 + 0xb4U & 3;
      uVar13 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
      uVar15 = uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20;
      lVar1 = (longlong)(int)uVar15 * (longlong)(int)uVar15 +
              (longlong)(int)uVar3 * (longlong)(int)uVar3 +
              (longlong)(int)uVar10 * (longlong)(int)uVar10;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        Vector3_MaybeNormalize(param_1 + 0xac,param_1 + 0xac);
      }
      Vector3_Cross(param_1 + 0xa0,param_1 + 0xac,param_1 + 0x94);
    }
    else {
      uVar15 = param_1 + 0xacU & 3;
      uVar3 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
      *(uint *)(param_1 + 0xac) = (uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) - uVar11;
      uVar15 = param_1 + 0xb4U & 3;
      uVar3 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
      *(uint *)(param_1 + 0xb4) = (uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) - uVar10;
      Vector3_Cross(param_1 + 0xa0,param_1 + 0xac,param_1 + 0x94);
      uVar15 = param_1 + 0x98U & 3;
      uVar3 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
      uVar10 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
      uVar15 = param_1 + 0x94U & 3;
      uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
      uVar3 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
      uVar15 = param_1 + 0x9cU & 3;
      uVar13 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar15 = uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20;
      lVar1 = (longlong)(int)uVar15 * (longlong)(int)uVar15 +
              (longlong)(int)uVar3 * (longlong)(int)uVar3 +
              (longlong)(int)uVar10 * (longlong)(int)uVar10;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        Vector3_MaybeNormalize(param_1 + 0x94,param_1 + 0x94);
      }
      Vector3_Cross(param_1 + 0x94,param_1 + 0xa0,param_1 + 0xac);
    }
  }
  uVar15 = param_1 + 0xd0U & 3;
  uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar10 = uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20;
  *(int *)(param_1 + 0xb8) =
       (int)(*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
            *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) >> 4;
  uVar15 = uVar10 + 4 & 3;
  uVar3 = *(uint *)(uVar10 + 4 & 0xfffffffc);
  *(int *)(param_1 + 0xbc) = (int)(uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) >> 4;
  uVar15 = uVar10 + 8 & 3;
  uVar3 = *(uint *)(uVar10 + 8 & 0xfffffffc);
  *(int *)(param_1 + 0xc0) = (int)(uVar3 >> uVar15 * 8 | uVar3 << uVar15 * -8 + 0x20) >> 4;
  uVar6 = *(undefined4 *)(param_1 + 0x98);
  uVar8 = *(undefined4 *)(param_1 + 0x9c);
  uVar9 = *(undefined4 *)(param_1 + 0xa0);
  *param_2 = *(undefined4 *)(param_1 + 0x94);
  param_2[1] = uVar6;
  param_2[2] = uVar8;
  param_2[3] = uVar9;
  uVar6 = *(undefined4 *)(param_1 + 0xa8);
  uVar8 = *(undefined4 *)(param_1 + 0xac);
  uVar9 = *(undefined4 *)(param_1 + 0xb0);
  param_2[4] = *(undefined4 *)(param_1 + 0xa4);
  param_2[5] = uVar6;
  param_2[6] = uVar8;
  param_2[7] = uVar9;
  uVar6 = *(undefined4 *)(param_1 + 0xb8);
  uVar8 = *(undefined4 *)(param_1 + 0xbc);
  uVar9 = *(undefined4 *)(param_1 + 0xc0);
  param_2[8] = *(undefined4 *)(param_1 + 0xb4);
  param_2[9] = uVar6;
  param_2[10] = uVar8;
  param_2[0xb] = uVar9;
  return;
}

