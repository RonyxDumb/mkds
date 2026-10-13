/* Decompiled C draft; module arm9; ROM address 020e6a18. No matching claim. */
#include "types.h"
#include "deps/020e6a18_func_020e6a18.h"

void func_020e6a18(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x1a) == 1) {
    uVar1 = param_1 + 0x20U & 3;
    uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    func_01ff9048(0x2b,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,1);
    uVar1 = param_1 + 0x1cU & 3;
    uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    func_01ff9048(0x2a,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,1);
  }
  func_01ff9048(0x30,param_1 + 0xc,1);
  func_01ff9048(0x31,param_1 + 0x10,1);
  return;
}

