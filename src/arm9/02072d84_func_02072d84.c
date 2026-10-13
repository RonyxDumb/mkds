/* Decompiled C draft; module arm9; ROM address 02072d84. No matching claim. */
#include "types.h"
#include "deps/02072d84_func_02072d84.h"

undefined4 func_02072d84(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar3;
  uint uVar2;
  
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar3 = 0;
  if ((uVar2 & 0x4000000) == 0) {
    if ((uVar2 & 0x200000) != 0) {
      uVar2 = param_1 + 0x4bcU & 3;
      uVar1 = *(uint *)(param_1 + 0x4bcU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
      if (iRam02072eb4 < (int)uVar2) {
        *(uint *)(param_1 + 0x4bc) =
             (uint)((ulonglong)uRam02072eb0 * (ulonglong)uVar2) >> 0xc |
             (((int)uVar2 >> 0x1f) * uRam02072eb0 +
             (int)((ulonglong)uRam02072eb0 * (ulonglong)uVar2 >> 0x20)) * 0x100000;
      }
      uVar2 = param_1 + 0x4bcU & 3;
      uVar1 = *(uint *)(param_1 + 0x4bcU & 0xfffffffc);
      *param_2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
  }
  else {
    uVar2 = param_1 + 0x4bcU & 3;
    uVar1 = *(uint *)(param_1 + 0x4bcU & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (iRam02072eac < (int)uVar2) {
      *(uint *)(param_1 + 0x4bc) =
           (uint)((ulonglong)uRam02072eb0 * (ulonglong)uVar2) >> 0xc |
           (((int)uVar2 >> 0x1f) * uRam02072eb0 +
           (int)((ulonglong)uRam02072eb0 * (ulonglong)uVar2 >> 0x20)) * 0x100000;
    }
    uVar2 = param_1 + 0x4bcU & 3;
    uVar1 = *(uint *)(param_1 + 0x4bcU & 0xfffffffc);
    *param_2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  *(short *)(param_1 + 0x3c0) = *(short *)(param_1 + 0x3c0) + 1;
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
    if (*(short *)(param_1 + 0x3c0) == 0x16) {
      func_02055a94();
    }
    else if (*(short *)(param_1 + 0x3c0) == 0x19) {
      func_02055c18(0x3c);
    }
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if ((((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) ||
     (*(short *)(param_1 + 0x3c0) != 0x55)) {
    if (0x78 < *(short *)(param_1 + 0x3c0)) {
      func_02063ad0(param_1);
      uVar3 = 1;
    }
  }
  else {
    func_020e7a40();
  }
  return uVar3;
}

