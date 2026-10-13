/* Decompiled C draft; module arm9; ROM address 020e4990. No matching claim. */
#include "types.h"
#include "deps/020e4990_func_020e4990.h"

void func_020e4990(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = param_1 + 0x14U & 3;
  uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) +
       (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20);
  uVar2 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar1 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0xbcU & 3;
  uVar4 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
  uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = uVar4;
  if ((int)uVar4 < (int)uVar1) {
    uVar2 = 0;
  }
  if ((int)uVar4 < (int)uVar1) {
    *(short *)(param_1 + 0x90) = (short)uVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

