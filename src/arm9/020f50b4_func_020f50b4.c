/* Decompiled C draft; module arm9; ROM address 020f50b4. No matching claim. */
#include "types.h"
#include "deps/020f50b4_func_020f50b4.h"

void func_020f50b4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_020f8e78();
  func_020f2d98(param_1,0);
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000000) == 0) {
    return;
  }
  uVar1 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    DriverContext_MaybeQueuePlaySfx(param_1,0xda,0x7f,0);
    return;
  }
  return;
}

