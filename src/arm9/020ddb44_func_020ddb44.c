/* Decompiled C draft; module arm9; ROM address 020ddb44. No matching claim. */
#include "types.h"
#include "deps/020ddb44_func_020ddb44.h"

void func_020ddb44(int param_1,undefined4 *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  undefined4 **ppuVar22;
  undefined4 *local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  int local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar16 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  local_7c = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
  uVar16 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar21 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
  uVar16 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  local_78 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
  uVar16 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar19 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
  uVar16 = param_1 + 4U & 3;
  uVar13 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar5 = param_1 + 0x10U & 3;
  uVar11 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  local_34 = *(uint *)(param_1 + 0x14);
  local_30 = *(uint *)(param_1 + 0x18);
  local_2c = *(uint *)(param_1 + 0x1c);
  iVar20 = uVar21 - 1;
  iVar9 = 1;
  uVar7 = local_7c;
  if (1 < (int)uVar21) {
    do {
      uVar1 = uVar7 + 0x10 & 3;
      uVar6 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
      iVar9 = iVar9 + 1;
      *(uint *)(uVar7 + 0x10) =
           (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) -
           (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20);
      uVar7 = uVar7 + 0xc;
    } while (iVar9 < (int)uVar21);
  }
  iVar9 = 1;
  local_80 = param_2;
  if (1 < (int)uVar21) {
    iVar17 = local_7c + 0xc;
    iVar18 = iVar17;
    do {
      VecFx32_AddScale1(-(uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) * (uVar21 - iVar9),
                        iVar17,iVar17,(int *)(uintptr_t)(iVar18));
      iVar9 = iVar9 + 1;
      iVar18 = iVar18 + 0xc;
      iVar17 = iVar17 + 0xc;
    } while (iVar9 < (int)uVar21);
  }
  iVar9 = 1;
  if (1 < (int)uVar21) {
    iVar17 = uVar19 + 0xc;
    iVar18 = iVar17;
    uVar16 = local_7c;
    do {
      uVar16 = uVar16 + 0xc;
      VecFx32_Add(iVar17,uVar16,(int *)(uintptr_t)(iVar18));
      iVar9 = iVar9 + 1;
      iVar18 = iVar18 + 0xc;
      iVar17 = iVar17 + 0xc;
    } while (iVar9 < (int)uVar21);
  }
  puVar14 = (undefined4 *)(iVar20 * 0xc + uVar19);
  uVar8 = local_80[1];
  uVar10 = local_80[2];
  *puVar14 = *local_80;
  puVar14[1] = uVar8;
  puVar14[2] = uVar10;
  if (1 < iVar20) {
    local_74 = local_34;
    local_6c = local_30;
    local_64 = local_2c;
    local_70 = (int)local_34 >> 0x1f;
    local_68 = (int)local_30 >> 0x1f;
    local_60 = (int)local_2c >> 0x1f;
    local_5c = 0;
    do {
      iVar18 = (iVar20 + -1) * 0xc;
      VecFx32_Subtract(uVar19 + iVar18,(uint)(uintptr_t)(puVar14),&local_4c);
      uVar16 = param_1 + 0x2cU & 3;
      uVar5 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      uVar5 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
      lVar2 = (longlong)(int)local_44 * (longlong)(int)local_44 +
              (longlong)(int)local_4c * (longlong)(int)local_4c +
              (longlong)(int)local_48 * (longlong)(int)local_48;
      uVar11 = (uint)lVar2;
      uVar16 = param_1 + 0x30U & 3;
      uVar7 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
      iVar9 = (int)((ulonglong)lVar2 >> 0x20) -
              ((uVar7 >> uVar16 * 8 | uVar7 << uVar16 * -8 + 0x20) + (uint)(uVar11 < uVar5));
      uVar16 = local_5c;
      if (-1 < iVar9) {
        uVar16 = uVar11 - uVar5 >> 0xc | iVar9 * 0x100000;
      }
      if (uVar16 != 0) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(&local_4c),&local_40);
        uVar16 = param_1 + 0x28U & 3;
        uVar5 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
        uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
        local_40 = (uint)((longlong)(int)local_40 * (longlong)(int)uVar16) >> 0xc |
                   (int)((ulonglong)((longlong)(int)local_40 * (longlong)(int)uVar16) >> 0x20) <<
                   0x14;
        local_3c = (uint)((longlong)(int)local_3c * (longlong)(int)uVar16) >> 0xc |
                   (int)((ulonglong)((longlong)(int)local_3c * (longlong)(int)uVar16) >> 0x20) <<
                   0x14;
        local_38 = (uint)((longlong)(int)local_38 * (longlong)(int)uVar16) >> 0xc |
                   (int)((ulonglong)((longlong)(int)local_38 * (longlong)(int)uVar16) >> 0x20) <<
                   0x14;
        VecFx32_Add((uint)(uintptr_t)(puVar14),(uint)(uintptr_t)(&local_40),(int *)(uintptr_t)(uVar19 + iVar18));
        VecFx32_Subtract((uint)(uintptr_t)(&local_40),(uint)(uintptr_t)(&local_4c),&local_4c);
        local_50 = (int)local_48 >> 0x1f;
        local_58 = local_44;
        local_54 = (int)local_44 >> 0x1f;
        uVar16 = param_1 + 0x24U & 3;
        uVar5 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
        iVar9 = (uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20) * iVar20;
        lVar2 = (longlong)
                (int)((uint)((ulonglong)local_74 * (ulonglong)local_4c) >> 0xc |
                     (((int)local_4c >> 0x1f) * local_74 +
                     local_4c * local_70 + (int)((ulonglong)local_74 * (ulonglong)local_4c >> 0x20))
                     * 0x100000) * (longlong)iVar9;
        local_4c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        lVar2 = (longlong)
                (int)((uint)((ulonglong)local_6c * (ulonglong)local_48) >> 0xc |
                     (local_50 * local_6c +
                     local_48 * local_68 + (int)((ulonglong)local_6c * (ulonglong)local_48 >> 0x20))
                     * 0x100000) * (longlong)iVar9;
        lVar3 = (longlong)
                (int)((uint)((ulonglong)local_64 * (ulonglong)local_44) >> 0xc |
                     (local_54 * local_64 +
                     local_44 * local_60 + (int)((ulonglong)local_64 * (ulonglong)local_44 >> 0x20))
                     * 0x100000) * (longlong)iVar9;
        local_48 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        local_44 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
        VecFx32_Add(local_7c + iVar18,(uint)(uintptr_t)(&local_4c),(int *)(uintptr_t)(local_7c + iVar18));
      }
      puVar14 = puVar14 + -3;
      iVar20 = iVar20 + -1;
    } while (1 < iVar20);
  }
  uVar16 = param_1 + 8U & 3;
  uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (uVar5 >> uVar16 * 8 == 0 && uVar5 << uVar16 * -8 + 0x20 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = 1;
  }
  if (iVar9 < (int)uVar21) {
    iVar18 = iVar9 * 0xc + uVar19;
    iVar20 = iVar18;
    do {
      iVar15 = (iVar9 + -1) * 0xc + uVar19;
      VecFx32_Subtract(iVar20,iVar15,&local_4c);
      uVar16 = param_1 + 0x2cU & 3;
      uVar5 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      uVar5 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
      lVar2 = (longlong)(int)local_44 * (longlong)(int)local_44 +
              (longlong)(int)local_4c * (longlong)(int)local_4c +
              (longlong)(int)local_48 * (longlong)(int)local_48;
      uVar7 = (uint)lVar2;
      uVar16 = param_1 + 0x30U & 3;
      uVar11 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
      iVar17 = (int)((ulonglong)lVar2 >> 0x20) -
               ((uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20) + (uint)(uVar7 < uVar5));
      if (iVar17 < 0) {
        uVar16 = 0;
      }
      else {
        uVar16 = uVar7 - uVar5 >> 0xc | iVar17 * 0x100000;
      }
      if (uVar16 != 0) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(&local_4c),&local_40);
        uVar16 = param_1 + 0x28U & 3;
        uVar5 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
        uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
        local_40 = (uint)((longlong)(int)local_40 * (longlong)(int)uVar16) >> 0xc |
                   (int)((ulonglong)((longlong)(int)local_40 * (longlong)(int)uVar16) >> 0x20) <<
                   0x14;
        local_3c = (uint)((longlong)(int)local_3c * (longlong)(int)uVar16) >> 0xc |
                   (int)((ulonglong)((longlong)(int)local_3c * (longlong)(int)uVar16) >> 0x20) <<
                   0x14;
        local_38 = (uint)((longlong)(int)local_38 * (longlong)(int)uVar16) >> 0xc |
                   (int)((ulonglong)((longlong)(int)local_38 * (longlong)(int)uVar16) >> 0x20) <<
                   0x14;
        VecFx32_Add(iVar15,(uint)(uintptr_t)(&local_40),(int *)(uintptr_t)(iVar18));
      }
      iVar9 = iVar9 + 1;
      iVar20 = iVar20 + 0xc;
      iVar18 = iVar18 + 0xc;
    } while (iVar9 < (int)uVar21);
  }
  iVar9 = uVar21 - 2;
  ppuVar22 = &local_80;
  if (iVar9 < 2) {
    ppuVar22 = (undefined4 **)&stack0xffffffdc;
  }
  iVar20 = 1;
  if (iVar9 == 1 || (int)(uVar21 - 3) < 0 != SBORROW4(iVar9,1)) {
    return;
  }
  piVar4 = *(int **)((int)ppuVar22 + 4);
  do {
    piVar12 = piVar4 + 3;
    uVar16 = uVar19 + 0x10 & 3;
    uVar5 = *(uint *)(uVar19 + 0x10 & 0xfffffffc);
    if ((int)((uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20) - *(int *)((int)ppuVar22 + 8)) < 0
       ) {
      *(undefined4 *)(uVar19 + 0x10) = *(undefined4 *)((int)ppuVar22 + 8);
      uVar16 = (uint)(piVar4 + 4) & 3;
      uVar5 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
      if ((int)(uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20) < 0) {
        piVar4[4] = 0;
      }
      *piVar12 = (int)((*(uint *)((uint)piVar12 & 0xfffffffc) >> ((uint)piVar12 & 3) * 8 |
                       *(uint *)((uint)piVar12 & 0xfffffffc) << ((uint)piVar12 & 3) * -8 + 0x20) * 7
                      ) >> 3;
      uVar16 = (uint)(piVar4 + 5) & 3;
      uVar5 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
      piVar4[5] = (int)((uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20) * 7) >> 3;
    }
    iVar20 = iVar20 + 1;
    piVar4 = piVar12;
    uVar19 = uVar19 + 0xc;
  } while (iVar20 < iVar9);
  return;
}

