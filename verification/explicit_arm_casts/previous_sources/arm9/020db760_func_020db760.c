/* Decompiled C draft; module arm9; ROM address 020db760. No matching claim. */
#include "types.h"
#include "deps/020db760_func_020db760.h"

void func_020db760(undefined4 param_1,int param_2)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  *(undefined4 *)(param_2 + 0xb0) = 0;
  uVar4 = param_2 + 0xb4U & 3;
  uVar6 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  uVar13 = param_2 + 200;
  if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = param_2 + 0xa0U & 3;
    uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    switch(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) {
    case 0:
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) - 1;
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (-1 < (int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20)) {
        return;
      }
      uVar4 = param_2 + 0xa0U & 3;
      uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa0) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 1;
      uVar4 = param_2 + 0xf0U & 3;
      uVar6 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
      if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
        iVar7 = 0x3000;
      }
      else {
        iVar7 = 0xc00;
      }
      *(int *)(param_2 + 0xcc) = iVar7;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
               *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
      uVar4 = param_2 + 0xd4U & 3;
      uVar3 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      uVar6 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x54 +
              (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) + 0x34;
      uVar6 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      lVar2 = (longlong)iVar7 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
      *(uint *)(param_2 + 0xd8) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      return;
    case 1:
      uVar4 = param_2 + 0xf0U & 3;
      uVar6 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
      if (uVar6 >> uVar4 * 8 != 0 || uVar6 << uVar4 * -8 + 0x20 != 0) {
        func_020d275c(param_2,DAT_020dbd98);
      }
      break;
    case 2:
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) - 1;
      iVar7 = DAT_020dbda0;
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (((int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) < 0) &&
         (*(ushort *)(param_2 + 0xc2) < DAT_020dbd9c)) {
        uVar4 = param_2 + 0xa0U & 3;
        uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
        *(uint *)(param_2 + 0xa0) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 1;
        uVar4 = param_2 + 0x100U & 3;
        uVar6 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
        *(uint *)(param_2 + 0xa8) = -(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
        return;
      }
      *(short *)(param_2 + 0xc2) = *(short *)(param_2 + 0xc2) + (short)DAT_020dbd9c;
      uVar4 = param_2 + 0xacU & 3;
      uVar6 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
      *(uint *)(param_2 + 8) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      uVar4 = param_2 + 0xc4U & 3;
      uVar13 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      uVar6 = param_2 + 8U & 3;
      uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
      lVar2 = (longlong)(int)*(short *)(iVar7 + ((int)(uint)*(ushort *)(param_2 + 0xc2) >> 4) * 4) *
              (longlong)(int)(uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20);
      *(uint *)(param_2 + 8) =
           (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
           ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
      return;
    case 3:
      uVar4 = param_2 + 0xa8U & 3;
      uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      uVar6 = param_2 + 0x104U & 3;
      uVar13 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
      *(uint *)(param_2 + 0xa8) =
           (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
           (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20);
      uVar4 = param_2 + 8U & 3;
      uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar6 = param_2 + 0xa8U & 3;
      uVar13 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      *(uint *)(param_2 + 8) =
           (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) -
           (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20);
      uVar4 = param_2 + 8U & 3;
      uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar6 = param_2 + 0xacU & 3;
      uVar13 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
      if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) <
          (int)(uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20)) {
        uVar4 = param_2 + 0xa0U & 3;
        uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
        *(uint *)(param_2 + 0xa0) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 1;
      }
      return;
    case 4:
      uVar4 = param_2 + 0xa8U & 3;
      uVar6 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      if ((int)uVar4 < 0x14000) {
        *(uint *)(param_2 + 0xa8) = uVar4 + 0x1000;
        uVar4 = param_2 + 0xa8U & 3;
        uVar6 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
        uVar11 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
        *(uint *)(param_2 + 0xcc) = uVar11;
        uVar12 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                 *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
        uVar4 = param_2 + 0xd4U & 3;
        uVar3 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
        uVar6 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x54 +
                (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) + 0x34;
        uVar6 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        lVar2 = (longlong)(int)uVar11 *
                (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
        *(uint *)(param_2 + 0xd8) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      }
      break;
    case 5:
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) - 1;
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (-1 < (int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20)) {
        return;
      }
      uVar4 = param_2 + 0xa0U & 3;
      uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa0) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 1;
      uVar4 = param_2 + 0x108U & 3;
      uVar6 = *(uint *)(param_2 + 0x108U & 0xfffffffc);
      uVar12 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      *(uint *)(param_2 + 0xcc) = uVar12;
      uVar3 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
              *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
      uVar4 = param_2 + 0xd4U & 3;
      uVar13 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      uVar6 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = (uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20) * 0x54 +
              (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x34;
      uVar6 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      lVar2 = (longlong)(int)uVar12 *
              (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
      *(uint *)(param_2 + 0xd8) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      return;
    case 6:
    }
    iVar7 = func_020d8cc8(uVar13);
    if (iVar7 != 0) {
      uVar4 = param_2 + 0xe4U & 3;
      uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
      sVar1 = *(short *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x10);
      if (sVar1 == 0) {
        uVar8 = 0;
      }
      else if (sVar1 == 1) {
        uVar8 = 2;
      }
      else if (sVar1 == 2) {
        uVar8 = 5;
      }
      else {
        uVar8 = 0;
      }
      *(undefined4 *)(param_2 + 0xa0) = uVar8;
      uVar4 = param_2 + 0xa0U & 3;
      uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) == 2) {
        uVar4 = param_2 + 8U & 3;
        uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
        *(uint *)(param_2 + 0xac) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
        *(undefined2 *)(param_2 + 0xc2) = 0;
      }
      uVar4 = param_2 + 0xa0U & 3;
      uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) == 5) {
        uVar4 = param_2 + 0xe4U & 3;
        uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
        uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
        iVar7 = func_020d4ddc(param_2);
        if (iVar7 == 0) {
          uVar6 = param_2 + 0x70U & 3;
          uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
          uVar12 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
          uVar6 = DAT_020dbda4 + 0x68U & 3;
          uVar3 = *(uint *)(DAT_020dbda4 + 0x68U & 0xfffffffc);
          if (uVar12 == (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20)) {
            local_18 = 2;
          }
          else {
            uVar6 = DAT_020dbda4 + 0x8cU & 3;
            uVar3 = *(uint *)(DAT_020dbda4 + 0x8cU & 0xfffffffc);
            if (uVar12 == (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20)) {
              local_18 = 3;
            }
            else {
              local_18 = 4;
            }
          }
          local_1c = param_2 + 4;
          local_20 = DAT_020dbda8;
          local_14 = func_020d4ef4();
          func_0210b7a8(&local_20);
        }
        uVar6 = param_2 + 0x78U & 3;
        uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
        func_02073fb0((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x3fffffe0,0x1000);
        uVar6 = param_2 + 0x78U & 3;
        uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
        if (((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 3) == 0) {
          func_0208b7bc(0x59,uVar4);
          func_0208b7bc(0x5a,uVar4);
        }
        *(undefined4 *)(param_2 + 0xb0) = 1;
      }
      uVar4 = param_2 + 0xe4U & 3;
      uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
      *(int *)(param_2 + 0xa4) =
           (int)*(short *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0xe);
      uVar4 = param_2 + 0xa4U & 3;
      uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (uVar6 >> uVar4 * 8 != 0 || uVar6 << uVar4 * -8 + 0x20 != 0) {
        uVar13 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                 *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
        uVar4 = param_2 + 0xd4U & 3;
        uVar3 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
        uVar6 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        puVar5 = (undefined4 *)
                 ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x54 +
                 (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20));
        uVar8 = puVar5[1];
        uVar9 = puVar5[2];
        *(undefined4 *)(param_2 + 4) = *puVar5;
        *(undefined4 *)(param_2 + 8) = uVar8;
        *(undefined4 *)(param_2 + 0xc) = uVar9;
        uVar4 = param_2 + 8U & 3;
        uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
        uVar6 = param_2 + 0xf8U & 3;
        uVar13 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
        *(uint *)(param_2 + 8) =
             (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
             (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20);
        *(undefined4 *)(param_2 + 0xdc) = 0;
        return;
      }
    }
    func_020d8a5c(uVar13,param_2 + 4);
    uVar4 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar6 = param_2 + 0xf8U & 3;
    uVar13 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
         (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20);
    return;
  }
  *(short *)(param_2 + 0xba) = *(short *)(param_2 + 0xba) + *(short *)(param_2 + 0xb8);
  iVar7 = (int)*(short *)(param_2 + 0xb8);
  if ((iVar7 < 0x3e9) && (-0x3e9 < iVar7)) {
    uVar4 = param_2 + 0xb4U & 3;
    uVar6 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) == 2) {
      iVar10 = (int)*(short *)(param_2 + 0xba);
      if (iVar7 * iVar10 < 1) {
        return;
      }
      if (iVar7 * iVar7 - iVar10 * iVar10 == 0 || iVar7 * iVar7 < iVar10 * iVar10) {
        return;
      }
      *(undefined2 *)(param_2 + 0xb8) = 0;
      *(undefined2 *)(param_2 + 0xba) = *(undefined2 *)(param_2 + 0xb8);
      *(undefined4 *)(param_2 + 0xb4) = 0;
      *(undefined2 *)(param_2 + 0xc0) = 0;
      *(undefined4 *)(param_2 + 0xa4) = 0x1e;
      *(undefined4 *)(param_2 + 0xa0) = 0;
      return;
    }
  }
  else {
    uVar4 = param_2 + 0xa0U & 3;
    uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    if ((int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) < 4) {
      *(short *)(param_2 + 0xb8) = (short)((uint)(iVar7 * 64000) >> 0x10);
    }
    else {
      *(short *)(param_2 + 0xb8) = (short)((uint)(iVar7 * DAT_020dbd8c) >> 0x10);
    }
  }
  uVar4 = param_2 + 0xb4U & 3;
  uVar6 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) != 1) {
    return;
  }
  uVar4 = param_2 + 0xa0U & 3;
  uVar3 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar6 = param_2 + 0xccU & 3;
  uVar12 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
  uVar6 = uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20;
  if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 4) {
    if (0x4000 < (int)uVar6) {
      uVar11 = (uint)((ulonglong)DAT_020dbd90 * (ulonglong)uVar6) >> 0xc |
               (((int)uVar6 >> 0x1f) * DAT_020dbd90 +
               (int)((ulonglong)DAT_020dbd90 * (ulonglong)uVar6 >> 0x20)) * 0x100000;
      *(uint *)(param_2 + 0xcc) = uVar11;
      uVar3 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
              *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
      uVar4 = param_2 + 0xd4U & 3;
      uVar12 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      uVar6 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * 0x54 +
              (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x34;
      uVar6 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      lVar2 = (longlong)(int)uVar11 *
              (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
      *(uint *)(param_2 + 0xd8) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    }
  }
  else if (0x800 < (int)uVar6) {
    uVar11 = (uint)((ulonglong)DAT_020dbd94 * (ulonglong)uVar6) >> 0xc |
             (((int)uVar6 >> 0x1f) * DAT_020dbd94 +
             (int)((ulonglong)DAT_020dbd94 * (ulonglong)uVar6 >> 0x20)) * 0x100000;
    *(uint *)(param_2 + 0xcc) = uVar11;
    uVar3 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
    uVar4 = param_2 + 0xd4U & 3;
    uVar12 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * 0x54 +
            (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x34;
    uVar6 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    lVar2 = (longlong)(int)uVar11 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20)
    ;
    *(uint *)(param_2 + 0xd8) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  }
  iVar7 = func_020d8cc8(uVar13);
  if (iVar7 != 0) {
    uVar4 = param_2 + 0xe4U & 3;
    uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
    puVar5 = (undefined4 *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    uVar8 = puVar5[1];
    uVar9 = puVar5[2];
    *(undefined4 *)(param_2 + 4) = *puVar5;
    *(undefined4 *)(param_2 + 8) = uVar8;
    *(undefined4 *)(param_2 + 0xc) = uVar9;
    uVar4 = param_2 + 8U & 3;
    uVar12 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar6 = param_2 + 0xf8U & 3;
    uVar3 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
         (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    uVar4 = param_2 + 0xe0U & 3;
    uVar6 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
      func_020d8620(uVar13);
      func_020d8648(uVar13);
    }
    else {
      *(undefined4 *)(param_2 + 0xdc) = 0;
    }
    *(undefined4 *)(param_2 + 0xb4) = 2;
    return;
  }
  func_020d8a5c(uVar13,param_2 + 4);
  uVar4 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar6 = param_2 + 0xf8U & 3;
  uVar13 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
  *(uint *)(param_2 + 8) =
       (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
       (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20);
  return;
}

