/* Decompiled C draft; module arm9; ROM address 020a3154. No matching claim. */
#include "types.h"
#include "deps/020a3154_func_020a3154.h"

void func_020a3154(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_2 + 0xa4U & 3;
  uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0) {
    *(undefined4 *)(param_2 + 0xd8) = 0;
    *(undefined4 *)(param_2 + 0xd0) = 0x1000;
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(uint *)(param_2 + 0xa0) = uVar3 - 1;
    if ((int)uVar3 < 1) {
      func_0208b748(0x5b,param_2 + 4,param_2,uRam020a35a8);
      func_0208b748(0x5c,param_2 + 4,param_2,uRam020a35a8);
      func_0208b748(0x5d,param_2 + 4,param_2,uRam020a35a8);
      uVar4 = func_020d4ef4(param_2 + 4);
      func_0210b8f4(param_2 + 4,uVar4);
      func_020d2398(param_2);
    }
    else {
      uVar3 = param_2 + 200U & 3;
      uVar7 = *(uint *)(param_2 + 200U & 0xfffffffc);
      uVar2 = param_2 + 0xccU & 3;
      uVar5 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
      *(uint *)(param_2 + 200) =
           (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) +
           (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
      uVar3 = param_2 + 200U & 3;
      uVar2 = *(uint *)(param_2 + 200U & 0xfffffffc);
      if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0) {
        uVar3 = param_2 + 0xccU & 3;
        uVar2 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
        uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        if ((int)uVar3 < 0) {
          *(uint *)(param_2 + 0xcc) = uVar3 + 200;
        }
        else {
          *(undefined4 *)(param_2 + 0xcc) = 0x640;
        }
      }
      else {
        uVar3 = param_2 + 0xccU & 3;
        uVar2 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
        uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        if ((int)uVar3 < 0) {
          *(undefined4 *)(param_2 + 0xcc) = 0xfffff9c0;
        }
        else {
          *(uint *)(param_2 + 0xcc) = uVar3 - 200;
        }
      }
    }
    uVar3 = param_2 + 200U & 3;
    uVar2 = *(uint *)(param_2 + 200U & 0xfffffffc);
    *(ushort *)(param_2 + 0x7e) =
         ((ushort)(uVar2 >> uVar3 * 8) | (ushort)(uVar2 << uVar3 * -8 + 0x20)) + 0x4000;
    uVar3 = param_2 + 0x14U & 3;
    uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iRam020a35ac;
    uVar3 = param_2 + 0xc0U & 3;
    uVar2 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    *(uint *)(param_2 + 0xc0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x2000;
    uVar3 = param_2 + 0x10U & 3;
    uVar2 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    lVar1 = (ulonglong)uVar3 * 0xc00;
    *(uint *)(param_2 + 0x10) =
         (uint)lVar1 >> 0xc |
         (((int)uVar3 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar3 = param_2 + 0x14U & 3;
    uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    lVar1 = (ulonglong)uVar3 * 0xc00;
    *(uint *)(param_2 + 0x14) =
         (uint)lVar1 >> 0xc |
         (((int)uVar3 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar3 = param_2 + 0x18U & 3;
    uVar2 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    lVar1 = (ulonglong)uVar3 * 0xc00;
    *(uint *)(param_2 + 0x18) =
         (uint)lVar1 >> 0xc |
         (((int)uVar3 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,param_2 + 4);
    VecFx32_Add(param_2 + 0xb0,param_2 + 0xbc,param_2 + 0xb0);
    return;
  }
  uVar3 = param_2 + 0xfcU & 3;
  uVar2 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    uVar3 = param_2 + 0xd8U & 3;
    uVar7 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
    uVar2 = param_2 + 0xdcU & 3;
    uVar5 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    *(uint *)(param_2 + 0xd8) =
         (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) +
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar3 = param_2 + 0xd8U & 3;
    uVar2 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0) {
      uVar3 = param_2 + 0xdcU & 3;
      uVar2 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 0) {
        *(uint *)(param_2 + 0xdc) = uVar3 + 10;
      }
      else {
        *(undefined4 *)(param_2 + 0xdc) = 0x32;
      }
    }
    else {
      uVar3 = param_2 + 0xdcU & 3;
      uVar2 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 0) {
        *(undefined4 *)(param_2 + 0xdc) = 0xffffffce;
      }
      else {
        *(uint *)(param_2 + 0xdc) = uVar3 - 10;
      }
    }
    uVar3 = param_2 + 0xa4U & 3;
    uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) ==
         (int)*(char *)((*(uint *)(uRam020a359c & 0xfffffffc) >> (uRam020a359c & 3) * 8 |
                        *(uint *)(uRam020a359c & 0xfffffffc) << (uRam020a359c & 3) * -8 + 0x20) +
                       0x62)) && (iVar6 = IsAwardOrStaffRoll(), iVar6 == 1)) {
      uVar3 = param_2 + 0xa4U & 3;
      uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      uVar4 = GetDriverEntry((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xffff);
      uVar3 = param_2 + 0xd0U & 3;
      uVar9 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
      uVar2 = param_2 + 0xd8U & 3;
      uVar7 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
      uVar5 = param_2 + 0xd4U & 3;
      uVar8 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      func_020249b8(uVar4,(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
                          (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20),
                    uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    }
    iVar6 = iRam020a35a4;
    uVar3 = param_2 + 0xf4U & 3;
    uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 1) ||
       (uVar3 = param_2 + 0xf8U & 3, uVar2 = *(uint *)(param_2 + 0xf8U & 0xfffffffc),
       uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0)) {
      uVar3 = param_2 + 0xb0U & 3;
      uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 4) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = param_2 + 0xb4U & 3;
      uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      *(uint *)(param_2 + 8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar6;
      uVar3 = param_2 + 0xb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      *(uint *)(param_2 + 0xc) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      return;
    }
    func_020a36a8(param_2);
    iVar6 = func_020a369c(param_2);
    if (iVar6 != 0) {
      return;
    }
    uVar3 = func_020a3690(param_2);
    if (uRam020a35a0 <= uVar3) {
      return;
    }
    func_020a35b0(param_2);
    return;
  }
  if (uVar3 != 1) {
    if (uVar3 != 2) {
      return;
    }
    *(undefined4 *)(param_2 + 0xd8) = 0;
    *(undefined4 *)(param_2 + 0xd0) = 0x1000;
    iVar6 = iRam020a35a4;
    uVar3 = param_2 + 0xf4U & 3;
    uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 1) ||
       (uVar3 = param_2 + 0xf8U & 3, uVar2 = *(uint *)(param_2 + 0xf8U & 0xfffffffc),
       uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0)) {
      uVar3 = param_2 + 0xb0U & 3;
      uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(uint *)(param_2 + 4) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = param_2 + 0xb4U & 3;
      uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      *(uint *)(param_2 + 8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar6;
      uVar3 = param_2 + 0xb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      *(uint *)(param_2 + 0xc) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      return;
    }
    func_020a36a8(param_2);
    iVar6 = func_020a369c(param_2);
    if (iVar6 != 0) {
      return;
    }
    uVar3 = func_020a3690(param_2);
    if (uRam020a35a0 <= uVar3) {
      return;
    }
    func_020a35b0(param_2);
    return;
  }
  *(undefined4 *)(param_2 + 0xd8) = 0;
  uVar3 = param_2 + 0xd0U & 3;
  uVar7 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
  uVar2 = param_2 + 0xd4U & 3;
  uVar5 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  *(uint *)(param_2 + 0xd0) =
       (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) +
       (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0xd0U & 3;
  uVar2 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
  if (0xfff < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
    uVar3 = param_2 + 0xd4U & 3;
    uVar2 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    *(uint *)(param_2 + 0xd4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 200;
  }
  uVar3 = param_2 + 0xd4U & 3;
  uVar2 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  if (((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0) &&
     (uVar3 = param_2 + 0xd0U & 3, uVar2 = *(uint *)(param_2 + 0xd0U & 0xfffffffc),
     (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0x1001)) {
    *(undefined4 *)(param_2 + 0xd0) = 0x1000;
    *(undefined4 *)(param_2 + 0xfc) = 2;
  }
  iVar6 = iRam020a35a4;
  uVar3 = param_2 + 0xf4U & 3;
  uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 1) ||
     (uVar3 = param_2 + 0xf8U & 3, uVar2 = *(uint *)(param_2 + 0xf8U & 0xfffffffc),
     uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0)) {
    uVar3 = param_2 + 0xb0U & 3;
    uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    *(uint *)(param_2 + 4) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = param_2 + 0xb4U & 3;
    uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    *(uint *)(param_2 + 8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar6;
    uVar3 = param_2 + 0xb8U & 3;
    uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    *(uint *)(param_2 + 0xc) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    return;
  }
  func_020a36a8(param_2);
  iVar6 = func_020a369c(param_2);
  if (iVar6 != 0) {
    return;
  }
  uVar3 = func_020a3690(param_2);
  if (uRam020a35a0 <= uVar3) {
    return;
  }
  func_020a35b0(param_2);
  return;
}

