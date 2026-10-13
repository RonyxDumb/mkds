/* Decompiled C draft; module arm9; ROM address 0201b560. No matching claim. */
#include "types.h"
#include "deps/0201b560_func_0201b560.h"

void func_0201b560(int param_1,int param_2)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  uint uStack_84;
  uint uStack_80;
  uint uStack_7c;
  undefined1 auStack_78 [36];
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  uint uVar12;
  
  uVar7 = (uint)*(ushort *)(param_2 + 0x2e);
  uVar11 = param_1 + 0x40U & 3;
  uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar11 = (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x20;
  uVar14 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar12 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
  iVar9 = (int)((uVar7 & 0x1f) * (((uVar7 << 0x16) >> 0x1b) + 1)) >> 5;
  uVar11 = param_1 + 0x3cU & 3;
  uVar6 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  uVar14 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  sVar1 = *(short *)((uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) + 0x30);
  uVar14 = param_1 + 0x44U & 3;
  uVar12 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar14 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
  *puRam0201bc38 =
       uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20 | 0xc0 | ((uVar7 << 0x10) >> 0x1a) << 0x18
       | iVar9 << 0x10;
  if (iVar9 == 0) {
    return;
  }
  uVar11 = param_2 + 0x30U & 3;
  uVar6 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  uVar12 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
  uVar11 = param_1 + 0x40U & 3;
  uVar6 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar11 = (uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) + 0x20;
  uVar6 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar12 * (longlong)(int)sVar1 + 0x800;
  uVar11 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
  uVar11 = uVar7 + 0x48 & 3;
  uVar6 = *(uint *)(uVar7 + 0x48 & 0xfffffffc);
  uVar15 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  uVar11 = ((uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) << 1) >> 0x1d;
  if (uVar11 == 0) {
    uVar11 = (uint)*(short *)(param_2 + 0x34);
    uVar6 = (uint)((ulonglong)uVar11 * (ulonglong)uVar12);
    lVar2 = (longlong)(int)uVar15 * (longlong)(int)uVar11 + 0x800;
    uVar15 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uVar12 = uVar6 + 0x800 >> 0xc |
             (((int)uVar12 >> 0x1f) * uVar11 +
              uVar12 * ((int)uVar11 >> 0x1f) + (int)((ulonglong)uVar11 * (ulonglong)uVar12 >> 0x20)
             + (uint)(0xfffff7ff < uVar6)) * 0x100000;
  }
  else if (uVar11 == 1) {
    lVar2 = (longlong)(int)uVar15 * (longlong)(int)*(short *)(param_2 + 0x34) + 0x800;
    uVar15 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  }
  else if (uVar11 == 2) {
    uVar11 = (uint)*(short *)(param_2 + 0x34);
    uVar6 = (uint)((ulonglong)uVar11 * (ulonglong)uVar12);
    uVar12 = uVar6 + 0x800 >> 0xc |
             (((int)uVar12 >> 0x1f) * uVar11 +
              uVar12 * ((int)uVar11 >> 0x1f) + (int)((ulonglong)uVar11 * (ulonglong)uVar12 >> 0x20)
             + (uint)(0xfffff7ff < uVar6)) * 0x100000;
  }
  if ((int)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) << 8) < 0) {
    uVar11 = param_2 + 8U & 3;
    uVar13 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar6 = param_2 + 0x38U & 3;
    uVar10 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar8 = uVar7 + 4 & 3;
    uVar7 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    iStack_9c = ((uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) +
                (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20)) -
                (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
    uVar11 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar6 = param_2 + 0xcU & 3;
    uVar13 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar11 = (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) + 0x20;
    uVar7 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar8 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x3cU & 3;
    uVar10 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    uVar11 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 8;
    uVar8 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    iStack_98 = ((uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) +
                (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20)) -
                (uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20);
    uVar11 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar6 = param_2 + 0x10U & 3;
    uVar13 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar11 = (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) + 0x20;
    uVar7 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar8 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x40U & 3;
    uVar10 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    uVar11 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0xc;
    uVar8 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    iStack_94 = ((uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) +
                (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20)) -
                (uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20);
    iStack_90 = *(int *)(param_2 + 0x14);
    iStack_8c = *(int *)(param_2 + 0x18);
    iStack_88 = *(int *)(param_2 + 0x1c);
    uVar11 = uVar14 + 8 & 3;
    uVar6 = *(uint *)(uVar14 + 8 & 0xfffffffc);
    uStack_84 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    uVar11 = uVar14 + 0x14 & 3;
    uVar6 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
    uStack_80 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    uVar11 = uVar14 + 0x20 & 3;
    uVar6 = *(uint *)(uVar14 + 0x20 & 0xfffffffc);
    uStack_7c = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    VecFx32_CrossProduct((uint)(uintptr_t)(&iStack_90),(uint)(uintptr_t)(&uStack_84),&iStack_90);
    if (((iStack_90 == 0) && (iStack_8c == 0)) && (iStack_88 == 0)) {
      return;
    }
    VecFx32_Normalize((uint)(uintptr_t)(&iStack_90),&iStack_90);
    asm_MI_Copy36B((undefined4 *)(uintptr_t)(uVar14),(undefined4 *)(void *)(auStack_78));
    MTX_MultVec33((uint)(uintptr_t)(&iStack_90),(uint)(uintptr_t)(auStack_78),&iStack_90);
    func_02147288((uint)(uintptr_t)(&iStack_9c),uVar14,&iStack_9c);
    iStack_a8 = *(int *)(param_2 + 0x14);
    iStack_a4 = *(int *)(param_2 + 0x18);
    iStack_a0 = *(int *)(param_2 + 0x1c);
    VecFx32_Normalize((uint)(uintptr_t)(&iStack_a8),&iStack_a8);
    uVar11 = uVar14 + 0x20 & 3;
    uVar6 = *(uint *)(uVar14 + 0x20 & 0xfffffffc);
    lVar2 = (longlong)iStack_a0 *
            (longlong)(int)-(uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) + 0x800;
    uVar11 = uVar14 + 0x14 & 3;
    uVar7 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
    uVar6 = uVar14 + 8 & 3;
    uVar14 = *(uint *)(uVar14 + 8 & 0xfffffffc);
    lVar3 = (longlong)iStack_a8 *
            (longlong)(int)-(uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) + 0x800;
    lVar4 = (longlong)iStack_a4 *
            (longlong)(int)-(uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) + 0x800;
    iVar9 = ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
            ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
            ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
    uVar11 = param_1 + 0x40U & 3;
    uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    uVar11 = (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x20;
    uVar14 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar14 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
    uVar11 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    uVar11 = (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x48;
    uVar14 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    lVar2 = (longlong)(0x1000 - iVar9) *
            (longlong)(int)(((uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) << 8) >> 0x10) +
            0x800;
    lVar2 = (longlong)(int)uVar12 *
            (longlong)
            (int)(((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) + 0x1000) +
            0x800;
    uVar11 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    lVar2 = (longlong)iStack_90 * (longlong)(int)uVar15 + 0x800;
    iStack_30 = iStack_9c;
    iStack_2c = iStack_98;
    lVar3 = (longlong)-iStack_8c * (longlong)(int)uVar11 + 0x800;
    uStack_54 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    lVar2 = (longlong)iStack_8c * (longlong)(int)uVar15 + 0x800;
    lVar4 = (longlong)iStack_90 * (longlong)(int)uVar11 + 0x800;
    uStack_48 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
    uStack_50 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uStack_44 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_4c = 0;
    uStack_40 = 0;
    uStack_34 = 0x1000;
    iStack_28 = iStack_94;
    *puRam0201bc3c = 0;
    puVar5 = puRam0201bc40;
    uVar11 = param_1 + 0x40U & 3;
    uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar11 = (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x20;
    uVar14 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar14 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
    uVar11 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    uVar7 = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
    uVar11 = uVar7 + 0xc & 3;
    uVar15 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    uVar14 = uVar7 + 8 & 3;
    uVar12 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    uVar6 = uVar7 + 4 & 3;
    uVar7 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    *puRam0201bc40 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    *puVar5 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
    *puVar5 = uVar15 >> uVar11 * 8 | uVar15 << uVar11 * -8 + 0x20;
    G3_MultMtx43(&uStack_54);
  }
  else {
    uVar11 = param_2 + 8U & 3;
    uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar6 = param_2 + 0x38U & 3;
    uVar7 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    iStack_9c = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
                (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    uVar11 = param_2 + 0xcU & 3;
    uVar8 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar6 = param_2 + 0x3cU & 3;
    uVar7 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    iStack_98 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
                (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    uVar11 = param_2 + 0x10U & 3;
    uVar8 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar6 = param_2 + 0x40U & 3;
    uVar7 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    iStack_94 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
                (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    iStack_90 = *(int *)(param_2 + 0x14);
    iStack_8c = *(int *)(param_2 + 0x18);
    iStack_88 = *(int *)(param_2 + 0x1c);
    uVar11 = uVar14 + 8 & 3;
    uVar6 = *(uint *)(uVar14 + 8 & 0xfffffffc);
    uStack_84 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    uVar11 = uVar14 + 0x14 & 3;
    uVar6 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
    uStack_80 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    uVar11 = uVar14 + 0x20 & 3;
    uVar6 = *(uint *)(uVar14 + 0x20 & 0xfffffffc);
    uStack_7c = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    VecFx32_CrossProduct((uint)(uintptr_t)(&iStack_90),(uint)(uintptr_t)(&uStack_84),&iStack_90);
    if (((iStack_90 == 0) && (iStack_8c == 0)) && (iStack_88 == 0)) {
      return;
    }
    VecFx32_Normalize((uint)(uintptr_t)(&iStack_90),&iStack_90);
    asm_MI_Copy36B((undefined4 *)(uintptr_t)(uVar14),(undefined4 *)(void *)(auStack_78));
    MTX_MultVec33((uint)(uintptr_t)(&iStack_90),(uint)(uintptr_t)(auStack_78),&iStack_90);
    func_02147288((uint)(uintptr_t)(&iStack_9c),uVar14,&iStack_9c);
    iStack_a8 = *(int *)(param_2 + 0x14);
    iStack_a4 = *(int *)(param_2 + 0x18);
    iStack_a0 = *(int *)(param_2 + 0x1c);
    VecFx32_Normalize((uint)(uintptr_t)(&iStack_a8),&iStack_a8);
    uVar11 = uVar14 + 0x20 & 3;
    uVar6 = *(uint *)(uVar14 + 0x20 & 0xfffffffc);
    lVar2 = (longlong)iStack_a0 *
            (longlong)(int)-(uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) + 0x800;
    uVar11 = uVar14 + 0x14 & 3;
    uVar7 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
    uVar6 = uVar14 + 8 & 3;
    uVar14 = *(uint *)(uVar14 + 8 & 0xfffffffc);
    lVar3 = (longlong)iStack_a8 *
            (longlong)(int)-(uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) + 0x800;
    lVar4 = (longlong)iStack_a4 *
            (longlong)(int)-(uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) + 0x800;
    iVar9 = ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
            ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
            ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
    uVar11 = param_1 + 0x40U & 3;
    uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    uVar11 = (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x20;
    uVar14 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar14 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
    uVar11 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    uVar11 = (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x48;
    uVar14 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    lVar2 = (longlong)(0x1000 - iVar9) *
            (longlong)(int)(((uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) << 8) >> 0x10) +
            0x800;
    lVar2 = (longlong)(int)uVar12 *
            (longlong)
            (int)(((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) + 0x1000) +
            0x800;
    uVar11 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    lVar2 = (longlong)iStack_90 * (longlong)(int)uVar15 + 0x800;
    iStack_30 = iStack_9c;
    iStack_2c = iStack_98;
    uStack_54 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    lVar3 = (longlong)-iStack_8c * (longlong)(int)uVar11 + 0x800;
    lVar2 = (longlong)iStack_8c * (longlong)(int)uVar15 + 0x800;
    lVar4 = (longlong)iStack_90 * (longlong)(int)uVar11 + 0x800;
    uStack_48 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
    uStack_50 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uStack_44 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_4c = 0;
    uStack_40 = 0;
    uStack_34 = 0x1000;
    iStack_28 = iStack_94;
    *puRam0201bc3c = 0;
    G3_MultMtx43(&uStack_54);
  }
  uVar11 = param_1 + 0x40U & 3;
  uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar6 = (uint)*(ushort *)(param_2 + 0x36);
  uVar11 = (uint)*(ushort *)((uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) + 0x72);
  *puRam0201bc44 =
       (int)((uVar6 & 0x1f) * (uVar11 & 0x1f)) >> 5 |
       ((int)((uVar6 & 0x3e0) * (uVar11 & 0x3e0)) >> 0xf) << 5 |
       ((int)((uVar6 & 0x7c00) * (uVar11 & 0x7c00)) >> 0x19) << 10;
  uVar11 = param_1 + 0x40U & 3;
  uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar6 = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
  uVar11 = uVar6 + 0x20 & 3;
  uVar14 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
  uVar14 = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
  uVar11 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  uVar11 = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
  func_0201c690((int)*(short *)(uVar6 + 0x78),(int)*(short *)(uVar6 + 0x7a),
                (int)*(short *)(uVar11 + 0x50),(int)*(short *)(uVar11 + 0x52));
  return;
}

