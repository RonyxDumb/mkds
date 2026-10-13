/* Decompiled C draft; module arm9; ROM address 02100b84. No matching claim. */
#include "types.h"
#include "deps/02100b84_func_02100b84.h"

void func_02100b84(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x268U & 3;
  uVar2 = *(uint *)(param_1 + 0x268U & 0xfffffffc);
  *(uint *)(param_1 + 0x268) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
  uVar1 = param_1 + 0x268U & 3;
  uVar2 = *(uint *)(param_1 + 0x268U & 0xfffffffc);
  if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0) {
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x24c) =
         (uint)(((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000000) == 0);
    *(undefined2 *)(param_1 + 0x13c) = 5;
    *(undefined2 *)(param_1 + 0x13e) = 1;
    return;
  }
  return;
}

