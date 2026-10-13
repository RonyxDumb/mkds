/* Decompiled C draft; module arm9; ROM address 02134508. No matching claim. */
#include "types.h"
#include "deps/02134508_func_02134508.h"

void func_02134508(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x18U & 3;
  uVar5 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = param_1 + 0x2cU & 3;
  uVar4 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar2 = param_1 + 0x28U & 3;
  uVar6 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) -
       ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) &
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20));
  uVar1 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x34) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  return;
}

