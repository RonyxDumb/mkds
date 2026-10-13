/* Decompiled C draft; module arm9; ROM address 0200dce0. No matching claim. */
#include "types.h"
#include "deps/0200dce0_Os_Thread_SetPriority.h"

undefined4 Os_Thread_SetPriority(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = iRam0200dd8c + 8U & 3;
  uVar4 = *(uint *)(iRam0200dd8c + 8U & 0xfffffffc);
  uVar1 = Os_DisableIrq();
  uVar3 = 0;
  uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  while ((uVar2 != 0 && (uVar2 != param_1))) {
    uVar4 = uVar2 + 0x68 & 3;
    uVar5 = *(uint *)(uVar2 + 0x68 & 0xfffffffc);
    uVar3 = uVar2;
    uVar2 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  }
  if ((uVar2 != 0) && (uVar2 != uRam0200dd90)) {
    uVar4 = uVar2 + 0x70 & 3;
    uVar2 = *(uint *)(uVar2 + 0x70 & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) != param_2) {
      if (uVar3 == 0) {
        uVar2 = param_1 + 0x68 & 3;
        uVar3 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
        *(uint *)(iRam0200dd8c + 8) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      }
      else {
        uVar2 = param_1 + 0x68 & 3;
        uVar4 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
        *(uint *)(uVar3 + 0x68) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      }
      *(uint *)(param_1 + 0x70) = param_2;
      Os_InsertThread(param_1);
      Os_RescheduleThread();
    }
    Os_RestoreIrq(uVar1);
    return 1;
  }
  Os_RestoreIrq(uVar1);
  return 0;
}

