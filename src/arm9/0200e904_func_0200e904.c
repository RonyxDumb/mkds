/* Decompiled C draft; module arm9; ROM address 0200e904. No matching claim. */
#include "types.h"
#include "deps/0200e904_func_0200e904.h"

undefined4 func_0200e904(int param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
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
  Os_RestoreIrq(uVar1);
  return 1;
}

