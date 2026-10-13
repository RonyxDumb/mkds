/* Decompiled C draft; module arm9; ROM address 02094768. No matching claim. */
#include "types.h"
#include "deps/02094768_func_02094768.h"

void func_02094768(undefined4 param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar4;
  
  uVar4 = param_2 + 0x110U & 3;
  uVar3 = *(uint *)(param_2 + 0x110U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 0) {
    uVar4 = param_2 + 0xb8U & 3;
    uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_2 + 0xb8) = uVar4 - 1;
    if ((int)uVar4 < 1) {
      *(undefined4 *)(param_2 + 0xb8) = 0;
      uVar4 = param_2 + 0xfcU & 3;
      uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      *(uint *)(param_2 + 0xfc) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - 0x1000;
      uVar4 = param_2 + 0xfcU & 3;
      uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if ((int)uVar4 < 1) {
        *(undefined2 *)(param_2 + 0xac) = 0;
        func_020d2398(param_2);
        *piRam02094bc4 =
             (*(uint *)((uint)piRam02094bc4 & 0xfffffffc) >> ((uint)piRam02094bc4 & 3) * 8 |
             *(uint *)((uint)piRam02094bc4 & 0xfffffffc) << ((uint)piRam02094bc4 & 3) * -8 + 0x20) -
             1;
      }
      else {
        *(short *)(param_2 + 0xac) = (short)((int)uVar4 >> 0xc);
      }
    }
    else {
      uVar4 = param_2 + 0xfcU & 3;
      uVar9 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      uVar3 = param_2 + 0x100U & 3;
      uVar5 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
      *(uint *)(param_2 + 0xfc) =
           (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
           (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
      uVar4 = param_2 + 0xfcU & 3;
      uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = param_2 + 0x108U & 3;
      uVar3 = *(uint *)(param_2 + 0x108U & 0xfffffffc);
      if ((int)uVar5 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
        uVar4 = param_2 + 0x104U & 3;
        uVar3 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
        if ((int)uVar5 <= (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
          uVar4 = param_2 + 0x100U & 3;
          uVar3 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
          *(uint *)(param_2 + 0x100) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
          uVar4 = param_2 + 0x104U & 3;
          uVar9 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
          uVar3 = param_2 + 0xfcU & 3;
          uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
          *(uint *)(param_2 + 0xfc) =
               (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * 2 -
               (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
        }
      }
      else {
        uVar4 = param_2 + 0x100U & 3;
        uVar3 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
        *(uint *)(param_2 + 0x100) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
        uVar4 = param_2 + 0x108U & 3;
        uVar9 = *(uint *)(param_2 + 0x108U & 0xfffffffc);
        uVar3 = param_2 + 0xfcU & 3;
        uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
        *(uint *)(param_2 + 0xfc) =
             (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * 2 -
             (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
      }
      uVar4 = param_2 + 0xfcU & 3;
      uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      *(short *)(param_2 + 0xac) =
           (short)((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 0xc);
    }
  }
  else if ((uVar4 == 1) &&
          (uVar4 = param_2 + 0xb4U & 3, uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc),
          uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,
          *(uint *)(param_2 + 0xb4) = uVar4 - 1, (int)uVar4 < 1)) {
    *(undefined4 *)(param_2 + 0xb4) = 0;
    uVar4 = param_2 + 0xfcU & 3;
    uVar9 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar3 = param_2 + 0x100U & 3;
    uVar5 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
    *(uint *)(param_2 + 0xfc) =
         (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
         (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    uVar4 = param_2 + 0xfcU & 3;
    uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = param_2 + 0x108U & 3;
    uVar3 = *(uint *)(param_2 + 0x108U & 0xfffffffc);
    if ((int)uVar5 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
      uVar4 = param_2 + 0x104U & 3;
      uVar3 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
      if ((int)uVar5 <= (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
        uVar4 = param_2 + 0x100U & 3;
        uVar3 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
        *(uint *)(param_2 + 0x100) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
        uVar4 = param_2 + 0x104U & 3;
        uVar9 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
        uVar3 = param_2 + 0xfcU & 3;
        uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
        *(uint *)(param_2 + 0xfc) =
             (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * 2 -
             (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
      }
    }
    else {
      uVar4 = param_2 + 0x100U & 3;
      uVar3 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
      *(uint *)(param_2 + 0x100) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
      uVar4 = param_2 + 0x108U & 3;
      uVar9 = *(uint *)(param_2 + 0x108U & 0xfffffffc);
      uVar3 = param_2 + 0xfcU & 3;
      uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      *(uint *)(param_2 + 0xfc) =
           (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * 2 -
           (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    }
    uVar4 = param_2 + 0xfcU & 3;
    uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    *(short *)(param_2 + 0xac) =
         (short)((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 0xc);
    uVar4 = param_2 + 0xfcU & 3;
    uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    if (0x1fff < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0x110) = 0;
    }
  }
  uVar4 = param_2 + 0xb8U & 3;
  uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
  if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 1) {
    return;
  }
  uVar4 = param_2 + 0xd4U & 3;
  uVar3 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  *(ushort *)(param_2 + 0xbc) =
       *(short *)(param_2 + 0xbc) +
       ((ushort)(uVar3 >> uVar4 * 8) | (ushort)(uVar3 << uVar4 * -8 + 0x20));
  uVar6 = Maybe_get_15d4b4_3(*(undefined2 *)(param_2 + 0xbc));
  uVar4 = param_2 + 0xccU & 3;
  uVar3 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
  iVar7 = Maybe_calc_094bf0(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,uVar6);
  uVar4 = param_2 + 200U & 3;
  uVar9 = *(uint *)(param_2 + 200U & 0xfffffffc);
  uVar3 = param_2 + 0xc0U & 3;
  uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  *(uint *)(param_2 + 0xc4) =
       ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) + iVar7) -
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar4 = param_2 + 0xc0U & 3;
  uVar9 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  uVar3 = param_2 + 0xc4U & 3;
  uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  *(uint *)(param_2 + 0xc0) =
       (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar4 = param_2 + 0xccU & 3;
  uVar3 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar3 = param_2 + 0xd0U & 3;
      uVar5 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
      iVar7 = uVar4 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
      if (-1 < iVar7) {
        iVar7 = 0;
      }
      *(int *)(param_2 + 0xcc) = iVar7;
    }
  }
  else {
    uVar3 = param_2 + 0xd0U & 3;
    uVar5 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    iVar7 = uVar4 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    *(int *)(param_2 + 0xcc) = iVar7;
  }
  uVar4 = param_2 + 0xd4U & 3;
  uVar3 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar3 = param_2 + 0xd8U & 3;
      uVar5 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
      iVar7 = uVar4 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
      if (-1 < iVar7) {
        iVar7 = 0;
      }
      *(int *)(param_2 + 0xd4) = iVar7;
    }
  }
  else {
    uVar3 = param_2 + 0xd8U & 3;
    uVar5 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
    iVar7 = uVar4 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    *(int *)(param_2 + 0xd4) = iVar7;
  }
  uVar4 = param_2 + 0xf4U & 3;
  uVar5 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  uVar3 = param_2 + 0xc0U & 3;
  uVar10 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  *(ushort *)(param_2 + 0xdc) =
       *(short *)(param_2 + 0xdc) +
       ((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20));
  iVar7 = Maybe_helper_094bd0(*(undefined2 *)(param_2 + 0xdc));
  uVar4 = param_2 + 0xecU & 3;
  uVar5 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  iVar7 = Maybe_calc_094bf0((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) / 2,
                            0x1000 - iVar7);
  uVar4 = param_2 + 0xe8U & 3;
  uVar11 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
  uVar5 = param_2 + 0xe0U & 3;
  uVar9 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  *(uint *)(param_2 + 0xe4) =
       ((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) + iVar7) -
       (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
  uVar4 = param_2 + 0xe0U & 3;
  uVar11 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  uVar5 = param_2 + 0xe4U & 3;
  uVar9 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
  *(uint *)(param_2 + 0xe0) =
       (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) +
       (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
  uVar4 = param_2 + 0xecU & 3;
  uVar5 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar5 = param_2 + 0xf0U & 3;
      uVar9 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
      iVar7 = uVar4 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
      if (-1 < iVar7) {
        iVar7 = 0;
      }
      *(int *)(param_2 + 0xec) = iVar7;
    }
  }
  else {
    uVar5 = param_2 + 0xf0U & 3;
    uVar9 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
    iVar7 = uVar4 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    *(int *)(param_2 + 0xec) = iVar7;
  }
  uVar4 = param_2 + 0xf4U & 3;
  uVar5 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar5 = param_2 + 0xf8U & 3;
      uVar9 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
      iVar7 = uVar4 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
      if (-1 < iVar7) {
        iVar7 = 0;
      }
      *(int *)(param_2 + 0xf4) = iVar7;
    }
  }
  else {
    uVar5 = param_2 + 0xf8U & 3;
    uVar9 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
    iVar7 = uVar4 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    *(int *)(param_2 + 0xf4) = iVar7;
  }
  uVar4 = param_2 + 0xe0U & 3;
  uVar5 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = param_2 + 0x10cU & 3;
  uVar9 = *(uint *)(param_2 + 0x10cU & 0xfffffffc);
  uVar4 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
  iVar8 = func_02061818();
  iVar2 = iRam02094bc8;
  iVar7 = (int)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) & 0xffff) >> 4;
  if (iVar8 == 2) {
    uVar3 = param_2 + 0xa0U & 3;
    uVar9 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    lVar1 = (longlong)(int)uVar4 * (longlong)(int)*(short *)(iRam02094bc8 + (iVar7 * 2 + 1) * 2);
    *(uint *)(param_2 + 4) =
         (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar3 = param_2 + 0xa4U & 3;
    uVar9 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    *(uint *)(param_2 + 8) = (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + uVar5;
    uVar3 = param_2 + 0xa8U & 3;
    uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    lVar1 = (longlong)(int)uVar4 * (longlong)(int)*(short *)(iVar2 + iVar7 * 4);
    *(uint *)(param_2 + 0xc) =
         (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    return;
  }
  iVar8 = GetDriverEntry((short)*(char *)((*(uint *)(uRam02094bcc & 0xfffffffc) >>
                                           (uRam02094bcc & 3) * 8 |
                                          *(uint *)(uRam02094bcc & 0xfffffffc) <<
                                          (uRam02094bcc & 3) * -8 + 0x20) + 0x62));
  iVar2 = iRam02094bc8;
  uVar3 = param_2 + 0xa0U & 3;
  uVar11 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar9 = iVar8 + 0x80U & 3;
  uVar10 = *(uint *)(iVar8 + 0x80U & 0xfffffffc);
  lVar1 = (longlong)(int)uVar4 * (longlong)(int)*(short *)(iRam02094bc8 + (iVar7 * 2 + 1) * 2);
  *(uint *)(param_2 + 4) =
       (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) +
       (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar3 = param_2 + 0xa4U & 3;
  uVar9 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  *(uint *)(param_2 + 8) = (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + uVar5;
  uVar3 = param_2 + 0xa8U & 3;
  uVar9 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  uVar5 = iVar8 + 0x88U & 3;
  uVar11 = *(uint *)(iVar8 + 0x88U & 0xfffffffc);
  lVar1 = (longlong)(int)uVar4 * (longlong)(int)*(short *)(iVar2 + iVar7 * 4);
  *(uint *)(param_2 + 0xc) =
       (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) +
       (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  return;
}

