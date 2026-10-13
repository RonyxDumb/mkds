/* Decompiled C draft; module arm9; ROM address 020f0f70. No matching claim. */
#include "types.h"
#include "deps/020f0f70_func_020f0f70.h"

void func_020f0f70(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 4U & 3;
  uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar3 = 0;
  uVar4 = uVar6;
  if (0 < (int)uVar6) {
    do {
      uVar4 = uVar5 + uVar3 * 4;
      uVar2 = uVar4 & 3;
      uVar1 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar3;
      if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == param_2) break;
      uVar3 = uVar3 + 1;
      uVar4 = uVar6;
    } while ((int)uVar3 < (int)uVar6);
  }
  uVar3 = param_1 + 0x18U & 3;
  uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  if ((int)uVar4 < (int)uVar3) {
    *(uint *)(param_1 + 0x18) = uVar3 - 1;
    uVar3 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    while ((int)uVar4 < (int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20)) {
      uVar2 = uVar5 + (uVar4 + 1) * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar5 + uVar4 * 4) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar4 = uVar4 + 1;
    }
  }
  uVar3 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  if ((int)uVar4 < (int)uVar3) {
    *(uint *)(param_1 + 0x14) = uVar3 - 1;
    uVar3 = param_1 + 0x14U & 3;
    uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar3 = uVar5 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * 4;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar5 + uVar4 * 4) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar4 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  if ((int)uVar4 < (int)uVar3) {
    *(uint *)(param_1 + 0x10) = uVar3 - 1;
    uVar3 = param_1 + 0x10U & 3;
    uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar3 = uVar5 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * 4;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar5 + uVar4 * 4) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar4 = param_1 + 0x10U & 3;
    uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  *(uint *)(uVar5 + uVar4 * 4) = param_2;
  func_020f992c(param_2);
  uVar4 = param_1 + 0x1cU & 3;
  uVar5 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) - 1;
  return;
}

