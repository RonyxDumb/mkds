/* Decompiled C draft; module arm9; ROM address 020f0044. No matching claim. */
#include "types.h"
#include "deps/020f0044_func_020f0044.h"

void func_020f0044(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x1fc & 3;
  uVar1 = *(uint *)(param_1 + 0x1fc & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x7c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400) != 0) {
    return;
  }
  uVar2 = param_1 + 0x30 & 3;
  uVar1 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0x13) {
    func_020f45f0(param_1 + 0x30,0);
  }
  uVar2 = (*(uint *)(uRam020f00ec & 0xfffffffc) >> (uRam020f00ec & 3) * 8 |
          *(uint *)(uRam020f00ec & 0xfffffffc) << (uRam020f00ec & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 5) {
    if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) {
      func_020f81c0(param_1);
    }
    uVar2 = param_1 + 0x14 & 3;
    uVar1 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0x13) {
      *(undefined4 *)(param_1 + 0x14) = 0x13;
    }
    uVar2 = (*(uint *)(uRam020f00ec & 0xfffffffc) >> (uRam020f00ec & 3) * 8 |
            *(uint *)(uRam020f00ec & 0xfffffffc) << (uRam020f00ec & 3) * -8 + 0x20) + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 5) {
      uVar2 = param_1 + 0x58 & 3;
      uVar1 = *(uint *)(param_1 + 0x58 & 0xfffffffc);
      if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0xf) {
        func_020edb00(param_1 + 0x58);
        return;
      }
      return;
    }
    return;
  }
  return;
}

