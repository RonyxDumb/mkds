/* Decompiled C draft; module arm9; ROM address 0200e01c. No matching claim. */
#include "types.h"
#include "deps/0200e01c_Os_Thread_Sleep.h"

void Os_Thread_Sleep(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = Os_DisableIrq();
  uVar2 = *(uint *)(uRam0200e06c & 0xfffffffc) >> (uRam0200e06c & 3) * 8 |
          *(uint *)(uRam0200e06c & 0xfffffffc) << (uRam0200e06c & 3) * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (param_1 != 0) {
    *(int *)(uVar3 + 0x78) = param_1;
    Os_ThreadQueue_Queue(param_1,uVar3);
  }
  *(undefined4 *)(uVar3 + 100) = 0;
  Os_RescheduleThread();
  Os_RestoreIrq(uVar1);
  return;
}

