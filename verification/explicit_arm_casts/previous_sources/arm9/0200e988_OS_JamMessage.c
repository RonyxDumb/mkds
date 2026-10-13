/* Decompiled C draft; module arm9; ROM address 0200e988. No matching claim. */
#include "types.h"
#include "deps/0200e988_OS_JamMessage.h"

undefined4 OS_JamMessage(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 extraout_r1;
  uint uVar4;
  uint uVar5;
  
  uVar2 = Os_DisableIrq();
  uVar1 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if ((int)uVar3 <= (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
    do {
      if ((param_3 & 1) == 0) {
        Os_RestoreIrq(uVar2);
        return 0;
      }
      Os_Thread_Sleep(param_1);
      uVar1 = param_1 + 0x14U & 3;
      uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = param_1 + 0x1cU & 3;
      uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    } while ((int)uVar3 <= (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20));
  }
  uVar1 = param_1 + 0x18U & 3;
  uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  _s32_div_f((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + uVar3 + -1);
  *(undefined4 *)(param_1 + 0x18) = extraout_r1;
  uVar1 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = param_1 + 0x18U & 3;
  uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(undefined4 *)
   ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
   (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * 4) = param_2;
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  Os_Thread_WakeUp(param_1 + 8);
  Os_RestoreIrq(uVar2);
  return 1;
}

