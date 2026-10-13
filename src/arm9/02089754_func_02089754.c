/* Decompiled C draft; module arm9; ROM address 02089754. No matching claim. */
#include "types.h"
#include "deps/02089754_func_02089754.h"

void func_02089754(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar3;
  
  func_020808d4(param_1 + 0x28);
  uVar2 = param_1 + 0x28U & 3;
  uVar1 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar4 = puVar3[1];
  uVar5 = puVar3[2];
  *(undefined4 *)(param_1 + 0x44) = *puVar3;
  *(undefined4 *)(param_1 + 0x48) = uVar4;
  *(undefined4 *)(param_1 + 0x4c) = uVar5;
  func_020898bc(param_1);
  return;
}

