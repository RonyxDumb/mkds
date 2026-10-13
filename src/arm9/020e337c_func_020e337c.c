/* Decompiled C draft; module arm9; ROM address 020e337c. No matching claim. */
#include "types.h"
#include "deps/020e337c_func_020e337c.h"

void func_020e337c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - iRam020e33bc;
  uVar2 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = param_1 + 0x14U & 3;
  uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
       (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar1 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0xb0U & 3;
  uVar3 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar3;
  if ((int)uVar1 < (int)uVar3) {
    uVar2 = 5;
  }
  if ((int)uVar1 < (int)uVar3) {
    *(short *)(param_1 + 0x90) = (short)uVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

