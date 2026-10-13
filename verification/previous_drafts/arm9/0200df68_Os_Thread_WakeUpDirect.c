/* Decompiled C draft; module arm9; ROM address 0200df68. No matching claim. */
#include "types.h"
#include "deps/0200df68_Os_Thread_WakeUpDirect.h"

void Os_Thread_WakeUpDirect(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = Os_DisableIrq();
  *(undefined4 *)(param_1 + 100) = 1;
  Os_RescheduleThread();
  Os_RestoreIrq(uVar1);
  return;
}

