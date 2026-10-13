/* Decompiled C draft; module arm9; ROM address 020f6388. No matching claim. */
#include "types.h"
#include "deps/020f6388_func_020f6388.h"

void func_020f6388(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  func_020f92e8(param_1 + 0x5c,param_3);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 & 0x1000000) == 0) {
    *(uint *)(param_1 + 0x74) = uVar2 | 0x1000000;
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(undefined4 *)(param_1 + 0x110) = 0;
    return;
  }
  return;
}

