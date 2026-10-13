/* Decompiled C draft; module arm9; ROM address 020e1dec. No matching claim. */
#include "types.h"
#include "deps/020e1dec_func_020e1dec.h"

void func_020e1dec(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(int *)(param_1 + 0x4c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(int *)(param_1 + 0x50) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(int *)(param_1 + 0x54) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  func_020ea8a8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_1 + 0x28,param_1 + 0x1c,
                param_3);
  return;
}

