/* Decompiled C draft; module arm9; ROM address 020f00f0. No matching claim. */
#include "types.h"
#include "deps/020f00f0_func_020f00f0.h"

void func_020f00f0(uint param_1)

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
  uVar2 = (*(uint *)(uRam020f0150 & 0xfffffffc) >> (uRam020f0150 & 3) * 8 |
          *(uint *)(uRam020f0150 & 0xfffffffc) << (uRam020f0150 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 5) {
    if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) {
      func_020f81c0();
      return;
    }
    return;
  }
  return;
}

