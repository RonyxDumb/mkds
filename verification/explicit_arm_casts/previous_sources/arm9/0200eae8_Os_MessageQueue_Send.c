/* Decompiled C draft; module arm9; ROM address 0200eae8. No matching claim. */
#include "types.h"
#include "deps/0200eae8_Os_MessageQueue_Send.h"

undefined4 Os_MessageQueue_Send(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int extraout_r1;
  uint uVar3;
  uint uVar4;
  
  uVar2 = Os_DisableIrq();
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) <= (int)uVar4) {
    do {
      if ((param_3 & 1) == 0) {
        Os_RestoreIrq(uVar2);
        return 0;
      }
      Os_Thread_Sleep(param_1);
      uVar1 = param_1 + 0x1cU & 3;
      uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = param_1 + 0x14U & 3;
      uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    } while ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) <= (int)uVar4);
  }
  uVar1 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  _s32_div_f((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar4);
  uVar1 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + extraout_r1 * 4) = param_2;
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  Os_Thread_WakeUp(param_1 + 8);
  Os_RestoreIrq(uVar2);
  return 1;
}

