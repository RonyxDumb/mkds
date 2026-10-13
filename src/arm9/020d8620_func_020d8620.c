/* Decompiled C draft; module arm9; ROM address 020d8620. No matching claim. */
#include "types.h"
#include "deps/020d8620_func_020d8620.h"

void func_020d8620(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar3 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(param_1 + 0x20) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uint)(uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0);
  return;
}

