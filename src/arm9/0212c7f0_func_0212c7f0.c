/* Decompiled C draft; module arm9; ROM address 0212c7f0. No matching claim. */
#include "types.h"
#include "deps/0212c7f0_func_0212c7f0.h"

void func_0212c7f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  func_0212bb7c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(uRam0212c820),param_1);
  uVar1 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe;
  return;
}

