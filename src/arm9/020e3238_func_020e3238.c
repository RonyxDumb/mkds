/* Decompiled C draft; module arm9; ROM address 020e3238. No matching claim. */
#include "types.h"
#include "deps/020e3238_func_020e3238.h"

void func_020e3238(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - iRam020e329c;
  uVar4 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = param_1 + 0x14U & 3;
  uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
       (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  uVar4 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0xb0U & 3;
  uVar2 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar1 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar2 = uVar1;
  uVar4 = uVar3;
  if ((int)uVar3 < (int)uVar1) {
    uVar4 = param_1 + 0x80;
    uVar2 = 5;
  }
  if ((int)uVar3 < (int)uVar1) {
    *(short *)(uVar4 + 0x10) = (short)uVar2;
    *(undefined2 *)(uVar4 + 0x12) = 1;
  }
  uVar4 = param_1 + 0xb4U & 3;
  uVar2 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
    *(short *)(param_1 + 0xb8) = *(short *)(param_1 + 0xb8) + -0x400;
  }
  else {
    *(short *)(param_1 + 0xb8) = *(short *)(param_1 + 0xb8) + 0x400;
  }
  return;
}

