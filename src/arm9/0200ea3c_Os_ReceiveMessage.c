/* Decompiled C draft; module arm9; ROM address 0200ea3c. No matching claim. */
#include "types.h"
#include "deps/0200ea3c_Os_ReceiveMessage.h"

undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 extraout_r1;
  
  uVar1 = Os_DisableIrq();
  uVar3 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    do {
      if ((param_3 & 1) == 0) {
        Os_RestoreIrq(uVar1);
        return 0;
      }
      Os_Thread_Sleep(param_1 + 8);
      uVar3 = param_1 + 0x1cU & 3;
      uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    } while (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0);
  }
  if (param_2 != (uint *)0x0) {
    uVar3 = param_1 + 0x10U & 3;
    uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar4 = param_1 + 0x18U & 3;
    uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
            (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 4;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *param_2 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  uVar3 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar4 = param_1 + 0x14U & 3;
  uVar5 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  _s32_div_f((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1,
             uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x18) = extraout_r1;
  uVar3 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - 1;
  Os_Thread_WakeUp((uint *)(uintptr_t)(param_1));
  Os_RestoreIrq(uVar1);
  return 1;
}

