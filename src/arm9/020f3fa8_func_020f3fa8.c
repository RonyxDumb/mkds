/* Decompiled C draft; module arm9; ROM address 020f3fa8. No matching claim. */
#include "types.h"
#include "deps/020f3fa8_func_020f3fa8.h"

void func_020f3fa8(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_1 + 0x60U & 3;
  uVar4 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  iVar2 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * 0xc + param_1;
  uVar3 = param_2[1];
  uVar5 = param_2[2];
  *(undefined4 *)(iVar2 + 0x74) = *param_2;
  *(undefined4 *)(iVar2 + 0x78) = uVar3;
  *(undefined4 *)(iVar2 + 0x7c) = uVar5;
  uVar1 = param_1 + 0x60U & 3;
  uVar4 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(uint *)(param_1 + 0x60) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 1;
  uVar1 = param_1 + 0x60U & 3;
  uVar4 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(uint *)(param_1 + 0x60) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 3;
  uVar1 = param_1 + 100U & 3;
  uVar7 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar4 = param_1 + 0x68U & 3;
  uVar6 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
  *(uint *)(param_1 + 100) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x6cU & 3;
  uVar6 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  *(uint *)(param_1 + 0x68) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x70U & 3;
  uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  *(uint *)(param_1 + 0x6c) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  *(uint *)(param_1 + 0x70) = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  func_020d7c84(param_1,1,(undefined4 *)(uintptr_t)(param_1 + 100));
  return;
}

