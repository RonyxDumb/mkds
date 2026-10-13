/* Decompiled C draft; module arm9; ROM address 021014a0. No matching claim. */
#include "types.h"
#include "deps/021014a0_func_021014a0.h"

uint func_021014a0(int param_1,undefined4 param_2,undefined2 param_3)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = iRam02101614;
  uVar1 = param_1 + 0x15cU & 3;
  uVar5 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  uVar7 = param_1 + 0x130U & 3;
  uVar6 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0x26cU & 3;
    uVar5 = *(uint *)(param_1 + 0x26cU & 0xfffffffc);
    if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
      uVar1 = param_1 + 0x170U & 3;
      uVar4 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
      uVar5 = param_1 + 0x17cU & 3;
      uVar6 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      *(uint *)(param_1 + 0x170) =
           (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
           (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      uVar5 = uRam02101610;
      uVar1 = param_1 + 0x17cU & 3;
      uVar6 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      *(uint *)(param_1 + 0x17c) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + iVar3;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = (uint)*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + uVar7 * 2);
      uVar1 = param_1 + 0x16cU & 3;
      uVar5 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
              (longlong)(int)uVar6;
      *(uint *)(param_1 + 0x16c) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar1 = param_1 + 0x174U & 3;
      uVar5 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
              (longlong)(int)uVar6;
      *(uint *)(param_1 + 0x174) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    }
    else {
      uVar1 = param_1 + 0x16cU & 3;
      uVar5 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
      uVar6 = (uint)*(ushort *)
                     ((*(uint *)(uRam02101610 & 0xfffffffc) >> (uRam02101610 & 3) * 8 |
                      *(uint *)(uRam02101610 & 0xfffffffc) << (uRam02101610 & 3) * -8 + 0x20) +
                     uVar7 * 2);
      lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
              (longlong)(int)uVar6;
      *(uint *)(param_1 + 0x16c) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar1 = param_1 + 0x174U & 3;
      uVar5 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
              (longlong)(int)uVar6;
      *(uint *)(param_1 + 0x174) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    }
  }
  else {
    func_0210174c();
  }
  func_02101964(param_1,param_2);
  if (7 < (int)uVar7) {
    if (*(short *)(param_1 + 0xd8) < 0x1f) {
      *(short *)(param_1 + 0xd8) = *(short *)(param_1 + 0xd8) + 6;
    }
    if (uVar7 == 0x27) {
      uVar1 = param_1 + 0x15cU & 3;
      uVar5 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
      if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
        uVar1 = param_1 + 0x16cU & 3;
        uVar5 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
        *(uint *)(param_1 + 0x178) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
        uVar1 = param_1 + 0x174U & 3;
        uVar5 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
        *(uint *)(param_1 + 0x180) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      }
    }
    else if (uVar7 == 0x28) {
      uVar1 = param_1 + 0x15cU & 3;
      uVar5 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
      if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
        uVar1 = param_1 + 0x16cU & 3;
        uVar4 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
        uVar5 = param_1 + 0x178U & 3;
        uVar6 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
        *(uint *)(param_1 + 0x178) =
             (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
             (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
        uVar1 = param_1 + 0x174U & 3;
        uVar4 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
        uVar5 = param_1 + 0x180U & 3;
        uVar6 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
        *(uint *)(param_1 + 0x180) =
             (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
             (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      }
      *(undefined2 *)(param_1 + 0x13c) = param_3;
      *(undefined2 *)(param_1 + 0x13e) = 1;
      *(undefined4 *)(param_1 + 0x26c) = 0;
    }
  }
  return uVar7;
}

