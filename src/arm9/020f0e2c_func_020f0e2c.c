/* Decompiled C draft; module arm9; ROM address 020f0e2c. No matching claim. */
#include "types.h"
#include "deps/020f0e2c_func_020f0e2c.h"

void func_020f0e2c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar4;
  
  uVar6 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar5 = 0;
  uVar6 = uVar4;
  if (0 < (int)uVar4) {
    do {
      uVar6 = uVar3 + uVar5 * 4;
      uVar1 = uVar6 & 3;
      uVar2 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar5;
      if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == param_2) break;
      uVar5 = uVar5 + 1;
      uVar6 = uVar4;
    } while ((int)uVar5 < (int)uVar4);
  }
  uVar4 = param_1 + 0x18U & 3;
  uVar5 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((int)uVar6 < (int)uVar4) {
    return;
  }
  uVar4 = uVar3 + uVar4 * 4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar3 + uVar6 * 4) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar6 = param_1 + 0x18U & 3;
  uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(uVar3 + (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) * 4) = param_2;
  uVar6 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 1;
  return;
}

