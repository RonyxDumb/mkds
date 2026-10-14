/* Decompiled C draft; module arm9; ROM address 020f4fd0. No matching claim. */
#include "types.h"
#include "deps/020f4fd0_func_020f4fd0.h"

void func_020f4fd0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  *(uint *)(param_1 + 0x130) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
  uVar1 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0) {
    func_020f7658(param_1,0);
  }
  func_020f68b0(param_1);
  return;
}

