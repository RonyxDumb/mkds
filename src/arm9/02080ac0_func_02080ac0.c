/* Decompiled C draft; module arm9; ROM address 02080ac0. No matching claim. */
#include "types.h"
#include "deps/02080ac0_func_02080ac0.h"

void func_02080ac0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 4U & 3;
    uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
    *(uint *)(param_1 + 0x14) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}

