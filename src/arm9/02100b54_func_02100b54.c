/* Decompiled C draft; module arm9; ROM address 02100b54. No matching claim. */
#include "types.h"
#include "deps/02100b54_func_02100b54.h"

void func_02100b54(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xd0U & 3;
  uVar2 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if ((undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) ==
      (undefined4 *)(param_1 + 0xc4)) {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0xc4);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 200);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0xcc);
    *(undefined4 **)(param_1 + 0xd0) = (undefined4 *)(param_1 + 0x50);
  }
  return;
}

