/* Decompiled C draft; module arm9; ROM address 0200e0ec. No matching claim. */
#include "types.h"
#include "deps/0200e0ec_func_0200e0ec.h"

void func_0200e0ec(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = Os_DisableIrq();
  uVar1 = iRam0200e15c + 4U & 3;
  uVar3 = *(uint *)(iRam0200e15c + 4U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == param_1) {
    Os_DisposeCurrentThreadImpl();
  }
  Os_DisableScheduler();
  Os_UnlockAllMutexes(param_1);
  Os_Thread_CancelAlarmForSleep(param_1);
  Os_PopThread(param_1);
  *(undefined4 *)(param_1 + 100) = 2;
  Os_Thread_WakeUp((uint *)(uintptr_t)(param_1 + 0x9c));
  Os_EnableScheduler();
  Os_RestoreIrq(uVar2);
  Os_RescheduleThread();
  return;
}

