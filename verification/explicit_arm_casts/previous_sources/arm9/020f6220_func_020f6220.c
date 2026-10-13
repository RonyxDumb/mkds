/* Decompiled C draft; module arm9; ROM address 020f6220. No matching claim. */
#include "types.h"
#include "deps/020f6220_func_020f6220.h"

void func_020f6220(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400000) != 0) {
    uVar1 = param_1 + 0xd4U & 3;
    uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210b7ec(param_1 + 0x16c,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x3fffffe0);
    func_02109078(param_1,0xd7,0x7f,0);
    return;
  }
  return;
}

