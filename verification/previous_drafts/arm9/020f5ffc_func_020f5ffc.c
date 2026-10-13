/* Decompiled C draft; module arm9; ROM address 020f5ffc. No matching claim. */
#include "types.h"
#include "deps/020f5ffc_func_020f5ffc.h"

void func_020f5ffc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_020f8e78();
  func_0210b850((undefined4 *)(uintptr_t)(param_1 + 0x16c));
  *(undefined4 *)(param_1 + 0x30) = uRam020f6034;
  uVar1 = param_1 + 0x168U & 3;
  uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  func_020f1ea4(param_1,9,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  return;
}

