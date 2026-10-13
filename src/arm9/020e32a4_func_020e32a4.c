/* Decompiled C draft; module arm9; ROM address 020e32a4. No matching claim. */
#include "types.h"
#include "deps/020e32a4_func_020e32a4.h"

void func_020e32a4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 + 0xb4U & 3;
  uVar1 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
    *(short *)(param_1 + 0xb8) = *(short *)(param_1 + 0xb8) + -0x400;
  }
  else {
    *(short *)(param_1 + 0xb8) = *(short *)(param_1 + 0xb8) + 0x400;
  }
  uVar3 = param_1 + 0x14U & 3;
  uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) - 0x400;
  uVar3 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar3 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0xb0U & 3;
  uVar1 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar3 = uVar1;
  if ((int)uVar2 < (int)uVar1) {
    uVar3 = 5;
  }
  if ((int)uVar2 < (int)uVar1) {
    *(short *)(param_1 + 0x90) = (short)uVar3;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

