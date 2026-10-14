/* Decompiled C draft; module arm9; ROM address 020f5008. No matching claim. */
#include "types.h"
#include "deps/020f5008_func_020f5008.h"

void func_020f5008(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x134U & 3;
  uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020ed5c0(param_1,param_3,(undefined4 *)(uintptr_t)(param_2));
    return;
  }
  return;
}

