/* Decompiled C draft; module arm9; ROM address 01ff8c98. No matching claim. */
#include "types.h"
#include "deps/01ff8c98_func_01ff8c98.h"

void func_01ff8c98(int param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar1 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
  }
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x20;
  return;
}

