/* Decompiled C draft; module arm9; ROM address 0212f5a0. No matching claim. */
#include "types.h"
#include "deps/0212f5a0_func_0212f5a0.h"

void func_0212f5a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  int param_5)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar1 = param_5 + 8U & 3;
  uVar2 = *(uint *)(param_5 + 8U & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
  }
  uVar1 = param_5 + 4U & 3;
  uVar2 = *(uint *)(param_5 + 4U & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))(param_1,param_2,param_3,param_5);
  uVar1 = param_5 + 0x10U & 3;
  uVar2 = *(uint *)(param_5 + 0x10U & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    uVar1 = param_5 + 0x14U & 3;
    uVar2 = *(uint *)(param_5 + 0x14U & 0xfffffffc);
    (*pcVar3)(param_1,param_2,param_3,param_4,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  Arm_FlushRange(param_1,param_3);
  Arm_FlushRange(param_2,param_3);
  return;
}

