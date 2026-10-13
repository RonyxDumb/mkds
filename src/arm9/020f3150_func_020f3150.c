/* Decompiled C draft; module arm9; ROM address 020f3150. No matching claim. */
#include "types.h"
#include "deps/020f3150_func_020f3150.h"

void func_020f3150(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                  int param_6,int param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int unaff_r4;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar19;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint uVar18;
  
  uVar4 = VecFx32_CrossProduct_0(param_2 + 0x6c,param_2 + 0x44);
  uVar7 = param_2 + 0x10U & 3;
  uVar6 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x48;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  bVar19 = ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 1) != 0;
  if (bVar19) {
    unaff_r4 = 1;
  }
  uVar7 = (uint)((ulonglong)uVar4 * 0x1ec) >> 0xc |
          (((int)uVar4 >> 0x1f) * 0x1ec + (int)((ulonglong)uVar4 * 0x1ec >> 0x20)) * 0x100000;
  if (!bVar19) {
    unaff_r4 = 0;
  }
  if ((int)uVar7 < (int)uRam020f355c) {
    uVar7 = uRam020f355c;
  }
  if (param_4 == 0) {
    iVar5 = func_020edb8c(param_2,uVar7,0x1000,0x7000);
  }
  else {
    iVar5 = func_020edc9c(param_2,param_5,uRam020f3560,0x7000);
    uVar7 = param_2 + 0x7cU & 3;
    uVar6 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    if (0 < (int)uVar7) {
      iVar5 = iVar5 + ((uint)((ulonglong)uRam020f3564 * (ulonglong)uVar7) >> 0xc |
                      (((int)uVar7 >> 0x1f) * uRam020f3564 +
                      (int)((ulonglong)uRam020f3564 * (ulonglong)uVar7 >> 0x20)) * 0x100000);
    }
  }
  uVar7 = param_2 + 0x68U & 3;
  uVar6 = *(uint *)(param_2 + 0x68U & 0xfffffffc);
  if ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < 0x3000) {
    uVar14 = *(uint *)(uRam020f3568 & 0xfffffffc) >> (uRam020f3568 & 3) * 8 |
             *(uint *)(uRam020f3568 & 0xfffffffc) << (uRam020f3568 & 3) * -8 + 0x20;
    iVar13 = uVar14 + iRam020f356c;
    uVar7 = iVar13 + 8U & 3;
    uVar6 = *(uint *)(iVar13 + 8U & 0xfffffffc);
    uVar16 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = uVar14 + 0x47c & 3;
    uVar6 = *(uint *)(uVar14 + 0x47c & 0xfffffffc);
    uVar15 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = iVar13 + 4U & 3;
    uVar11 = *(uint *)(iVar13 + 4U & 0xfffffffc);
    lVar3 = (ulonglong)uVar15 * (ulonglong)uVar16;
    uVar9 = (uint)lVar3;
    uVar6 = iVar13 + 0xcU & 3;
    uVar12 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
    uVar4 = iVar13 + 0x10U & 3;
    uVar17 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
    uVar18 = uVar17 >> uVar4 * 8 | uVar17 << uVar4 * -8 + 0x20;
    uVar4 = iVar13 + 0x14U & 3;
    uVar17 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
    *(uint *)(uVar14 + 0x47c) = uVar18 + uVar9;
    *(uint *)(iVar13 + 4) =
         (uVar17 >> uVar4 * 8 | uVar17 << uVar4 * -8 + 0x20) +
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * uVar15 +
         uVar16 * (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
         (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar18,uVar9);
    uVar7 = iVar13 + 4U & 3;
    uVar6 = *(uint *)(iVar13 + 4U & 0xfffffffc);
    local_28 = local_28 +
               (int)((ulonglong)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 0xf6 >> 0x20) +
               -0x7b;
    uVar7 = iVar13 + 0x14U & 3;
    uVar11 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
    uVar6 = iVar13 + 8U & 3;
    uVar4 = *(uint *)(iVar13 + 8U & 0xfffffffc);
    uVar15 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    uVar6 = iVar13 + 0xcU & 3;
    uVar12 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
    uVar4 = iVar13 + 4U & 3;
    uVar16 = *(uint *)(iVar13 + 4U & 0xfffffffc);
    uVar9 = uVar14 + 0x47c & 3;
    uVar17 = *(uint *)(uVar14 + 0x47c & 0xfffffffc);
    uVar17 = uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20;
    uVar9 = iVar13 + 0x10U & 3;
    uVar18 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
    uVar18 = uVar18 >> uVar9 * 8 | uVar18 << uVar9 * -8 + 0x20;
    lVar3 = (ulonglong)uVar17 * (ulonglong)uVar15;
    uVar9 = (uint)lVar3;
    *(uint *)(uVar14 + 0x47c) = uVar18 + uVar9;
    *(uint *)(iVar13 + 4) =
         (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * uVar17 +
         uVar15 * (uVar16 >> uVar4 * 8 | uVar16 << uVar4 * -8 + 0x20) +
         (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar18,uVar9);
    uVar7 = iVar13 + 4U & 3;
    uVar6 = *(uint *)(iVar13 + 4U & 0xfffffffc);
    local_30 = local_30 +
               (int)((ulonglong)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 0xf6 >> 0x20) +
               -0x7b;
  }
  local_30 = (uint)((longlong)(int)local_30 * (longlong)iVar5) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_30 * (longlong)iVar5) >> 0x20) << 0x14;
  local_2c = (uint)((longlong)(int)local_2c * (longlong)iVar5) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_2c * (longlong)iVar5) >> 0x20) << 0x14;
  local_28 = (uint)((longlong)(int)local_28 * (longlong)iVar5) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_28 * (longlong)iVar5) >> 0x20) << 0x14;
  if (unaff_r4 == 0) {
    if (param_4 == 0) {
      uVar7 = param_2 + 0x70U & 3;
      uVar6 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      uVar7 = uRam020f355c;
      if ((int)uVar6 < 1) {
        uVar7 = uRam020f3570;
      }
      lVar3 = (longlong)(int)uVar7 * (longlong)(int)uVar6;
      param_7 = param_7 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    }
    else {
      uVar7 = param_2 + 0x68U & 3;
      uVar6 = *(uint *)(param_2 + 0x68U & 0xfffffffc);
      uVar4 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      uVar7 = param_2 + 0x70U & 3;
      uVar6 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      param_7 = param_6 + ((uVar4 << 9) >> 0xc | (((int)uVar4 >> 0x1f) << 9 | uVar4 >> 0x17) << 0x14
                          ) + ((uVar7 << 0xd) >> 0xc | (uVar7 >> 0x13) << 0x14);
    }
    VecFx32_AddScale1(param_7,param_2 + 0x38,(uint)(uintptr_t)(&local_30),(int *)(uintptr_t)(param_1 + 0x5c));
  }
  if (param_4 == 0) {
    uVar7 = param_2 + 0x10U & 3;
    uVar6 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    VecFx32_Add(param_1 + 0x5c,(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x1fc,
                (int *)(uintptr_t)(param_1 + 0x5c));
    uVar7 = param_2 + 0x7cU & 3;
    uVar6 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
    if (((uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) &&
        (uVar7 = param_2 + 0x68U & 3, uVar6 = *(uint *)(param_2 + 0x68U & 0xfffffffc),
        (int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < 0x2000)) &&
       (uVar7 = param_1 + 0x70U & 3, uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc),
       (int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < iRam020f3574)) {
      VecFx32_Subtract(param_2 + 0x38,param_2 + 0x44,&local_30);
      VecFx32_AddScale1(0x2000,(uint)(uintptr_t)(&local_30),param_1 + 0x50,(int *)(uintptr_t)(param_1 + 0x50));
    }
  }
  else {
    uVar7 = param_2 + 0x10U & 3;
    uVar6 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar8 = *(undefined4 *)(uVar7 + 0x1bc);
    uVar10 = *(undefined4 *)(uVar7 + 0x1c0);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(uVar7 + 0x1b8);
    *(undefined4 *)(param_1 + 0x54) = uVar8;
    *(undefined4 *)(param_1 + 0x58) = uVar10;
    uVar7 = param_1 + 0x70U & 3;
    uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    VecFx32_AddScale1((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 10,param_2 + 0x44,
                      (undefined4 *)(param_1 + 0x50));
  }
  iVar5 = iRam020f3574;
  uVar7 = param_1 + 0x70U & 3;
  uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  if ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < iRam020f3574) {
    *(int *)(param_1 + 0x68) = iRam020f3574;
    *(int *)(param_1 + 0x6c) = iVar5;
    *(int *)(param_1 + 0x70) = iVar5;
  }
  uVar8 = uRam020f3578;
  *(undefined4 *)(param_1 + 300) = param_3;
  *(undefined4 *)(param_1 + 0x124) = uVar8;
  uVar7 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xf8ffffff;
  if (unaff_r4 != 0) {
    iVar5 = Vector3_DotProduct(param_2 + 0x38,param_1 + 0x5c);
    uVar7 = param_2 + 0x38U & 3;
    uVar4 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar6 = param_2 + 0x3cU & 3;
    uVar9 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    lVar3 = (longlong)(int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * (longlong)iVar5;
    lVar1 = (longlong)(int)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) * (longlong)iVar5;
    uVar7 = param_2 + 0x40U & 3;
    uVar6 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * (longlong)iVar5;
    uVar7 = param_1 + 0x5cU & 3;
    uVar6 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
    *(uint *)(param_1 + 0x5c) =
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) -
         ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    uVar7 = param_1 + 0x60U & 3;
    uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    *(uint *)(param_1 + 0x60) =
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) -
         ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar7 = param_1 + 100U & 3;
    uVar6 = *(uint *)(param_1 + 100U & 0xfffffffc);
    *(uint *)(param_1 + 100) =
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) -
         ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    if (param_4 == 0) {
      uVar8 = 0xfffff000;
    }
    else {
      uVar8 = 0x8800;
    }
    VecFx32_AddScale1(uVar8,param_2 + 0x38,param_1 + 0x5c,(int *)(uintptr_t)(param_1 + 0x5c));
    *(undefined4 *)(param_1 + 300) = 0;
    return;
  }
  return;
}

