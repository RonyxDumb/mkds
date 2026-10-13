/* Decompiled C draft; module arm9; ROM address 0210dc7c. No matching claim. */
#include "types.h"
#include "deps/0210dc7c_func_0210dc7c.h"

void func_0210dc7c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  func_0210e434((undefined4 *)(uintptr_t)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20));
  *puRam0210dca4 = 0;
  return;
}

