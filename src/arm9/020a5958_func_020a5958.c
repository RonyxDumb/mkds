/* Decompiled C draft; module arm9; ROM address 020a5958. No matching claim. */
#include "types.h"
#include "deps/020a5958_func_020a5958.h"

void func_020a5958(undefined4 param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  int *piVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar20;
  uint uVar21;
  uint local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [12];
  uint uVar19;
  
  uVar7 = param_2 + 0xe0U & 3;
  uVar3 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  switch(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) {
  case 0:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + DAT_020a6808;
    uVar3 = DAT_020a6808;
    uVar7 = param_2 + 0xa8U & 3;
    uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0xfff < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
    }
    uVar7 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) - uVar3;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,(int *)(uintptr_t)(param_2 + 4));
    uVar7 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    if ((int)uVar4 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      return;
    }
    *(uint *)(param_2 + 8) = uVar4;
    uVar7 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    *(uint *)(param_2 + 0x14) =
         (uint)((ulonglong)DAT_020a680c * (ulonglong)uVar7) >> 0xc |
         (((int)uVar7 >> 0x1f) * DAT_020a680c +
         ((int)((ulonglong)DAT_020a680c * (ulonglong)uVar7 >> 0x20) - uVar7)) * 0x100000;
    uVar11 = DAT_020a6810;
    uVar7 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    if ((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < 0x1000) {
      *(undefined4 *)(param_2 + 0x14) = 0;
      *(undefined4 *)(param_2 + 0xe0) = 1;
    }
    uVar7 = param_2 + 0x94U & 3;
    uVar3 = *(uint *)(param_2 + 0x94U & 0xfffffffc);
    func_0210b98c(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,uVar11);
    return;
  case 1:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + DAT_020a6808;
    uVar11 = DAT_020a6814;
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0xfff < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
    }
    uVar7 = param_2 + 0x94U & 3;
    uVar3 = *(uint *)(param_2 + 0x94U & 0xfffffffc);
    func_0210ba38(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,uVar11);
    return;
  case 2:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 4;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    iVar5 = GetDriverEntry(*(undefined2 *)(param_2 + 200));
    uVar7 = param_2 + 0xa0U & 3;
    uVar10 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) =
         (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) +
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    puVar9 = (undefined4 *)func_020a0ff0(*(undefined2 *)(param_2 + 200));
    uVar11 = puVar9[1];
    uVar14 = puVar9[2];
    *(undefined4 *)(param_2 + 4) = *puVar9;
    *(undefined4 *)(param_2 + 8) = uVar11;
    *(undefined4 *)(param_2 + 0xc) = uVar14;
    iVar20 = func_020a23a0(iVar5);
    uVar7 = param_2 + 0xa0U & 3;
    uVar4 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = param_2 + 8U & 3;
    uVar10 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + iVar20 + 0x7800;
    uVar7 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - DAT_020a6818;
    uVar7 = param_2 + 0xc0U & 3;
    uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    *(uint *)(param_2 + 0xc0) = uVar7 - 1;
    if ((int)uVar7 < 1) {
      *(undefined4 *)(param_2 + 0xc0) = 0;
      uVar7 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - DAT_020a6808;
      uVar7 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      if ((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < 1) {
        *(undefined4 *)(param_2 + 0xa8) = 0;
        func_020d2398(param_2);
        func_020a1218(0xffffffff);
        uVar7 = param_2 + 0xc4U & 3;
        uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
        if (-1 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
          func_020a6cb4();
        }
      }
      uVar7 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      if ((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < 1) {
        uVar11 = func_0208b7bc(0x7c,iVar5 + 0x80);
        func_02081f10(uVar11,*(undefined2 *)(iVar5 + 0x74),0x16);
      }
    }
    else {
      uVar7 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + DAT_020a6808;
      uVar7 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      if (0xfff < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *(undefined4 *)(param_2 + 0xa8) = 0x1000;
      }
    }
    uVar7 = param_2 + 0xe4U & 3;
    uVar3 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    if (uVar7 == 0) {
      return;
    }
    func_0208b5b0(uVar7,param_2 + 4);
    uVar7 = param_2 + 0xe8U & 3;
    uVar3 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    *(uint *)(param_2 + 0xe8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - 1;
    uVar7 = param_2 + 0xe8U & 3;
    uVar3 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    if (-1 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      return;
    }
    func_0208b6b0((undefined4 *)(uintptr_t)(param_2 + 0xe4));
    return;
  case 3:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 4;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    iVar5 = DAT_020a681c;
    iVar20 = 0;
    piVar13 = (int *)(param_2 + 0xdc);
    do {
      uVar4 = func_020a0f0c();
      iVar6 = func_020a0ff0(*(undefined2 *)(param_2 + 200));
      uVar7 = uVar4 + 4 & 3;
      uVar12 = *(uint *)(uVar4 + 4 & 0xfffffffc);
      uVar3 = iVar6 + 4U & 3;
      uVar10 = *(uint *)(iVar6 + 4U & 0xfffffffc);
      iVar6 = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) -
              (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
      if (iVar6 < 1) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x14000) {
        uVar7 = func_020a0ff0(*(undefined2 *)(param_2 + 0xca));
        iVar6 = (int)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) -
                     (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                     *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) >> 0xc;
        iVar8 = func_020a0ff0(*(undefined2 *)(param_2 + 0xca));
        uVar7 = uVar4 + 8 & 3;
        uVar12 = *(uint *)(uVar4 + 8 & 0xfffffffc);
        uVar3 = iVar8 + 8U & 3;
        uVar10 = *(uint *)(iVar8 + 8U & 0xfffffffc);
        iVar8 = (int)((uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) -
                     (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20)) >> 0xc;
        iVar6 = iVar6 * iVar6 + iVar8 * iVar8;
        if (*(short *)(param_2 + 0xca) == *(short *)(param_2 + 200)) {
          if ((iVar6 < iVar5) &&
             (uVar7 = param_2 + 0xd8U & 3, uVar3 = *(uint *)(param_2 + 0xd8U & 0xfffffffc),
             (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < iVar6)) {
            *(int *)(param_2 + 0xd8) = iVar6;
            *(uint *)(param_2 + 0xcc) =
                 *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
            uVar7 = uVar4 + 4 & 3;
            uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc);
            *(uint *)(param_2 + 0xd0) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
            uVar7 = uVar4 + 8 & 3;
            uVar3 = *(uint *)(uVar4 + 8 & 0xfffffffc);
            *(uint *)(param_2 + 0xd4) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
            *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                       *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) + 1
            ;
          }
        }
        else if ((iVar6 < iVar5) &&
                (uVar7 = param_2 + 0xd8U & 3, uVar3 = *(uint *)(param_2 + 0xd8U & 0xfffffffc),
                iVar6 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20))) {
          *(int *)(param_2 + 0xd8) = iVar6;
          *(uint *)(param_2 + 0xcc) =
               *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
               *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
          uVar7 = uVar4 + 4 & 3;
          uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc);
          *(uint *)(param_2 + 0xd0) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
          uVar7 = uVar4 + 8 & 3;
          uVar3 = *(uint *)(uVar4 + 8 & 0xfffffffc);
          *(uint *)(param_2 + 0xd4) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
          *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                     *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) + 1;
        }
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 < 2);
    uVar7 = param_2 + 0xa0U & 3;
    uVar10 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) =
         (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) +
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    puVar9 = (undefined4 *)func_020a0ff0(*(undefined2 *)(param_2 + 200));
    uVar11 = puVar9[1];
    uVar14 = puVar9[2];
    *(undefined4 *)(param_2 + 4) = *puVar9;
    *(undefined4 *)(param_2 + 8) = uVar11;
    *(undefined4 *)(param_2 + 0xc) = uVar14;
    GetDriverEntry(*(undefined2 *)(param_2 + 200));
    iVar5 = func_020a23a0();
    uVar7 = param_2 + 0xa0U & 3;
    uVar4 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = param_2 + 8U & 3;
    uVar10 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + iVar5 + 0x7800;
    uVar3 = DAT_020a6808;
    uVar7 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) - 0x52;
    uVar7 = param_2 + 0xa8U & 3;
    uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + uVar3;
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0xfff < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
    }
    uVar7 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    if (0 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      return;
    }
    uVar7 = param_2 + 0xdcU & 3;
    uVar3 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    if (0 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      uVar10 = *(uint *)(DAT_020a6820 & 0xfffffffc) >> (DAT_020a6820 & 3) * 8 |
               *(uint *)(DAT_020a6820 & 0xfffffffc) << (DAT_020a6820 & 3) * -8 + 0x20;
      uVar7 = uVar10 + 0x47c & 3;
      uVar3 = *(uint *)(uVar10 + 0x47c & 0xfffffffc);
      uVar16 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      iVar20 = uVar10 + DAT_020a6824;
      uVar7 = iVar20 + 8U & 3;
      uVar3 = *(uint *)(iVar20 + 8U & 0xfffffffc);
      uVar17 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      uVar7 = iVar20 + 4U & 3;
      uVar12 = *(uint *)(iVar20 + 4U & 0xfffffffc);
      lVar1 = (ulonglong)uVar16 * (ulonglong)uVar17;
      uVar21 = (uint)lVar1;
      uVar3 = iVar20 + 0xcU & 3;
      uVar15 = *(uint *)(iVar20 + 0xcU & 0xfffffffc);
      uVar4 = iVar20 + 0x10U & 3;
      uVar18 = *(uint *)(iVar20 + 0x10U & 0xfffffffc);
      uVar19 = uVar18 >> uVar4 * 8 | uVar18 << uVar4 * -8 + 0x20;
      uVar4 = iVar20 + 0x14U & 3;
      uVar18 = *(uint *)(iVar20 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x47c) = uVar19 + uVar21;
      *(uint *)(iVar20 + 4) =
           (uVar18 >> uVar4 * 8 | uVar18 << uVar4 * -8 + 0x20) +
           (uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) * uVar16 +
           uVar17 * (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar19,uVar21);
      uVar7 = uVar10 + 0x47c & 3;
      uVar3 = *(uint *)(uVar10 + 0x47c & 0xfffffffc);
      uVar19 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      uVar7 = iVar20 + 8U & 3;
      uVar3 = *(uint *)(iVar20 + 8U & 0xfffffffc);
      uVar4 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      uVar7 = iVar20 + 4U & 3;
      uVar3 = *(uint *)(iVar20 + 4U & 0xfffffffc);
      uVar17 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      lVar1 = (ulonglong)uVar19 * (ulonglong)uVar4;
      uVar15 = (uint)lVar1;
      uVar7 = iVar20 + 0xcU & 3;
      uVar12 = *(uint *)(iVar20 + 0xcU & 0xfffffffc);
      uVar3 = iVar20 + 0x10U & 3;
      uVar18 = *(uint *)(iVar20 + 0x10U & 0xfffffffc);
      uVar16 = uVar18 >> uVar3 * 8 | uVar18 << uVar3 * -8 + 0x20;
      uVar3 = iVar20 + 0x14U & 3;
      uVar18 = *(uint *)(iVar20 + 0x14U & 0xfffffffc);
      *(uint *)(uVar10 + 0x47c) = uVar16 + uVar15;
      *(uint *)(iVar20 + 4) =
           (uVar18 >> uVar3 * 8 | uVar18 << uVar3 * -8 + 0x20) +
           (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) * uVar19 +
           uVar4 * uVar17 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar15);
      iVar5 = (int)(uVar17 >> 0x10) >> 4;
      uVar7 = iVar20 + 4U & 3;
      uVar3 = *(uint *)(iVar20 + 4U & 0xfffffffc);
      iVar20 = (int)((ulonglong)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) * 0x14000 >> 0x20)
      ;
      lVar1 = (longlong)iVar20 * (longlong)(int)*(short *)(DAT_020a6828 + iVar5 * 4);
      lVar2 = (longlong)iVar20 * (longlong)(int)*(short *)(DAT_020a6828 + (iVar5 * 2 + 1) * 2);
      uVar7 = param_2 + 0xccU & 3;
      uVar10 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
      uVar3 = param_2 + 4U & 3;
      uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
      uVar10 = ((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) +
               ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14)) -
               (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
      uVar7 = param_2 + 0xd4U & 3;
      uVar12 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      uVar3 = param_2 + 0xcU & 3;
      uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      uVar7 = ((uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) +
              ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14)) -
              (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
      lVar1 = (ulonglong)uVar10 * 0x25;
      *(undefined4 *)(param_2 + 0xe0) = 4;
      *(uint *)(param_2 + 0x10) =
           (uint)lVar1 >> 0xc |
           (((int)uVar10 >> 0x1f) * 0x25 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      *(undefined4 *)(param_2 + 0x14) = 0x5000;
      lVar1 = (ulonglong)uVar7 * 0x25;
      *(uint *)(param_2 + 0x18) =
           (uint)lVar1 >> 0xc |
           (((int)uVar7 >> 0x1f) * 0x25 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
      return;
    }
    *(undefined4 *)(param_2 + 0xe0) = 5;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0x5000;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0xa8) = 0x1000;
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
    return;
  case 4:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + DAT_020a6808;
    uVar3 = DAT_020a6808;
    uVar7 = param_2 + 0xa8U & 3;
    uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0xfff < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
    }
    uVar7 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) - uVar3;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,(int *)(uintptr_t)(param_2 + 4));
    uVar7 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    if (((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < 0) &&
       (uVar7 = param_2 + 0xd0U & 3, uVar12 = *(uint *)(param_2 + 0xd0U & 0xfffffffc),
       uVar3 = param_2 + 0x58U & 3, uVar10 = *(uint *)(param_2 + 0x58U & 0xfffffffc),
       uVar4 = param_2 + 8U & 3, uVar15 = *(uint *)(param_2 + 8U & 0xfffffffc),
       (int)(uVar15 >> uVar4 * 8 | uVar15 << uVar4 * -8 + 0x20) <=
       (int)((uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) +
            (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20)))) {
      iVar5 = func_020d3c94(param_2,0,(undefined4)(uintptr_t)(auStack_40));
      if (iVar5 != 0) {
        uVar7 = param_2 + 0x14U & 3;
        uVar15 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
        VecFx32_Add(param_2 + 4,(uint)(uintptr_t)(auStack_40),(int *)(uintptr_t)(param_2 + 4));
        func_020ea94c((undefined4 *)(uintptr_t)(param_2 + 0x10),(int *)(void *)(auStack_40),0x1000,0x1000,0x800,(undefined4 *)(uintptr_t)(param_2 + 0x10));
        *(undefined4 *)(param_2 + 0x14) = 0;
        uVar3 = param_2 + 0x14U & 3;
        uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
        uVar10 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        uVar3 = param_2 + 0x10U & 3;
        uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
        uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        uVar3 = param_2 + 0x18U & 3;
        uVar12 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
        uVar3 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
        lVar1 = (longlong)(int)uVar3 * (longlong)(int)uVar3 +
                (longlong)(int)uVar4 * (longlong)(int)uVar4 +
                (longlong)(int)uVar10 * (longlong)(int)uVar10;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          Vector3_MaybeNormalize(param_2 + 0x10,(int *)(uintptr_t)(param_2 + 0x10));
        }
        uVar3 = param_2 + 0x10U & 3;
        uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
        *(uint *)(param_2 + 0x10) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        uVar3 = param_2 + 0x14U & 3;
        uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
        *(uint *)(param_2 + 0x14) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        uVar3 = param_2 + 0x18U & 3;
        uVar4 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
        *(uint *)(param_2 + 0x18) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        *(uint *)(param_2 + 0x14) = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
      }
      uVar7 = param_2 + 4U & 3;
      uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
      local_4c = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      uVar7 = param_2 + 8U & 3;
      uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar3 = param_2 + 0x58U & 3;
      uVar10 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
      local_48 = (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
                 ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) - 0x14000);
      uVar7 = param_2 + 0xcU & 3;
      uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      local_44 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      uVar7 = param_2 + 0x58U & 3;
      uVar3 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
      iVar5 = func_01ffdee4(&local_4c,0,0,uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,8,
                            0xfffffffe,(int *)(void *)(auStack_40),(int *)(void *)(auStack_34),(int *)(void *)(auStack_28),&local_50,0,0,0,0);
      if (iVar5 != 0) {
        VecFx32_Add(param_2 + 4,(uint)(uintptr_t)(auStack_40),(int *)(uintptr_t)(param_2 + 4));
        if ((local_50 & DAT_020a6830) != 0) {
          uVar7 = param_2 + 0x14U & 3;
          uVar15 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
          func_020eaa14(param_2 + 0x10,auStack_28,0x1000,0x1000,0x800,param_2 + 0x10);
          *(undefined4 *)(param_2 + 0x14) = 0;
          uVar3 = param_2 + 0x14U & 3;
          uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
          uVar10 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          uVar3 = param_2 + 0x10U & 3;
          uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
          uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          uVar3 = param_2 + 0x18U & 3;
          uVar12 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
          uVar3 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
          lVar1 = (longlong)(int)uVar3 * (longlong)(int)uVar3 +
                  (longlong)(int)uVar4 * (longlong)(int)uVar4 +
                  (longlong)(int)uVar10 * (longlong)(int)uVar10;
          if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
            Vector3_MaybeNormalize(param_2 + 0x10,param_2 + 0x10);
          }
          uVar3 = param_2 + 0x10U & 3;
          uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
          *(uint *)(param_2 + 0x10) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          uVar3 = param_2 + 0x14U & 3;
          uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
          *(uint *)(param_2 + 0x14) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          uVar3 = param_2 + 0x18U & 3;
          uVar4 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
          *(uint *)(param_2 + 0x18) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          *(uint *)(param_2 + 0x14) = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
        }
        uVar7 = DAT_020a6808;
        if ((local_50 & DAT_020a6834) != 0) {
          uVar3 = param_2 + 0x10U & 3;
          uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
          uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          lVar1 = (ulonglong)DAT_020a6808 * (ulonglong)uVar3;
          *(uint *)(param_2 + 0x10) =
               (uint)lVar1 >> 0xc |
               (((int)uVar3 >> 0x1f) * DAT_020a6808 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
          uVar3 = param_2 + 0x14U & 3;
          uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
          uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          *(uint *)(param_2 + 0x14) =
               (uint)((ulonglong)DAT_020a680c * (ulonglong)uVar3) >> 0xc |
               (((int)uVar3 >> 0x1f) * DAT_020a680c +
               ((int)((ulonglong)DAT_020a680c * (ulonglong)uVar3 >> 0x20) - uVar3)) * 0x100000;
          uVar3 = param_2 + 0x18U & 3;
          uVar4 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
          uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
          lVar1 = (ulonglong)uVar7 * (ulonglong)uVar3;
          *(uint *)(param_2 + 0x18) =
               (uint)lVar1 >> 0xc |
               (((int)uVar3 >> 0x1f) * uVar7 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
          uVar11 = DAT_020a6810;
          uVar7 = param_2 + 0x14U & 3;
          uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
          if ((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < 0x1000) {
            *(undefined4 *)(param_2 + 0x14) = 0;
            *(undefined4 *)(param_2 + 0xe0) = 1;
          }
          uVar7 = param_2 + 0x94U & 3;
          uVar3 = *(uint *)(param_2 + 0x94U & 0xfffffffc);
          func_0210b98c(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,uVar11);
        }
        if ((local_50 & 0x1000000) == 0) {
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xffdf;
        }
        else {
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_020a6838;
        }
      }
    }
    uVar7 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    if (-1 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      return;
    }
    *(undefined4 *)(param_2 + 0xe0) = 6;
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_020a682c;
    break;
  case 5:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + DAT_020a6808;
    uVar3 = DAT_020a6808;
    uVar7 = param_2 + 0xa8U & 3;
    uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0xfff < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
    }
    uVar7 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) - uVar3;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,param_2 + 4);
    uVar7 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    if (-1 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      return;
    }
    *(undefined4 *)(param_2 + 0xe0) = 6;
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_020a682c;
    return;
  case 6:
    uVar7 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    piVar13 = (int *)(param_2 + 0xb4);
    *(uint *)(param_2 + 0xb4) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 4;
    uVar3 = DAT_020a6804;
    uVar7 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if (2 < (int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) {
      *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                 *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 3;
      uVar7 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb0) = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 1;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = StructMapObject_SomeFn_1(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      uVar7 = param_2 + 0xb0U & 3;
      uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      if (iVar5 <= (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        iVar5 = StructMapObject_SomeFn_1
                          (*(uint *)(DAT_020a6804 & 0xfffffffc) >> (DAT_020a6804 & 3) * 8 |
                           *(uint *)(DAT_020a6804 & 0xfffffffc) << (DAT_020a6804 & 3) * -8 + 0x20);
        uVar7 = param_2 + 0xb0U & 3;
        uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - iVar5;
      }
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      piVar13 = (int *)(param_2 + 0xbc);
      *(uint *)(param_2 + 0xbc) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (7 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *piVar13 = (*(uint *)((uint)piVar13 & 0xfffffffc) >> ((uint)piVar13 & 3) * 8 |
                   *(uint *)((uint)piVar13 & 0xfffffffc) << ((uint)piVar13 & 3) * -8 + 0x20) - 8;
        uVar7 = param_2 + 0xb8U & 3;
        uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) =
             (uint)(uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0);
      }
    }
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - DAT_020a6808;
    uVar7 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
      return;
    }
    *(undefined4 *)(param_2 + 0xa8) = 0;
    func_020d2398(param_2);
    func_020a1218(0xffffffff);
    uVar7 = param_2 + 0xc4U & 3;
    uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    if ((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) < 0) {
      return;
    }
    func_020a6cb4();
    return;
  }
  return;
}

