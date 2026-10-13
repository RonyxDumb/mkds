/* Decompiled C draft; module arm9; ROM address 020f0df8. No matching claim. */
#include "types.h"
#include "deps/020f0df8_func_020f0df8.h"

void func_020f0df8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020ed718();
    return;
  }
  func_020ed79c();
  return;
}

