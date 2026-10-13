/* Decompiled C draft; module arm9; ROM address 020de214. No matching claim. */
#include "types.h"
#include "deps/020de214_func_020de214.h"

void func_020de214(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_18 [12];
  uint uVar6;
  
  uVar1 = param_2 + 0xf4U & 3;
  uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  uVar6 = param_2 + 0xa0U & 3;
  uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar3 = *(undefined4 *)(uVar6 + 8);
    uVar4 = *(undefined4 *)(uVar6 + 0xc);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(uVar6 + 4);
    *(undefined4 *)(param_2 + 8) = uVar3;
    *(undefined4 *)(param_2 + 0xc) = uVar4;
  }
  uVar1 = uVar6 + 0xf0 & 3;
  uVar2 = *(uint *)(uVar6 + 0xf0 & 0xfffffffc);
  VecFx32_AddScale1(-(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20),uVar6 + 0x40,uVar6 + 4,
                    (int *)(void *)(auStack_18));
  func_020ddb44(param_2 + 0xa4,auStack_18,uVar6 + 0x10);
  return;
}

