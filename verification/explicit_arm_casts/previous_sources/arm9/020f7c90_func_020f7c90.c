/* Decompiled C draft; module arm9; ROM address 020f7c90. No matching claim. */
#include "types.h"
#include "deps/020f7c90_func_020f7c90.h"

void func_020f7c90(int param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  bool bVar17;
  uint uVar10;
  
  uVar10 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) & 0x2000000) != 0) {
    uVar10 = param_3 + 4 & 3;
    uVar3 = *(uint *)(param_3 + 4 & 0xfffffffc);
    uVar8 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
    uVar3 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
            *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
    uVar10 = param_3 + 8 & 3;
    uVar9 = *(uint *)(param_3 + 8 & 0xfffffffc);
    uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar10 * (longlong)(int)uVar10 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar8 * (longlong)(int)uVar8;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(param_3,param_3);
    }
    iVar4 = VecFx32_CrossProduct_0(param_3,param_1 + 0x108);
    uVar10 = uRam020f7e98;
    if (0x800 < iVar4) {
      uVar3 = param_3 + 8 & 3;
      uVar8 = *(uint *)(param_3 + 8 & 0xfffffffc);
      uVar3 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
      lVar1 = (ulonglong)uRam020f7e98 * (ulonglong)uVar3;
      *(uint *)(param_1 + 100) =
           (uint)lVar1 >> 0xc |
           (((int)uVar3 >> 0x1f) * uRam020f7e98 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar3 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
              *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
      lVar1 = (ulonglong)uVar10 * (ulonglong)uVar3;
      *(uint *)(param_1 + 0x5c) =
           (uint)lVar1 >> 0xc |
           (((int)uVar3 >> 0x1f) * uVar10 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    }
  }
  uVar10 = param_1 + 0x54U & 3;
  uVar6 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  uVar3 = param_2 + 4 & 3;
  uVar9 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar8 = param_1 + 0x50U & 3;
  uVar15 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
  iVar4 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) -
          (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20);
  uVar10 = param_1 + 0x58U & 3;
  uVar9 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  iVar16 = (uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20) -
           (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  uVar3 = param_2 + 8 & 3;
  uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
  iVar5 = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) -
          (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20);
  uVar10 = param_1 + 0xe0U & 3;
  uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  uVar10 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
  lVar1 = (longlong)iVar5 * (longlong)iVar5 +
          (longlong)iVar16 * (longlong)iVar16 + (longlong)iVar4 * (longlong)iVar4;
  iVar5 = (int)((ulonglong)lVar1 >> 0x20);
  lVar2 = (longlong)(int)uVar10 * (longlong)(int)uVar10;
  iVar4 = (int)((ulonglong)lVar2 >> 0x20);
  bVar17 = (uint)lVar1 < (uint)lVar2;
  if ((int)(iVar5 - (iVar4 + (uint)bVar17)) < 0 ==
      (SBORROW4(iVar5,iVar4) != SBORROW4(iVar5 - iVar4,(uint)bVar17))) {
    return;
  }
  uVar10 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20 | 0x4000000;
  uVar10 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) & 0x2000000) != 0) {
    return;
  }
  iVar4 = VecFx32_CrossProduct_0(param_1 + 0x5c,param_3);
  if (iVar4 < 0) {
    uVar14 = *(uint *)(uRam020f7e9c & 0xfffffffc) >> (uRam020f7e9c & 3) * 8 |
             *(uint *)(uRam020f7e9c & 0xfffffffc) << (uRam020f7e9c & 3) * -8 + 0x20;
    uVar10 = uVar14 + 0x47c & 3;
    uVar3 = *(uint *)(uVar14 + 0x47c & 0xfffffffc);
    uVar7 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
    iVar4 = uVar14 + iRam020f7ea0;
    uVar10 = iVar4 + 8U & 3;
    uVar3 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uVar11 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
    uVar10 = iVar4 + 4U & 3;
    uVar9 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar11;
    uVar13 = (uint)lVar1;
    uVar3 = iVar4 + 0xcU & 3;
    uVar6 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar8 = iVar4 + 0x10U & 3;
    uVar15 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
    uVar12 = uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20;
    uVar8 = iVar4 + 0x14U & 3;
    uVar15 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    *(uint *)(uVar14 + 0x47c) = uVar12 + uVar13;
    *(uint *)(iVar4 + 4) =
         (uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20) +
         (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * uVar7 +
         uVar11 * (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) +
         (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar12,uVar13);
    iVar5 = iRam020f7ea4;
    uVar3 = uRam020f7e98;
    uVar10 = iVar4 + 4U & 3;
    uVar8 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    iVar4 = (int)((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) >> 0x10) >> 4;
    *(int *)(param_1 + 0x110) = (int)*(short *)(iRam020f7ea4 + (iVar4 * 2 + 1) * 2);
    *(int *)(param_1 + 0x108) = (int)*(short *)(iVar5 + iVar4 * 4);
    uVar10 = param_1 + 0x110U & 3;
    uVar8 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
    uVar10 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
    lVar1 = (ulonglong)uVar3 * (ulonglong)uVar10;
    *(uint *)(param_1 + 100) =
         (uint)lVar1 >> 0xc |
         (((int)uVar10 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar10 = param_1 + 0x108U & 3;
    uVar8 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
    uVar10 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
    lVar1 = (ulonglong)uVar3 * (ulonglong)uVar10;
    *(uint *)(param_1 + 0x5c) =
         (uint)lVar1 >> 0xc |
         (((int)uVar10 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar10 = param_1 + 0x74U & 3;
    uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20 | 0x2000000;
    return;
  }
  return;
}

