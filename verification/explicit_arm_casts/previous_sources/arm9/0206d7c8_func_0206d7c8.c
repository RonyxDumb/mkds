/* Decompiled C draft; module arm9; ROM address 0206d7c8. No matching claim. */
#include "types.h"
#include "deps/0206d7c8_func_0206d7c8.h"

void func_0206d7c8(int param_1,int param_2,uint param_3,int param_4,uint *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint extraout_r1;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  int iStack_30;
  
  uVar15 = param_1 + 0x2ccU & 3;
  uVar5 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar8 = param_2 + 0x2ccU & 3;
  uVar16 = *(uint *)(param_2 + 0x2ccU & 0xfffffffc);
  uVar14 = param_1 + 0x2d0U & 3;
  uVar18 = *(uint *)(param_1 + 0x2d0U & 0xfffffffc);
  uVar9 = param_2 + 0x2d0U & 3;
  uVar13 = *(uint *)(param_2 + 0x2d0U & 0xfffffffc);
  uVar10 = param_1 + 0x7cU & 3;
  uVar12 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar14 = (uVar18 >> uVar14 * 8 | uVar18 << uVar14 * -8 + 0x20) + 4;
  uVar18 = uVar14 & 3;
  uVar19 = *(uint *)(uVar14 & 0xfffffffc);
  uVar14 = (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) + 4;
  uVar9 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  iVar20 = (int)*(short *)((uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20) + 0xc) +
           (uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20);
  iVar17 = (int)*(short *)((uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20) + 0xc) +
           (uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20);
  uVar14 = param_1 + 0x2a0U & 3;
  uVar15 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
  uVar14 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20;
  if (((uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) & 0x600) == 0) {
    if ((int)uVar14 < 0x801) {
      uVar15 = uVar14 * 2;
      if ((int)(uVar14 * 2) < (int)uRam0206dbe8) {
        uVar15 = uRam0206dbe8;
      }
    }
    else {
      uVar15 = 0x1000;
    }
  }
  else {
    uVar6 = FUN_02132440(uVar14);
    iVar7 = FUN_02131860(uVar6,uRam0206dbe4);
    uVar15 = uVar14;
    if (iVar7 != 0) {
      uVar15 = uRam0206dbe8;
    }
  }
  uVar14 = param_1 + 0x4cU & 3;
  uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20) & 0x80) != 0) {
    iVar20 = iVar20 >> 3;
    iVar17 = iVar17 >> 3;
  }
  uVar14 = param_1 + 0x48U & 3;
  uVar9 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar8 = param_2 + 0x48U & 3;
  uVar10 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  if (((uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) & 0x100000) != 0) {
    iVar20 = iVar20 << 1;
  }
  if (((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) & 0x100000) != 0) {
    iVar20 = iVar20 >> 2;
  }
  iVar17 = FX_Div(iVar20,iVar17);
  if (0x5000 < iVar17) {
    iVar17 = 0x5000;
  }
  lVar1 = (longlong)
          (int)((uint)((longlong)iVar20 * (longlong)iVar17) >> 0xc |
               (int)((ulonglong)((longlong)iVar20 * (longlong)iVar17) >> 0x20) << 0x14) *
          (longlong)(int)uVar15;
  local_58 = *(int *)(param_2 + 0x50);
  local_54 = *(int *)(param_2 + 0x54);
  local_50 = *(int *)(param_2 + 0x58);
  uVar14 = param_2 + 0x44U & 3;
  uVar15 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (((uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) & 0x100) != 0) {
    local_58 = -local_58;
    local_54 = -local_54;
    local_50 = -local_50;
  }
  lVar1 = (longlong)
          (int)(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) * (longlong)(int)uVar8;
  local_70 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar14 = param_3 + 4 & 3;
  uVar15 = *(uint *)(param_3 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) *
          (longlong)(int)uVar8;
  local_6c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar14 = param_3 + 8 & 3;
  uVar15 = *(uint *)(param_3 + 8 & 0xfffffffc);
  iVar20 = (int)uVar8 >> 0x1f;
  lVar1 = (longlong)(int)(uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) *
          (longlong)(int)uVar8;
  local_68 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  iVar17 = Vector3_DotProduct(&local_58,&local_70);
  local_60 = local_6c -
             ((uint)((longlong)local_54 * (longlong)iVar17) >> 0xc |
             (int)((ulonglong)((longlong)local_54 * (longlong)iVar17) >> 0x20) << 0x14);
  local_64 = local_70 -
             ((uint)((longlong)local_58 * (longlong)iVar17) >> 0xc |
             (int)((ulonglong)((longlong)local_58 * (longlong)iVar17) >> 0x20) << 0x14);
  iVar7 = 0;
  local_5c = local_68 -
             ((uint)((longlong)local_50 * (longlong)iVar17) >> 0xc |
             (int)((ulonglong)((longlong)local_50 * (longlong)iVar17) >> 0x20) << 0x14);
  lVar1 = (longlong)local_5c * (longlong)local_5c +
          (longlong)local_64 * (longlong)local_64 + (longlong)local_60 * (longlong)local_60;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    iVar7 = Vector3_MaybeNormalize(&local_64,&uStack_4c);
  }
  if (iVar7 < 1) {
    return;
  }
  if (param_4 == 0) {
    if ((((*(uint *)((uint)param_5 & 0xfffffffc) >> ((uint)param_5 & 3) * 8 != 0 ||
           *(uint *)((uint)param_5 & 0xfffffffc) << ((uint)param_5 & 3) * -8 + 0x20 != 0) ||
         (uVar14 = (uint)(param_5 + 1) & 3, uVar15 = *(uint *)((uint)(param_5 + 1) & 0xfffffffc),
         uVar15 >> uVar14 * 8 != 0 || uVar15 << uVar14 * -8 + 0x20 != 0)) ||
        (uVar14 = (uint)(param_5 + 2) & 3, uVar15 = *(uint *)((uint)(param_5 + 2) & 0xfffffffc),
        uVar15 >> uVar14 * 8 != 0 || uVar15 << uVar14 * -8 + 0x20 != 0)) &&
       (iVar17 = Vector3_DotProduct(&uStack_4c,param_5), iRam0206dbec < iVar17)) {
      uStack_4c = *puRam0206dbf0;
      uStack_48 = puRam0206dbf0[1];
      uStack_44 = puRam0206dbf0[2];
    }
  }
  else {
    *param_5 = uStack_4c;
    param_5[1] = uStack_48;
    param_5[2] = uStack_44;
  }
  uStack_3c = (uint)((ulonglong)uVar8 * (ulonglong)uStack_48) >> 0xc |
              (((int)uStack_48 >> 0x1f) * uVar8 +
              uStack_48 * iVar20 + (int)((ulonglong)uVar8 * (ulonglong)uStack_48 >> 0x20)) *
              0x100000;
  uStack_38 = (uint)((ulonglong)uVar8 * (ulonglong)uStack_44) >> 0xc |
              (((int)uStack_44 >> 0x1f) * uVar8 +
              uStack_44 * iVar20 + (int)((ulonglong)uVar8 * (ulonglong)uStack_44 >> 0x20)) *
              0x100000;
  uStack_40 = (uint)((ulonglong)uVar8 * (ulonglong)uStack_4c) >> 0xc |
              (((int)uStack_4c >> 0x1f) * uVar8 +
              uStack_4c * iVar20 + (int)((ulonglong)uVar8 * (ulonglong)uStack_4c >> 0x20)) *
              0x100000;
  if (0 < (int)uStack_3c) {
    uStack_3c = 0;
  }
  iVar17 = Vector3_DotProduct(param_2 + 0x244,&uStack_40);
  uVar14 = param_2 + 0x244U & 3;
  uVar9 = *(uint *)(param_2 + 0x244U & 0xfffffffc);
  uVar15 = param_2 + 0x24cU & 3;
  uVar10 = *(uint *)(param_2 + 0x24cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) * (longlong)iVar17;
  lVar2 = (longlong)(int)(uVar10 >> uVar15 * 8 | uVar10 << uVar15 * -8 + 0x20) * (longlong)iVar17;
  uVar14 = param_2 + 0x248U & 3;
  uVar15 = *(uint *)(param_2 + 0x248U & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) * (longlong)iVar17;
  uVar4 = (ulonglong)uRam0206dbf4;
  uVar10 = (uint)(uVar4 * uVar8);
  iVar20 = iVar20 * uRam0206dbf4;
  uVar14 = param_2 + 0x2d8U & 3;
  uVar15 = *(uint *)(param_2 + 0x2d8U & 0xfffffffc);
  *(uint *)(param_2 + 0x2d8) =
       (uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) +
       (uStack_40 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14));
  uVar14 = param_2 + 0x2e0U & 3;
  uVar15 = *(uint *)(param_2 + 0x2e0U & 0xfffffffc);
  *(uint *)(param_2 + 0x2e0) =
       (uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20) +
       (uStack_38 - ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14));
  uVar14 = param_2 + 0x260U & 3;
  uVar9 = *(uint *)(param_2 + 0x260U & 0xfffffffc);
  uVar15 = uVar10 + 0x800 >> 0xc |
           (iVar20 + (int)(uVar4 * uVar8 >> 0x20) + (uint)(0xfffff7ff < uVar10)) * 0x100000;
  *(uint *)(param_2 + 0x260) =
       (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) +
       (uStack_3c - ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14));
  if (0x1000 < (int)uVar15) {
    uVar15 = 0x1000;
  }
  VecFx32_CrossProduct(&uStack_4c,param_2 + 0x278,auStack_34);
  if (iStack_30 < 0) {
    uVar15 = -uVar15;
  }
  uVar14 = param_2 + 0x590U & 3;
  uVar8 = *(uint *)(param_2 + 0x590U & 0xfffffffc);
  uVar14 = (uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20) + 0x58;
  uVar8 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  if (uVar14 >> uVar8 * 8 != 0 || uVar14 << uVar8 * -8 + 0x20 != 0) {
    return;
  }
  uVar14 = param_2 + 0x2a8U & 3;
  uVar8 = *(uint *)(param_2 + 0x2a8U & 0xfffffffc);
  uVar14 = uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20;
  if ((int)uVar14 < 1) {
    uVar14 = -uVar14;
  }
  if ((int)uVar14 < 0x3001) {
    return;
  }
  uVar14 = param_2 + 0x4cU & 3;
  uVar9 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
  uVar8 = extraout_r1;
  if (0 < (int)uVar15) {
    uVar8 = uVar15;
  }
  *(uint *)(param_2 + 0x4c) = uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20 | 0x2000000;
  uVar14 = param_2 + 0x594U & 3;
  uVar9 = *(uint *)(param_2 + 0x594U & 0xfffffffc);
  if ((int)uVar15 < 1) {
    uVar8 = -uVar15;
  }
  if ((int)uVar8 <= (int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20)) {
    return;
  }
  *(uint *)(param_2 + 0x594) = uVar8;
  if (0 < (int)uVar15) {
    uVar8 = 1;
  }
  uVar11 = (undefined2)uVar8;
  if ((int)uVar15 < 1) {
    uVar11 = 0xffff;
  }
  *(undefined2 *)(param_2 + 0x598) = uVar11;
  return;
}

