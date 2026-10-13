/* Decompiled C draft; module arm9; ROM address 020edad8. No matching claim. */
#include "types.h"
#include "deps/020edad8_func_020edad8.h"

void func_020edad8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x24) = 10;
  uVar1 = param_1 + 0x170U & 3;
  uVar2 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = param_1 + 0xcU & 3;
    uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x14) = 0x13;
    *(undefined4 *)(param_1 + 0x170) = 0;
  }
  return;
}

