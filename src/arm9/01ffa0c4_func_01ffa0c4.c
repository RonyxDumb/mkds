/* Decompiled C draft; module arm9; ROM address 01ffa0c4. No matching claim. */
#include "types.h"
#include "deps/01ffa0c4_func_01ffa0c4.h"

void func_01ffa0c4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10) == 0) {
    uVar1 = param_1 + 0x380U & 3;
    uVar2 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
    *(uint *)(param_1 + 0x380) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
    uVar1 = param_1 + 0x380U & 3;
    uVar2 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
    if (5 < (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
      uVar1 = param_1 + 0x44U & 3;
      uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x4000;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x380) = 0;
  *(undefined2 *)(param_1 + 0x234) = 0;
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffffbfff;
  uVar1 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x2ac) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

