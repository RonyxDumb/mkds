/* Decompiled C draft; module arm9; ROM address 020ec7e8. No matching claim. */
#include "types.h"
#include "deps/020ec7e8_func_020ec7e8.h"

bool func_020ec7e8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0xa8U & 3;
  uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    *(short *)(param_1 + 0xac) = *(short *)(param_1 + 0xac) - *(short *)(param_1 + 0xae);
  }
  else {
    *(short *)(param_1 + 0xac) = *(short *)(param_1 + 0xac) + *(short *)(param_1 + 0xae);
  }
  uVar1 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar2 = param_1 + 0xa4U & 3;
  uVar3 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  VecFx32_Add(param_1 + 4,param_1 + 0x10,param_1 + 4);
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = param_1 + 0xa0U & 3;
  uVar3 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  return (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) <
         (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
}

