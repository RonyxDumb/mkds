/* Decompiled C draft; module arm9; ROM address 0214f51c. No matching claim. */
#include "types.h"
#include "deps/0214f51c_func_0214f51c.h"

void func_0214f51c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    do {
      uVar1 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      (*(code *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20))
                (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
      uVar1 = param_1 + 8 & 3;
      uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
      param_1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    } while (param_1 != 0);
    return;
  }
  return;
}

