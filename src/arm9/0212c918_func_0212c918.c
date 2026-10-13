/* Decompiled C draft; module arm9; ROM address 0212c918. No matching claim. */
#include "types.h"
#include "deps/0212c918_func_0212c918.h"

void func_0212c918(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    func_0212c824();
    return;
  }
  return;
}

