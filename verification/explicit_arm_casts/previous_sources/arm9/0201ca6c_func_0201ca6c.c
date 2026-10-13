/* Decompiled C draft; module arm9; ROM address 0201ca6c. No matching claim. */
#include "types.h"
#include "deps/0201ca6c_func_0201ca6c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0201ca6c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  int extraout_r1;
  undefined1 *puVar18;
  undefined4 uVar19;
  undefined2 *puVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int local_e0;
  int iStack_d0;
  short sStack_a4;
  short sStack_a2;
  short sStack_a0;
  short sStack_9e;
  short sStack_9c;
  short sStack_9a;
  undefined2 auStack_98 [4];
  uint uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  uint uStack_74;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  uint uStack_48;
  uint uStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  uVar17 = param_1 + 0x20U & 3;
  uVar11 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar11 = uVar11 >> uVar17 * 8 | uVar11 << uVar17 * -8 + 0x20;
  uVar17 = param_1 + 0x58U & 3;
  uVar12 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  iVar21 = (uVar12 >> uVar17 * 8 | uVar12 << uVar17 * -8 + 0x20) + (int)*(short *)(param_1 + 0x4e);
  uVar12 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
           *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
  *(ushort *)(param_1 + 0x4e) = (ushort)iVar21 & (ushort)DAT_0201d778;
  uVar17 = (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
           *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) & 0xf;
  iVar21 = iVar21 >> 0xc;
  if (((uVar17 == 2) || (uVar17 == 3)) || (uVar17 - 5 < 5)) {
    func_0201d8f8(param_1);
  }
  iVar9 = DAT_0201d784;
  iVar8 = DAT_0201d780;
  puVar7 = DAT_0201d77c;
  local_e0 = 0;
  if (iVar21 < 1) {
    return;
  }
  iStack_d0 = 0;
  do {
    iVar13 = func_0201e448(param_2);
    if (iVar13 == 0) {
      return;
    }
    func_0201e494(param_1 + 8,iVar13);
    switch((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
           *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) & 0xf) {
    case 0:
      *(undefined4 *)(iVar13 + 0x10) = 0;
      uVar17 = iVar13 + 0x10U & 3;
      uVar15 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
      *(uint *)(iVar13 + 0xc) = uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20;
      uVar17 = iVar13 + 0xcU & 3;
      uVar15 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
      *(uint *)(iVar13 + 8) = uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20;
      break;
    case 1:
      func_0201e540(iVar13 + 8);
      uVar17 = iVar13 + 8U & 3;
      uVar24 = *(uint *)(iVar13 + 8U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      *(uint *)(iVar13 + 8) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = iVar13 + 0xcU & 3;
      uVar24 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      *(uint *)(iVar13 + 0xc) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = iVar13 + 0x10U & 3;
      uVar24 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      *(uint *)(iVar13 + 0x10) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      break;
    case 2:
      func_0201e4e4(&uStack_90);
      uVar17 = param_1 + 0x5cU & 3;
      uVar15 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)uStack_90 *
              (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 0x800;
      uStack_90 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = param_1 + 0x5cU & 3;
      uVar15 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)uStack_8c *
              (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 0x800;
      uStack_8c = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uStack_88 = 0;
      func_0201d798(iVar13 + 8,&uStack_90,param_1);
      break;
    case 3:
      iVar14 = _s32_div_f(iStack_d0,iVar21);
      iStack_d0 = iStack_d0 + 0x10000;
      uVar17 = param_1 + 0x5cU & 3;
      uVar15 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)*(short *)(DAT_0201d788 + (iVar14 >> 4) * 4) *
              (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 0x800;
      uStack_84 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = param_1 + 0x5cU & 3;
      uVar15 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)*(short *)(DAT_0201d788 + ((iVar14 >> 4) * 2 + 1) * 2) *
              (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 0x800;
      uStack_80 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uStack_7c = 0;
      func_0201d798(iVar13 + 8,&uStack_84,param_1);
      break;
    case 4:
      func_0201e540(iVar13 + 8);
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = iVar13 + 8U & 3;
      uVar22 = *(uint *)(iVar13 + 8U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar24 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar24 >> uVar15 * 8 | uVar24 << uVar15 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      *(uint *)(iVar13 + 8) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = iVar13 + 0xcU & 3;
      uVar22 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar24 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar24 >> uVar15 * 8 | uVar24 << uVar15 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      *(uint *)(iVar13 + 0xc) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = iVar13 + 0x10U & 3;
      uVar22 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar24 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar24 >> uVar15 * 8 | uVar24 << uVar15 * -8 + 0x20) + 0x800;
      lVar4 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      *(uint *)(iVar13 + 0x10) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      break;
    case 5:
      func_0201e4e4(&uStack_78);
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = param_1 + 0x5cU & 3;
      uVar15 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)uStack_78 *
              (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      uStack_78 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar15 = uVar23 * iVar8 + iVar9;
      *puVar7 = uVar15;
      uVar17 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)uStack_74 *
              (longlong)(int)(uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar15 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      uStack_74 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      func_0201d798(iVar13 + 8,&uStack_78,param_1);
      break;
    case 6:
      func_0201e4e4(iVar13 + 0x14);
      uVar17 = iVar13 + 0x14U & 3;
      uVar24 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      uStack_54 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = iVar13 + 0x18U & 3;
      uVar24 = *(uint *)(iVar13 + 0x18U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      uStack_50 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar15 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar15;
      uVar17 = param_1 + 0x60U & 3;
      uVar23 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      uVar17 = uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20;
      iStack_4c = (int)(uVar17 * (uVar15 >> 0x17) + uVar17 * -0x100) >> 8;
      func_0201d798(iVar13 + 8,&uStack_54,param_1);
      break;
    case 7:
      func_0201e4e4(iVar13 + 0x14);
      uVar24 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar24;
      uVar17 = iVar13 + 0x14U & 3;
      uVar22 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar24 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      uStack_48 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar24 = uVar24 * iVar8 + iVar9;
      *puVar7 = uVar24;
      uVar17 = iVar13 + 0x18U & 3;
      uVar22 = *(uint *)(iVar13 + 0x18U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)((int)((uVar24 >> 0x17) * 0x1000 + -0x100000) >> 8) + 0x800;
      uStack_44 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar15 = uVar24 * iVar8 + iVar9;
      *puVar7 = uVar15;
      uVar17 = param_1 + 0x60U & 3;
      uVar23 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      uVar17 = uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20;
      iStack_40 = (int)(uVar17 * (uVar15 >> 0x17) + uVar17 * -0x100) >> 8;
      func_0201d798(iVar13 + 8,&uStack_48,param_1);
      break;
    case 8:
      func_0201e540(iVar13 + 8);
      VecFx16_CrossProduct(param_1 + 0x84,param_1 + 0x8a,&sStack_a4);
      iStack_68 = (int)sStack_a2;
      iStack_64 = (int)sStack_a0;
      iStack_6c = (int)sStack_a4;
      iVar14 = Vector3_DotProduct(&iStack_6c,iVar13 + 8);
      if (iVar14 < 1) {
        uVar17 = iVar13 + 8U & 3;
        uVar15 = *(uint *)(iVar13 + 8U & 0xfffffffc);
        *(uint *)(iVar13 + 8) = -(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20);
        uVar17 = iVar13 + 0xcU & 3;
        uVar15 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
        *(uint *)(iVar13 + 0xc) = -(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20);
        uVar17 = iVar13 + 0x10U & 3;
        uVar15 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
        *(uint *)(iVar13 + 0x10) = -(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20);
      }
      uVar17 = iVar13 + 8U & 3;
      uVar24 = *(uint *)(iVar13 + 8U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      *(uint *)(iVar13 + 8) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = iVar13 + 0xcU & 3;
      uVar24 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      *(uint *)(iVar13 + 0xc) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar17 = iVar13 + 0x10U & 3;
      uVar24 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar23 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) + 0x800;
      *(uint *)(iVar13 + 0x10) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      break;
    case 9:
      func_0201e540(iVar13 + 8);
      VecFx16_CrossProduct(param_1 + 0x84,param_1 + 0x8a,&sStack_9e);
      iStack_5c = (int)sStack_9c;
      iStack_58 = (int)sStack_9a;
      iStack_60 = (int)sStack_9e;
      iVar14 = Vector3_DotProduct(&iStack_60,iVar13 + 8);
      if (iVar14 < 0) {
        uVar17 = iVar13 + 8U & 3;
        uVar15 = *(uint *)(iVar13 + 8U & 0xfffffffc);
        *(uint *)(iVar13 + 8) = -(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20);
        uVar17 = iVar13 + 0xcU & 3;
        uVar15 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
        *(uint *)(iVar13 + 0xc) = -(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20);
        uVar17 = iVar13 + 0x10U & 3;
        uVar15 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
        *(uint *)(iVar13 + 0x10) = -(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20);
      }
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = iVar13 + 8U & 3;
      uVar22 = *(uint *)(iVar13 + 8U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar24 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar24 >> uVar15 * 8 | uVar24 << uVar15 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)(((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 9) + 0x800) + 0x800;
      *(uint *)(iVar13 + 8) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = iVar13 + 0xcU & 3;
      uVar22 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar24 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar24 >> uVar15 * 8 | uVar24 << uVar15 * -8 + 0x20) + 0x800;
      lVar3 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)(((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 9) + 0x800) + 0x800;
      *(uint *)(iVar13 + 0xc) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      uVar23 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar23;
      uVar17 = iVar13 + 0x10U & 3;
      uVar22 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
      uVar15 = param_1 + 0x5cU & 3;
      uVar24 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar22 >> uVar17 * 8 | uVar22 << uVar17 * -8 + 0x20) *
              (longlong)(int)(uVar24 >> uVar15 * 8 | uVar24 << uVar15 * -8 + 0x20) + 0x800;
      lVar5 = (longlong)(int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) *
              (longlong)(((int)((uVar23 >> 0x17) * 0x1000 + -0x100000) >> 9) + 0x800) + 0x800;
      *(uint *)(iVar13 + 0x10) = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000;
    }
    uVar15 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
             *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 + iVar9
    ;
    *puVar7 = uVar15;
    uVar17 = param_1 + 100U & 3;
    uVar23 = *(uint *)(param_1 + 100U & 0xfffffffc);
    iVar14 = (int)((uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20) *
                  ((*(byte *)(uVar12 + 0x42) + 0xff) -
                  ((int)((uint)*(byte *)(uVar12 + 0x42) * (uVar15 >> 0x18)) >> 7))) >> 8;
    uVar15 = uVar15 * iVar8 + iVar9;
    *puVar7 = uVar15;
    uVar17 = param_1 + 0x68U & 3;
    uVar23 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
    iVar1 = (int)((uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20) *
                 ((*(byte *)(uVar12 + 0x42) + 0xff) -
                 ((int)((uint)*(byte *)(uVar12 + 0x42) * (uVar15 >> 0x18)) >> 7))) >> 8;
    if (((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
         *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) & 0xf) == 6) {
      uVar17 = iVar13 + 0x14U & 3;
      uVar15 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) *
              (longlong)(int)*(short *)(param_1 + 0x84) + 0x800;
      uVar17 = iVar13 + 0x18U & 3;
      uVar15 = *(uint *)(iVar13 + 0x18U & 0xfffffffc);
      lVar6 = (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) *
              (longlong)(int)*(short *)(param_1 + 0x8a) + 0x800;
      iStack_30 = ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
                  ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000);
      uVar17 = iVar13 + 0x14U & 3;
      uVar15 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) *
              (longlong)(int)*(short *)(param_1 + 0x86) + 0x800;
      uVar17 = iVar13 + 0x18U & 3;
      uVar15 = *(uint *)(iVar13 + 0x18U & 0xfffffffc);
      lVar6 = (longlong)(int)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) *
              (longlong)(int)*(short *)(param_1 + 0x8c) + 0x800;
      iStack_2c = ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
                  ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000);
      uVar17 = iVar13 + 0x18U & 3;
      uVar24 = *(uint *)(iVar13 + 0x18U & 0xfffffffc);
      uVar15 = iVar13 + 0x14U & 3;
      uVar23 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20) *
              (longlong)(int)*(short *)(param_1 + 0x88) + 0x800;
      lVar6 = (longlong)(int)(uVar24 >> uVar17 * 8 | uVar24 << uVar17 * -8 + 0x20) *
              (longlong)(int)*(short *)(param_1 + 0x8e) + 0x800;
      iStack_28 = ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
                  ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000);
      VecFx32_Normalize(&iStack_30,&iStack_3c);
    }
    else {
      uVar17 = iVar13 + 8U & 3;
      uVar15 = *(uint *)(iVar13 + 8U & 0xfffffffc);
      if (((uVar15 >> uVar17 * 8 == 0 && uVar15 << uVar17 * -8 + 0x20 == 0) &&
          (uVar17 = iVar13 + 0xcU & 3, uVar15 = *(uint *)(iVar13 + 0xcU & 0xfffffffc),
          uVar15 >> uVar17 * 8 == 0 && uVar15 << uVar17 * -8 + 0x20 == 0)) &&
         (uVar17 = iVar13 + 0x10U & 3, uVar15 = *(uint *)(iVar13 + 0x10U & 0xfffffffc),
         uVar15 >> uVar17 * 8 == 0 && uVar15 << uVar17 * -8 + 0x20 == 0)) {
        func_0201e540(&iStack_3c);
      }
      else {
        VecFx32_Normalize(iVar13 + 8,&iStack_3c);
      }
    }
    lVar3 = (longlong)iStack_3c * (longlong)iVar14 + 0x800;
    uVar17 = param_1 + 0x40U & 3;
    uVar15 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    lVar6 = (longlong)(int)*(short *)(param_1 + 0x50) * (longlong)iVar1 + 0x800;
    *(uint *)(iVar13 + 0x14) =
         (uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) +
         ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
         ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000);
    lVar3 = (longlong)iStack_38 * (longlong)iVar14 + 0x800;
    uVar17 = param_1 + 0x44U & 3;
    uVar15 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    lVar6 = (longlong)(int)*(short *)(param_1 + 0x52) * (longlong)iVar1 + 0x800;
    *(uint *)(iVar13 + 0x18) =
         (uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) +
         ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
         ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000);
    lVar3 = (longlong)iStack_34 * (longlong)iVar14 + 0x800;
    lVar6 = (longlong)(int)*(short *)(param_1 + 0x54) * (longlong)iVar1 + 0x800;
    uVar17 = param_1 + 0x48U & 3;
    uVar15 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(iVar13 + 0x1c) =
         (uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) +
         ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
         ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000);
    uVar16 = *(undefined4 *)(param_1 + 0x2c);
    uVar19 = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(iVar13 + 0x38) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar13 + 0x3c) = uVar16;
    *(undefined4 *)(iVar13 + 0x40) = uVar19;
    uVar15 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
             *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 + iVar9
    ;
    *puVar7 = uVar15;
    uVar17 = param_1 + 0x6cU & 3;
    uVar23 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    *(int *)(iVar13 + 0x30) =
         (int)((uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20) *
              ((*(byte *)(uVar12 + 0x40) + 0xff) -
              ((int)((uint)*(byte *)(uVar12 + 0x40) * (uVar15 >> 0x18)) >> 7))) >> 8;
    *(undefined2 *)(iVar13 + 0x34) = 0x1000;
    iVar14 = DAT_0201d78c;
    if (((int)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
               *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) << 0x16) < 0) &&
       (uVar17 = uVar11 + 8 & 3, uVar15 = *(uint *)(uVar11 + 8 & 0xfffffffc),
       (int)((uint)*(ushort *)((uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 8) << 0x1f) <
       0)) {
      uVar17 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar17;
      uVar17 = uVar17 >> 0x14;
      uVar15 = uVar11 + 8 & 3;
      uVar23 = *(uint *)(uVar11 + 8 & 0xfffffffc);
      puVar20 = (undefined2 *)(uVar23 >> uVar15 * 8 | uVar23 << uVar15 * -8 + 0x20);
      auStack_98[0] = *puVar20;
      auStack_98[1] = *(undefined2 *)(uVar12 + 0x22);
      auStack_98[2] = puVar20[1];
      *(undefined2 *)(iVar13 + 0x36) =
           auStack_98[uVar17 - (uint)((ulonglong)DAT_0201d790 * (ulonglong)uVar17 >> 0x21) * iVar14]
      ;
    }
    else {
      *(undefined2 *)(iVar13 + 0x36) = *(undefined2 *)(uVar12 + 0x22);
    }
    *(ushort *)(iVar13 + 0x2e) =
         *(ushort *)(iVar13 + 0x2e) & 0xffe0 | *(byte *)(param_1 + 0x81) & 0x1f;
    *(ushort *)(iVar13 + 0x2e) = *(ushort *)(iVar13 + 0x2e) & 0xfc1f | 0x3e0;
    if ((int)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) << 0x12) < 0) {
      uVar17 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar17;
      *(short *)(iVar13 + 0x20) = (short)uVar17;
    }
    else {
      *(undefined2 *)(iVar13 + 0x20) = *(undefined2 *)(param_1 + 0x56);
    }
    if ((int)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) << 0x13) < 0) {
      uVar17 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar17;
      *(short *)(iVar13 + 0x22) =
           (short)(((int)*(short *)(uVar12 + 0x36) - (int)*(short *)(uVar12 + 0x34)) *
                   (uVar17 >> 0x14) + *(short *)(uVar12 + 0x34) * 0x1000 >> 0xc);
    }
    else {
      *(undefined2 *)(iVar13 + 0x22) = 0;
    }
    uVar17 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
             *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 + iVar9
    ;
    *puVar7 = uVar17;
    *(short *)(iVar13 + 0x24) =
         (short)((uint)*(ushort *)(param_1 + 0x70) *
                 (0xff - ((int)((uint)*(byte *)(uVar12 + 0x41) * (uVar17 >> 0x18)) >> 8)) >> 8) + 1;
    *(undefined2 *)(iVar13 + 0x26) = 0;
    iVar14 = (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
             *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) << 0x14;
    if ((iVar14 < 0) &&
       (uVar17 = uVar11 + 0x10 & 3, uVar15 = *(uint *)(uVar11 + 0x10 & 0xfffffffc),
       uVar17 = (uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) + 8, uVar15 = uVar17 & 3,
       uVar17 = *(uint *)(uVar17 & 0xfffffffc),
       (int)((uVar17 >> uVar15 * 8 | uVar17 << uVar15 * -8 + 0x20) << 0xf) < 0)) {
      uVar15 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar15;
      uVar17 = uVar11 + 0x10 & 3;
      uVar23 = *(uint *)(uVar11 + 0x10 & 0xfffffffc);
      uVar17 = uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20;
      MaybeBoundsCheck(uVar15 >> 0x14,*(undefined1 *)(uVar17 + 8));
      *(undefined1 *)(iVar13 + 0x2c) = *(undefined1 *)(uVar17 + extraout_r1);
    }
    else if ((iVar14 < 0) &&
            (uVar17 = uVar11 + 0x10 & 3, uVar15 = *(uint *)(uVar11 + 0x10 & 0xfffffffc),
            puVar18 = (undefined1 *)(uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20),
            puVar2 = puVar18 + 8, uVar17 = (uint)puVar2 & 3,
            uVar15 = *(uint *)((uint)puVar2 & 0xfffffffc),
            -1 < (int)((uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) << 0xf))) {
      *(undefined1 *)(iVar13 + 0x2c) = *puVar18;
    }
    else {
      *(undefined1 *)(iVar13 + 0x2c) = *(undefined1 *)(uVar12 + 0x47);
    }
    uVar10 = _s32_div_f(DAT_0201d794,
                        *(undefined1 *)
                         ((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                          *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + 0x48));
    *(undefined2 *)(iVar13 + 0x28) = uVar10;
    uVar10 = _s32_div_f(DAT_0201d794,*(undefined2 *)(iVar13 + 0x24));
    *(undefined2 *)(iVar13 + 0x2a) = uVar10;
    *(undefined1 *)(iVar13 + 0x2d) = 0;
    if ((int)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) << 0xb) < 0) {
      uVar17 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) * iVar8 +
               iVar9;
      *puVar7 = uVar17;
      *(char *)(iVar13 + 0x2d) = (char)(uVar17 >> 0x18);
    }
    local_e0 = local_e0 + 1;
  } while (local_e0 < iVar21);
  return;
}

