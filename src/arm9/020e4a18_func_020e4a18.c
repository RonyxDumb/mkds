/* Decompiled C draft; module arm9; ROM address 020e4a18. No matching claim. */
#include "types.h"
#include "deps/020e4a18_func_020e4a18.h"

void func_020e4a18(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x84U & 3;
  uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar1;
  if (300 < uVar1) {
    uVar2 = 3;
  }
  if (300 < uVar1) {
    *(short *)(param_1 + 0x90) = (short)uVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

