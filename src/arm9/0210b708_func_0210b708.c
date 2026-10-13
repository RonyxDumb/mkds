/* Decompiled C draft; module arm9; ROM address 0210b708. No matching claim. */
#include "types.h"
#include "deps/0210b708_func_0210b708.h"

void func_0210b708(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  func_0210bee8(0,*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
                uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2,param_1);
  return;
}

