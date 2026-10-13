/* Decompiled C draft; module arm9; ROM address 0209b904. No matching claim. */
#include "types.h"
#include "deps/0209b904_func_0209b904.h"

void func_0209b904(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x10U & 3;
  uVar1 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    uVar2 = uVar2 + 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    ModelBlock_SomeTexPltFn_3(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_3,param_2);
    return;
  }
  return;
}

