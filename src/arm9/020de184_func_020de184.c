/* Decompiled C draft; module arm9; ROM address 020de184. No matching claim. */
#include "types.h"
#include "deps/020de184_func_020de184.h"

void func_020de184(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_28;
  int local_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [16];
  uint uVar3;
  
  uVar1 = param_1 + 0xa0U & 3;
  uVar2 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 + 0xf0 & 3;
  uVar2 = *(uint *)(uVar3 + 0xf0 & 0xfffffffc);
  VecFx32_AddScale1(-(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20),uVar3 + 0x40,uVar3 + 4,
                    (int *)(void *)(auStack_1c));
  local_28 = *(undefined4 *)(uVar3 + 0xa0);
  uStack_20 = *(undefined4 *)(uVar3 + 0xa8);
  uVar1 = uVar3 + 0xf0 & 3;
  uVar2 = *(uint *)(uVar3 + 0xf0 & 0xfffffffc);
  local_24 = *(int *)(uVar3 + 0xa4) - ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 1);
  func_020dd8b0(param_1 + 0xa4,&local_28,(undefined4)(uintptr_t)(auStack_1c));
  uVar1 = param_1 + 0xf4U & 3;
  uVar2 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_020dda2c(param_1 + 0xa4);
    return;
  }
  return;
}

