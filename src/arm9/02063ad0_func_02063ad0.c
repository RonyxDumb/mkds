/* Decompiled C draft; module arm9; ROM address 02063ad0. No matching claim. */
#include "types.h"
#include "deps/02063ad0_func_02063ad0.h"

void func_02063ad0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400) == 0) {
    uVar1 = param_1 + 0x224U & 3;
    uVar2 = *(uint *)(param_1 + 0x224U & 0xfffffffc);
    (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
    uVar1 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x200) != 0) {
      uVar1 = param_1 + 0x514U & 3;
      uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar1 = uVar3 + 0x2c;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      *(uint *)(uVar3 + 0x2c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) ^ 0x10000;
    }
    return;
  }
  return;
}

