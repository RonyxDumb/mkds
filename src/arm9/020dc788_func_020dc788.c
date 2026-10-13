/* Decompiled C draft; module arm9; ROM address 020dc788. No matching claim. */
#include "types.h"
#include "deps/020dc788_func_020dc788.h"

void func_020dc788(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = uRam020dc7b8;
  *(undefined4 *)(param_1 + 0xe8) = 0xd000;
  *(undefined4 *)(param_1 + 0xec) = uVar2;
  uVar1 = param_1 + 0xfcU & 3;
  uVar3 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0x1d8U & 3;
    uVar3 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xa8) = uRam020dc7bc;
  }
  *(undefined4 *)(param_1 + 0x14) = 0x8000;
  return;
}

