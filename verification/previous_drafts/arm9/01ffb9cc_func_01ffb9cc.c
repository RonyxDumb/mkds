/* Decompiled C draft; module arm9; ROM address 01ffb9cc. No matching claim. */
#include "types.h"
#include "deps/01ffb9cc_func_01ffb9cc.h"

void func_01ffb9cc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x260U & 3;
  uVar4 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  uVar2 = param_1 + 200U & 3;
  uVar3 = *(uint *)(param_1 + 200U & 0xfffffffc);
  *(uint *)(param_1 + 0x260) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  return;
}

