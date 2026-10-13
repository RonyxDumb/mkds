/* Decompiled C draft; module arm9; ROM address 020ff25c. No matching claim. */
#include "types.h"
#include "deps/020ff25c_func_020ff25c.h"

void func_020ff25c(int param_1)

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
  uVar1 = param_1 + 0x13cU & 3;
  uVar2 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    DriverContext_MaybeQueuePlaySfx(param_1,0xda,0x7f,0);
    return;
  }
  return;
}

