/* Decompiled C draft; module arm9; ROM address 020a36a8. No matching claim. */
#include "types.h"
#include "deps/020a36a8_func_020a36a8.h"

void func_020a36a8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint uVar7;
  
  uVar7 = param_1 + 0xa4U & 3;
  uVar6 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((int)uVar7 < 0) {
    uVar7 = param_1 + 0x14U & 3;
    uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    *(uint *)(param_1 + 0x14) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x1800;
  }
  else {
    iVar8 = GetDriverEntry(uVar7 & 0xffff);
    uVar7 = iVar8 + 300U & 3;
    uVar6 = *(uint *)(iVar8 + 300U & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = param_1 + 0x10U & 3;
    uVar12 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *(uint *)(param_1 + 0x10) =
         (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) + uVar6 + ((int)uVar6 >> 1);
    uVar7 = iVar8 + 0x130U & 3;
    uVar6 = *(uint *)(iVar8 + 0x130U & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = param_1 + 0x14U & 3;
    uVar12 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    *(uint *)(param_1 + 0x14) =
         (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) + uVar6 + ((int)uVar6 >> 1);
    uVar7 = iVar8 + 0x134U & 3;
    uVar6 = *(uint *)(iVar8 + 0x134U & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = param_1 + 0x18U & 3;
    uVar12 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(uint *)(param_1 + 0x18) =
         (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) + uVar6 + ((int)uVar6 >> 1);
  }
  uVar7 = param_1 + 0xd0U & 3;
  uVar13 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar6 = param_1 + 0xd8U & 3;
  uVar12 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
  uVar7 = (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) +
          (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
  lVar5 = (ulonglong)uVar7 * 0xa000;
  iVar16 = (int)((ulonglong)lVar5 >> 0x20);
  iVar8 = ((int)uVar7 >> 0x1f) * 0xa000 + iVar16;
  uVar7 = param_1 + 0xcU & 3;
  uVar23 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar6 = param_1 + 0x18U & 3;
  uVar19 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar12 = param_1 + 0xb8U & 3;
  uVar14 = *(uint *)(param_1 + 0xb8U & 0xfffffffc);
  uVar13 = param_1 + 0xc4U & 3;
  uVar9 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar1 = param_1 + 4U & 3;
  uVar32 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = param_1 + 0x10U & 3;
  uVar30 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = param_1 + 0xb0U & 3;
  uVar28 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar4 = param_1 + 0xbcU & 3;
  uVar25 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
  iVar20 = ((uVar23 >> uVar7 * 8 | uVar23 << uVar7 * -8 + 0x20) +
           (uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20)) -
           ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) +
           (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20));
  uVar7 = (uint)lVar5 >> 0xc | iVar16 * 0x100000;
  if (iVar20 < 0) {
    iVar8 = -iVar20;
  }
  iVar16 = ((uVar32 >> uVar1 * 8 | uVar32 << uVar1 * -8 + 0x20) +
           (uVar30 >> uVar2 * 8 | uVar30 << uVar2 * -8 + 0x20)) -
           ((uVar28 >> uVar3 * 8 | uVar28 << uVar3 * -8 + 0x20) +
           (uVar25 >> uVar4 * 8 | uVar25 << uVar4 * -8 + 0x20));
  if (iVar20 >= 0) {
    iVar8 = iVar20;
  }
  iVar27 = iVar16;
  if (iVar16 < 0) {
    iVar27 = -iVar16;
  }
  iVar8 = iVar27 / 2 + iVar8 / 2;
  if ((int)uVar7 < iVar8) {
    uVar6 = param_1 + 0xe0U & 3;
    uVar12 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    if ((uVar12 >> uVar6 * 8 != 0 || uVar12 << uVar6 * -8 + 0x20 != 0) && ((int)uVar7 < iVar8)) {
      iVar8 = FX_Div(iVar8 - uVar7);
      local_28 = (uint)((longlong)iVar20 * (longlong)iVar8) >> 0xc |
                 (int)((ulonglong)((longlong)iVar20 * (longlong)iVar8) >> 0x20) << 0x14;
      local_30 = (uint)((longlong)iVar16 * (longlong)iVar8) >> 0xc |
                 (int)((ulonglong)((longlong)iVar16 * (longlong)iVar8) >> 0x20) << 0x14;
      local_2c = 0;
      VecFx32_Subtract(param_1 + 4,&local_30,param_1 + 4);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xe0) = 1;
  }
  uVar7 = param_1 + 4U & 3;
  uVar33 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar6 = param_1 + 0x10U & 3;
  uVar30 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar12 = param_1 + 8U & 3;
  uVar26 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar13 = param_1 + 0x14U & 3;
  uVar24 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar1 = param_1 + 0xb4U & 3;
  uVar21 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  uVar2 = param_1 + 0xc0U & 3;
  uVar36 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  uVar3 = param_1 + 0xb0U & 3;
  uVar31 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar4 = param_1 + 0xbcU & 3;
  uVar29 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
  uVar9 = param_1 + 0xd0U & 3;
  uVar34 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar14 = param_1 + 0xd8U & 3;
  uVar32 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
  uVar19 = param_1 + 0xcU & 3;
  uVar35 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar23 = param_1 + 0x18U & 3;
  uVar17 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar25 = param_1 + 0xb8U & 3;
  uVar15 = *(uint *)(param_1 + 0xb8U & 0xfffffffc);
  uVar28 = param_1 + 0xc4U & 3;
  uVar10 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  iVar16 = (uVar34 >> uVar9 * 8 | uVar34 << uVar9 * -8 + 0x20) +
           (uVar32 >> uVar14 * 8 | uVar32 << uVar14 * -8 + 0x20);
  iVar20 = ((uVar26 >> uVar12 * 8 | uVar26 << uVar12 * -8 + 0x20) +
           (uVar24 >> uVar13 * 8 | uVar24 << uVar13 * -8 + 0x20)) -
           ((uVar21 >> uVar1 * 8 | uVar21 << uVar1 * -8 + 0x20) +
           (uVar36 >> uVar2 * 8 | uVar36 << uVar2 * -8 + 0x20));
  iVar8 = iVar16;
  if (iVar20 < 0) {
    iVar8 = -iVar20;
  }
  iVar27 = ((uVar33 >> uVar7 * 8 | uVar33 << uVar7 * -8 + 0x20) +
           (uVar30 >> uVar6 * 8 | uVar30 << uVar6 * -8 + 0x20)) -
           ((uVar31 >> uVar3 * 8 | uVar31 << uVar3 * -8 + 0x20) +
           (uVar29 >> uVar4 * 8 | uVar29 << uVar4 * -8 + 0x20));
  if (iVar20 >= 0) {
    iVar8 = iVar20;
  }
  iVar22 = ((uVar35 >> uVar19 * 8 | uVar35 << uVar19 * -8 + 0x20) +
           (uVar17 >> uVar23 * 8 | uVar17 << uVar23 * -8 + 0x20)) -
           ((uVar15 >> uVar25 * 8 | uVar15 << uVar25 * -8 + 0x20) +
           (uVar10 >> uVar28 * 8 | uVar10 << uVar28 * -8 + 0x20));
  iVar11 = iVar27;
  if (iVar27 < 0) {
    iVar11 = -iVar27;
  }
  iVar18 = iVar22;
  if (iVar22 < 0) {
    iVar18 = -iVar22;
  }
  iVar8 = iVar8 + (iVar11 >> 2) + (iVar18 >> 2);
  if (iVar8 != iVar16 * 0x10 && iVar8 + iVar16 * -0x10 < 0 == SBORROW4(iVar8,iVar16 * 0x10)) {
    iVar8 = FX_Div(iVar8 + iVar16 * -0x10);
    local_30 = (uint)((longlong)iVar27 * (longlong)iVar8) >> 0xc |
               (int)((ulonglong)((longlong)iVar27 * (longlong)iVar8) >> 0x20) << 0x14;
    local_2c = (uint)((longlong)iVar20 * (longlong)iVar8) >> 0xc |
               (int)((ulonglong)((longlong)iVar20 * (longlong)iVar8) >> 0x20) << 0x14;
    local_28 = (uint)((longlong)iVar22 * (longlong)iVar8) >> 0xc |
               (int)((ulonglong)((longlong)iVar22 * (longlong)iVar8) >> 0x20) << 0x14;
    uVar7 = param_1 + 0xa4U & 3;
    uVar6 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
    if ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < 0) {
      VecFx32_Add(param_1 + 0xbc,&local_30,param_1 + 0xbc);
    }
    else {
      VecFx32_Subtract(param_1 + 0x10,&local_30,param_1 + 0x10);
    }
  }
  VecFx32_Add(param_1 + 4,param_1 + 0x10,param_1 + 4);
  VecFx32_Add(param_1 + 0xb0,param_1 + 0xbc,param_1 + 0xb0);
  return;
}

