/* Decompiled C draft; module arm9; ROM address 020d5fb4. No matching claim. */
#include "types.h"
#include "deps/020d5fb4_func_020d5fb4.h"

void func_020d5fb4(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar3;
  
  uVar3 = param_2 + 0xe0U & 3;
  uVar2 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (0 < (int)uVar3) {
    *(uint *)(param_2 + 0xe0) = uVar3 - 1;
    uVar3 = param_2 + 0xe0U & 3;
    uVar2 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffd;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfff7;
      *(undefined2 *)(param_2 + 0x66) = 1;
      return;
    }
    return;
  }
  uVar3 = param_2 + 0xe4U & 3;
  uVar9 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
  uVar2 = param_2 + 0xecU & 3;
  uVar8 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  func_020d84e4(param_2 + 0xa4);
  func_020d8bc0(param_2 + 0xa4,param_2 + 0xe4);
  uVar7 = param_2 + 0xe4U & 3;
  uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
  *(uint *)(param_2 + 0x10) =
       (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) -
       (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20);
  uVar3 = param_2 + 0xecU & 3;
  uVar7 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  *(uint *)(param_2 + 0x18) =
       (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
       (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0x100U & 3;
  uVar6 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  uVar2 = param_2 + 0xf8U & 3;
  uVar7 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
  *(uint *)(param_2 + 0x100) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0x104U & 3;
  uVar6 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  uVar2 = param_2 + 0xfcU & 3;
  uVar7 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
  *(uint *)(param_2 + 0x104) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0x10U & 3;
  uVar6 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar2 = param_2 + 0xf8U & 3;
  uVar7 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
  *(uint *)(param_2 + 0x10) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0x18U & 3;
  uVar6 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  uVar2 = param_2 + 0xfcU & 3;
  uVar7 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
  *(uint *)(param_2 + 0x18) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0xe4U & 3;
  uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
  uVar2 = param_2 + 0x100U & 3;
  uVar7 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  *(uint *)(param_2 + 4) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0xecU & 3;
  uVar6 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  uVar2 = param_2 + 0x104U & 3;
  uVar7 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  *(uint *)(param_2 + 0xc) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0x100U & 3;
  uVar2 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  *(int *)(param_2 + 0x100) = (int)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x3f) >> 6;
  uVar3 = param_2 + 0x104U & 3;
  uVar2 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  *(int *)(param_2 + 0x104) = (int)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x3f) >> 6;
  uVar3 = param_2 + 8U & 3;
  uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar6 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_2 + 0x11cU & 3;
  uVar7 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
  uVar2 = param_2 + 0xe8U & 3;
  uVar8 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
  iVar4 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) -
          (uVar6 - (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20));
  if (iVar4 < 1) {
    *(short *)(param_2 + 0x108) = *(short *)(param_2 + 0x108) + 1;
  }
  else {
    *(uint *)(param_2 + 8) = uVar6 + iVar4;
    uVar3 = param_2 + 0x14U & 3;
    uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 < -0x2000) {
        uVar2 = param_2 + 0x120U & 3;
        uVar7 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        lVar1 = (longlong)(int)uVar3 *
                (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
        *(uint *)(param_2 + 0x14) = -((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
        uVar3 = param_2 + 0xf4U & 3;
        uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
        *(uint *)(param_2 + 0xf4) =
             (uint)(uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0);
        uVar3 = param_2 + 0x14U & 3;
        uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
        if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0x4001) {
          *(undefined4 *)(param_2 + 0xf8) = 0;
          *(undefined4 *)(param_2 + 0xfc) = 0;
        }
        else {
          uVar3 = param_2 + 0xb0U & 3;
          uVar6 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
          *(undefined4 *)(param_2 + 0x14) = 0x4000;
          uVar2 = param_2 + 0xf4U & 3;
          uVar7 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
          uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0xffff;
          if (uVar7 >> uVar2 * 8 == 0 && uVar7 << uVar2 * -8 + 0x20 == 0) {
            iVar4 = uVar3 * 0xc;
            uVar3 = param_2 + 0xf0U & 3;
            uVar2 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
            uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar4;
            uVar2 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(int *)(param_2 + 0xf8) = (int)-(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 1;
            uVar3 = param_2 + 0xf0U & 3;
            uVar2 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
            uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar4 + 8;
            uVar2 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(int *)(param_2 + 0xfc) = (int)-(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 1;
          }
          else {
            iVar4 = uVar3 * 0xc;
            uVar3 = param_2 + 0xf0U & 3;
            uVar2 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
            uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar4;
            uVar2 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(uint *)(param_2 + 0xf8) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) << 1;
            uVar3 = param_2 + 0xf0U & 3;
            uVar2 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
            uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar4 + 8;
            uVar2 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(int *)(param_2 + 0xfc) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 1;
          }
        }
      }
      else {
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
    }
    *(undefined2 *)(param_2 + 0x108) = 0;
  }
  if (*(ushort *)(param_2 + 0x108) < 10) {
    func_020d275c(param_2,uRam020d6348);
  }
  uVar3 = param_2 + 0x14U & 3;
  uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  *(uint *)(param_2 + 0x14) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x400;
  uVar3 = param_2 + 8U & 3;
  uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar2 = param_2 + 0x14U & 3;
  uVar7 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  *(uint *)(param_2 + 8) =
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
       (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0x110U & 3;
  uVar2 = *(uint *)(param_2 + 0x110U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar3 != 0) &&
     (uVar2 = param_2 + 0x20U & 3, uVar7 = *(uint *)(param_2 + 0x20U & 0xfffffffc),
     uVar6 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20, uVar2 = param_2 + 0x114U & 3,
     uVar7 = *(uint *)(param_2 + 0x114U & 0xfffffffc),
     (int)uVar6 < (int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20))) {
    uVar6 = uVar6 + uVar3;
    uVar3 = (uint)((ulonglong)uVar6 * 0x1e000) >> 0xc |
            (int)((ulonglong)uVar6 * 0x1e000 >> 0x20) * 0x100000;
    FX_DivAsync(0x1000,uVar3);
    *(uint *)(param_2 + 0x1c) = uVar6;
    *(uint *)(param_2 + 0x20) = uVar6;
    *(uint *)(param_2 + 0x24) = uVar6;
    *(uint *)(param_2 + 0x11c) = uVar3;
    *(uint *)(param_2 + 0x58) =
         (uint)((ulonglong)uVar6 * 0x1b000) >> 0xc |
         (int)((ulonglong)uVar6 * 0x1b000 >> 0x20) * 0x100000;
    if (-1 < *(short *)(param_2 + 100)) {
      uVar3 = param_2 + 0x58U & 3;
      uVar2 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
      func_020d5148((int)*(short *)(param_2 + 100),uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    }
    uVar3 = param_2 + 0x98U & 3;
    uVar2 = *(uint *)(param_2 + 0x98U & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x2c;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    *(uint *)(param_2 + 0x68) =
         (uint)((ulonglong)uVar6 * (ulonglong)uVar3) >> 0xc |
         (((int)uVar3 >> 0x1f) * uVar6 +
         uVar3 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)uVar6 * (ulonglong)uVar3 >> 0x20)) *
         0x100000;
    uVar5 = FX_GetDivResult();
    *(undefined4 *)(param_2 + 0x118) = uVar5;
  }
  uVar3 = param_2 + 0xbcU & 3;
  uVar2 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = param_2 + 8U & 3;
    uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0) {
      func_020d634c((ushort *)(uintptr_t)(param_2),0);
      return;
    }
    return;
  }
  func_020d634c((ushort *)(uintptr_t)(param_2),0);
  return;
}

