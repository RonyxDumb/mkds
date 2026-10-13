/* Decompiled C draft; module arm9; ROM address 02067a2c. No matching claim. */
#include "types.h"
#include "deps/02067a2c_func_02067a2c.h"

undefined4 func_02067a2c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_0207a6c0();
  uVar1 = param_1 + 0x3e4U & 3;
  uVar2 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
  uVar1 = iRam02067a60 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  func_02083f6c((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffff,param_1);
  return 2;
}

