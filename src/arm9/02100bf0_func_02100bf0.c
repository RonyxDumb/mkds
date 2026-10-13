/* Decompiled C draft; module arm9; ROM address 02100bf0. No matching claim. */
#include "types.h"
#include "deps/02100bf0_func_02100bf0.h"

void func_02100bf0(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  undefined4 uVar6;
  uint uVar4;
  
  if (*(short *)(param_1 + 0x164) < 0x1f) {
    *(short *)(param_1 + 0x164) = *(short *)(param_1 + 0x164) + 5;
  }
  uVar2 = uRam02100dcc;
  uVar4 = param_1 + 0x178U & 3;
  uVar3 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uRam02100dcc * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x178) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uRam02100dcc + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 0x180U & 3;
  uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x180) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 0x12) {
    uVar4 = param_1 + 0x19cU & 3;
    uVar2 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
      *(undefined4 *)(param_1 + 0x19c) = uRam02100dd0;
      uVar4 = param_1 + 0x17cU & 3;
      uVar2 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1a0) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    }
    uVar4 = param_1 + 0x17cU & 3;
    uVar5 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
    uVar2 = param_1 + 0x19cU & 3;
    uVar3 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    *(uint *)(param_1 + 0x17c) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar4 = param_1 + 0x170U & 3;
    uVar5 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
    uVar2 = param_1 + 0x17cU & 3;
    uVar3 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
    *(uint *)(param_1 + 0x170) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    func_02101964(param_1,1);
    uVar4 = param_1 + 0x19cU & 3;
    uVar2 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    if ((-1 < (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) &&
       (uVar4 = param_1 + 0x17cU & 3, uVar5 = *(uint *)(param_1 + 0x17cU & 0xfffffffc),
       uVar2 = param_1 + 0x1a0U & 3, uVar3 = *(uint *)(param_1 + 0x1a0U & 0xfffffffc),
       (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) <=
       (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
      return;
    }
    uVar4 = param_1 + 0x130U & 3;
    uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
    *(uint *)(param_1 + 0x130) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - 1;
    uVar4 = param_1 + 0x19cU & 3;
    uVar2 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if (-1 < (int)uVar4) {
      return;
    }
    uVar2 = param_1 + 0x17cU & 3;
    uVar3 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if (-0xc01 < (int)uVar2) {
      if ((int)uVar2 < 1) {
        return;
      }
      if ((int)(uVar2 + uVar4) < 0 != SBORROW4(uVar2,-uVar4)) {
        uVar4 = param_1 + 0x168U & 3;
        uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
        func_020f8e3c(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,0xf5);
        return;
      }
      return;
    }
    *(undefined4 *)(param_1 + 0x19c) = uRam02100dd4;
    return;
  }
  uVar4 = param_1 + 0x16cU & 3;
  uVar5 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  uVar2 = param_1 + 0x178U & 3;
  uVar3 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
  *(uint *)(param_1 + 0x16c) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar4 = param_1 + 0x174U & 3;
  uVar5 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  uVar2 = param_1 + 0x180U & 3;
  uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  *(uint *)(param_1 + 0x174) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x8000000) == 0) {
    uVar6 = 5;
  }
  else {
    uVar6 = 4;
  }
  func_02101618(param_1,1,uVar6);
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x8000000) == 0) {
    return;
  }
  uVar4 = param_1 + 0x24cU & 3;
  uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    return;
  }
  uVar4 = param_1 + 0x144U & 3;
  uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = param_1 + 0x264U & 3;
    uVar2 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if (uVar4 != 0xffffffff) {
      if (uVar4 - 2 < 2) {
        *(undefined4 *)(param_1 + 0x144) = 1;
        *(undefined4 *)(param_1 + 0x264) = 0xffffffff;
      }
      return;
    }
    return;
  }
  return;
}

