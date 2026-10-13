/* Decompiled C draft; module arm9; ROM address 0206c14c. No matching claim. */
#include "types.h"
#include "deps/0206c14c_func_0206c14c.h"

void func_0206c14c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 2) != 0) {
    uVar1 = param_1 + 0x310U & 3;
    uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
    func_0208c1ac(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

