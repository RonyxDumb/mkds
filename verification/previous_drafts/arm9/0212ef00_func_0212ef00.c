/* Decompiled C draft; module arm9; ROM address 0212ef00. No matching claim. */
#include "types.h"
#include "deps/0212ef00_func_0212ef00.h"

void func_0212ef00(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x120U & 3;
  uVar1 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    return;
  }
  *(uint *)(param_1 + 0x120) = uVar2 - 1;
  uVar2 = param_1 + 0x120U & 3;
  uVar1 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    func_0212c9a4();
    return;
  }
  return;
}

