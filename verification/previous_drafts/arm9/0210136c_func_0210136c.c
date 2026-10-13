/* Decompiled C draft; module arm9; ROM address 0210136c. No matching claim. */
#include "types.h"
#include "deps/0210136c_func_0210136c.h"

void func_0210136c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x250U & 3;
  uVar3 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 0xffffffff) {
    return;
  }
  uVar1 = param_1 + 0x24cU & 3;
  uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  uVar3 = param_1 + 0x130U & 3;
  uVar4 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if ((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) && ((int)uVar3 < 0x28)) {
    return;
  }
  *(uint *)(param_1 + 0x268) = uVar3 - 0x28;
  uVar1 = param_1 + 0x250U & 3;
  uVar3 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
  *(uint *)(param_1 + 0x140) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0x13c) = 2;
  *(undefined2 *)(param_1 + 0x13e) = 1;
  return;
}

