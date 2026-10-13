/* Decompiled C draft; module arm9; ROM address 020ebab0. No matching claim. */
#include "types.h"
#include "deps/020ebab0_func_020ebab0.h"

void func_020ebab0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = func_020ebc2c();
  bVar6 = iVar2 != 0;
  if (bVar6) {
    iVar2 = 3;
  }
  if (bVar6) {
    *(short *)(param_1 + 0x90) = (short)iVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  uVar1 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 0x1ec;
  uVar1 = param_1 + 0xd0U & 3;
  uVar5 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar3 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0xd0) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  VecFx32_Add(param_1 + 0xb0,param_1 + 0xcc,param_1 + 4);
  return;
}

