/* Decompiled C draft; module arm9; ROM address 0209d84c. No matching claim. */
#include "types.h"
#include "deps/0209d84c_func_0209d84c.h"

void func_0209d84c(undefined4 param_1,int param_2)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  uint local_30;
  undefined1 auStack_2c [12];
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar6 = param_2 + 0xb8U & 3;
  uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
  switch(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) {
  case 0:
    uVar6 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar6 - 1;
    if ((int)uVar6 < 1) {
      *(undefined4 *)(param_2 + 0xb8) = 1;
      local_1c = param_2 + 4;
      local_20 = DAT_0209dd2c;
      local_18 = 2;
      local_14 = func_020d4ef4();
      func_0210b7a8((uint)(uintptr_t)(&local_20));
    }
    break;
  case 1:
    sVar1 = *(short *)(param_2 + 0xa0);
    *(short *)(param_2 + 0xa0) = sVar1 + -1;
    if (sVar1 == 0) {
      func_020d2398(param_2);
      uVar6 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
        func_0208b6b0((undefined4 *)(uintptr_t)(param_2 + 0xbc));
      }
      uVar6 = param_2 + 0xc0U & 3;
      uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
        func_0208b6b0((undefined4 *)(uintptr_t)(param_2 + 0xc0));
      }
    }
    else {
      uVar6 = param_2 + 0x14U & 3;
      uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
      iVar7 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + DAT_0209dd30;
      if (iVar7 < -0x7fff) {
        iVar7 = -0x8000;
      }
      *(int *)(param_2 + 0x14) = iVar7;
      VecFx32_Add(param_2 + 4,param_2 + 0x10,(int *)(uintptr_t)(param_2 + 4));
      if ((((0x78 < *(ushort *)(param_2 + 0xa0)) &&
           (uVar6 = param_2 + 0x14U & 3, uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc),
           (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) < 0)) &&
          (uVar6 = param_2 + 0x58U & 3, uVar3 = *(uint *)(param_2 + 0x58U & 0xfffffffc),
          iVar7 = func_01ffdee4((int *)(uintptr_t)(param_2 + 4),0,0,uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20,8,
                                0xfffffffe,(int *)(void *)(auStack_2c),0,0,&local_30,0,0,0,0), iVar7 != 0)) &&
         ((local_30 & DAT_0209dd34) != 0)) {
        VecFx32_Add(param_2 + 4,(uint)(uintptr_t)(auStack_2c),(int *)(uintptr_t)(param_2 + 4));
        uVar6 = param_2 + 0xcU & 3;
        uVar10 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
        uVar3 = param_2 + 0xb0U & 3;
        uVar8 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
        uVar9 = param_2 + 4U & 3;
        uVar11 = *(uint *)(param_2 + 4U & 0xfffffffc);
        iVar7 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) -
                (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20);
        uVar6 = param_2 + 0xa8U & 3;
        uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
        iVar4 = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) -
                (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
        lVar2 = (longlong)iVar4 * (longlong)iVar4 + (longlong)iVar7 * (longlong)iVar7;
        iVar7 = (int)((ulonglong)lVar2 >> 0x20);
        bVar16 = (uint)lVar2 < 0x10000000;
        if ((int)(iVar7 - (bVar16 + 0x27)) < 0 ==
            (SBORROW4(iVar7,0x27) != SBORROW4(iVar7 + -0x27,(uint)bVar16))) {
          uVar6 = param_2 + 0x10U & 3;
          uVar3 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
          *(uint *)(param_2 + 0x10) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
          uVar6 = param_2 + 0x18U & 3;
          uVar3 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
          *(uint *)(param_2 + 0x18) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
        }
        else {
          piVar5 = (int *)func_020d22d0();
          uVar6 = (uint)(piVar5 + 2) & 3;
          uVar3 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
          uVar12 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
          uVar10 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                   *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
          uVar6 = (uint)(piVar5 + 1) & 3;
          uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          lVar2 = (ulonglong)uVar10 * (ulonglong)uVar12;
          uVar14 = (uint)lVar2;
          uVar3 = (uint)(piVar5 + 4) & 3;
          uVar9 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
          uVar15 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
          uVar3 = (uint)(piVar5 + 3) & 3;
          uVar13 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
          uVar9 = (uint)(piVar5 + 5) & 3;
          uVar11 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
          *piVar5 = uVar15 + uVar14;
          piVar5[1] = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
                      (uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20) * uVar10 +
                      uVar12 * (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
                      (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar15,uVar14);
          iVar4 = DAT_0209dd38;
          uVar6 = (uint)(piVar5 + 1) & 3;
          uVar3 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          iVar7 = (int)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) >> 0x10) >> 4;
          uVar6 = (uint)*(short *)(DAT_0209dd38 + iVar7 * 4);
          lVar2 = (ulonglong)uVar6 * 0x1800;
          *(uint *)(param_2 + 0x10) =
               (uint)lVar2 >> 0xc |
               (((int)uVar6 >> 0x1f) * 0x1800 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
          uVar6 = (uint)*(short *)(iVar4 + (iVar7 * 2 + 1) * 2);
          lVar2 = (ulonglong)uVar6 * 0x1800;
          *(uint *)(param_2 + 0x18) =
               (uint)lVar2 >> 0xc |
               (((int)uVar6 >> 0x1f) * 0x1800 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
        }
        *(undefined4 *)(param_2 + 0x14) = 0x2c00;
        uVar6 = param_2 + 0xa4U & 3;
        uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
        *(uint *)(param_2 + 0xa4) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x3c;
        *(undefined4 *)(param_2 + 0xb8) = 0;
        uVar6 = param_2 + 0xbcU & 3;
        uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        *(undefined2 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x70) = 0x2a;
        uVar6 = param_2 + 0xc0U & 3;
        uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        *(undefined2 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x70) = 0x2a;
        uVar6 = param_2 + 0xbcU & 3;
        uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        *(undefined1 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x80) = 6;
        uVar6 = param_2 + 0xc0U & 3;
        uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        *(undefined1 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x80) = 6;
      }
    }
    break;
  case 2:
    uVar6 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    iVar7 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - 0xcd;
    if (iVar7 < -0x1fff) {
      iVar7 = -0x2000;
    }
    *(int *)(param_2 + 0x14) = iVar7;
    uVar6 = param_2 + 8U & 3;
    uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar3 = param_2 + 0x14U & 3;
    uVar9 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
         (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20);
    uVar6 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    if ((int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) < 0) {
      piVar5 = (int *)func_020d22d0();
      uVar6 = (uint)(piVar5 + 2) & 3;
      uVar3 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar12 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      uVar10 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
               *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar6 = (uint)(piVar5 + 1) & 3;
      uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar10 * (ulonglong)uVar12;
      uVar15 = (uint)lVar2;
      uVar3 = (uint)(piVar5 + 4) & 3;
      uVar9 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar14 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
      uVar3 = (uint)(piVar5 + 3) & 3;
      uVar13 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar9 = (uint)(piVar5 + 5) & 3;
      uVar11 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      *piVar5 = uVar14 + uVar15;
      piVar5[1] = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
                  (uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20) * uVar10 +
                  uVar12 * (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar14,uVar15);
      uVar6 = (uint)(piVar5 + 1) & 3;
      uVar3 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      *(ushort *)(param_2 + 0xb4) =
           (ushort)((uVar3 >> uVar6 * 8) >> 0x10) | (ushort)((uVar3 << uVar6 * -8 + 0x20) >> 0x10);
      *(undefined4 *)(param_2 + 0xb8) = 3;
    }
    break;
  case 3:
    sVar1 = *(short *)(param_2 + 0xa0);
    *(short *)(param_2 + 0xa0) = sVar1 + -1;
    if (sVar1 == 0) {
      func_020d2398(param_2);
      uVar6 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
        func_0208b6b0((undefined4 *)(uintptr_t)(param_2 + 0xbc));
      }
      uVar6 = param_2 + 0xc0U & 3;
      uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
        func_0208b6b0((undefined4 *)(uintptr_t)(param_2 + 0xc0));
      }
    }
    else {
      uVar6 = param_2 + 0x14U & 3;
      uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
      iVar7 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - 0xcd;
      if (iVar7 < -0x1fff) {
        iVar7 = -0x2000;
      }
      *(int *)(param_2 + 0x14) = iVar7;
      iVar7 = DAT_0209dd38;
      *(short *)(param_2 + 0xb4) = *(short *)(param_2 + 0xb4) + (short)DAT_0209dd3c;
      uVar6 = param_2 + 4U & 3;
      uVar9 = *(uint *)(param_2 + 4U & 0xfffffffc);
      uVar3 = (uint)*(short *)(iVar7 + ((int)(uint)*(ushort *)(param_2 + 0xb4) >> 4) * 4);
      *(uint *)(param_2 + 4) =
           (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
           ((uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14);
      uVar6 = param_2 + 0xcU & 3;
      uVar9 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      uVar3 = (uint)*(short *)(iVar7 + (((int)(uint)*(ushort *)(param_2 + 0xb4) >> 4) * 2 + 1) * 2);
      *(uint *)(param_2 + 0xc) =
           (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
           ((uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14);
      uVar6 = param_2 + 8U & 3;
      uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar3 = param_2 + 0x14U & 3;
      uVar9 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
      *(uint *)(param_2 + 8) =
           (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
           (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20);
    }
  }
  if ((*(ushort *)(param_2 + 2) & 0x12) == 0) {
    uVar6 = param_2 + 0xbcU & 3;
    uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    if (uVar6 != 0) {
      func_0208b5b0(uVar6,param_2 + 4);
      uVar6 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      uVar9 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      uVar6 = uVar9 + 0x24;
      uVar3 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar9 + 0x24) = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0xfffffffd;
    }
    uVar6 = param_2 + 0xc0U & 3;
    uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    if (uVar6 == 0) {
      return;
    }
    func_0208b5b0(uVar6,param_2 + 4);
    uVar6 = param_2 + 0xc0U & 3;
    uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar9 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar6 = uVar9 + 0x24;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar9 + 0x24) = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0xfffffffd;
    return;
  }
  uVar6 = param_2 + 0xbcU & 3;
  uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    uVar3 = uVar6 + 0x24 & 3;
    uVar9 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
    *(uint *)(uVar6 + 0x24) = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20 | 2;
  }
  uVar6 = param_2 + 0xc0U & 3;
  uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    uVar3 = uVar6 + 0x24 & 3;
    uVar9 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
    *(uint *)(uVar6 + 0x24) = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20 | 2;
  }
  return;
}

