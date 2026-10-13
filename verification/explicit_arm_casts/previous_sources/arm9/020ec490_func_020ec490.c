/* Decompiled C draft; module arm9; ROM address 020ec490. No matching claim. */
#include "types.h"
#include "deps/020ec490_func_020ec490.h"

void func_020ec490(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_1 + 0xa8U & 3;
  uVar1 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    *(short *)(param_1 + 0xac) = *(short *)(param_1 + 0xac) - *(short *)(param_1 + 0xae);
  }
  else {
    *(short *)(param_1 + 0xac) = *(short *)(param_1 + 0xac) + *(short *)(param_1 + 0xae);
  }
  uVar2 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar1 = param_1 + 0xa4U & 3;
  uVar3 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) =
       (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) -
       (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  VecFx32_Add(param_1 + 4,param_1 + 0x10,param_1 + 4);
  uVar2 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0xa0U & 3;
  uVar1 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar1;
  if ((int)uVar3 < (int)uVar1) {
    uVar2 = 2;
  }
  if ((int)uVar3 < (int)uVar1) {
    *(short *)(param_1 + 0x90) = (short)uVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

