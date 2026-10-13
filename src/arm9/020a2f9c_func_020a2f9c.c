/* Decompiled C draft; module arm9; ROM address 020a2f9c. No matching claim. */
#include "types.h"
#include "deps/020a2f9c_func_020a2f9c.h"

void func_020a2f9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  *(undefined4 *)(param_1 + 0xd4) = param_3;
  uVar1 = param_1 + 0xd0U & 3;
  uVar4 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar3 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  *(uint *)(param_1 + 0xd0) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  uVar1 = param_1 + 0xd0U & 3;
  uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if (0xfff < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xd4) = 600;
    *(undefined4 *)(param_1 + 0xfc) = 1;
  }
  return;
}

