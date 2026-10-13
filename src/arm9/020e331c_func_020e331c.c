/* Decompiled C draft; module arm9; ROM address 020e331c. No matching claim. */
#include "types.h"
#include "deps/020e331c_func_020e331c.h"

void func_020e331c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  bool bVar5;
  uint uVar3;
  
  uVar1 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar3 = param_1 + 0xa4U & 3;
  uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  bVar5 = uVar3 <= (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  if (bVar5) {
    uVar3 = 1;
  }
  if (bVar5) {
    *(short *)(param_1 + 0x90) = (short)uVar3;
    *(short *)(param_1 + 0x92) = (short)uVar3;
  }
  return;
}

