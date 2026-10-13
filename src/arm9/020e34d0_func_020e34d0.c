/* Decompiled C draft; module arm9; ROM address 020e34d0. No matching claim. */
#include "types.h"
#include "deps/020e34d0_func_020e34d0.h"

void func_020e34d0(int param_1)

{
  uint uVar1;
  bool bVar3;
  uint uVar2;
  
  uVar2 = param_1 + 0x84U & 3;
  uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  bVar3 = 0x13 < uVar2;
  if (bVar3) {
    uVar2 = 3;
  }
  if (bVar3) {
    *(short *)(param_1 + 0x90) = (short)uVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

