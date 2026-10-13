/* Decompiled C draft; module arm9; ROM address 020f8e3c. No matching claim. */
#include "types.h"
#include "deps/020f8e3c_func_020f8e3c.h"

void func_020f8e3c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return;
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
    func_020719bc();
    return;
  }
  return;
}

