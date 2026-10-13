/* Decompiled C draft; module arm9; ROM address 020fcb4c. No matching claim. */
#include "types.h"
#include "deps/020fcb4c_func_020fcb4c.h"

void func_020fcb4c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  func_020f4198(param_2,uRam020fcb98);
  uVar2 = param_2 + 4U & 3;
  uVar1 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1fc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  DriverContext_ApplyShroomBoost(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(undefined4 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x204) = 1;
  func_020f4188(param_2,0xc);
  return;
}

