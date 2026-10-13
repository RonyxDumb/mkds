/* Decompiled C draft; module arm9; ROM address 0200e0c0. No matching claim. */
#include "types.h"
#include "deps/0200e0c0_Os_Thread_CancelAlarmForSleep.h"

void Os_Thread_CancelAlarmForSleep(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xb0U & 3;
  uVar2 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    Os_Alarm_Cancel();
    return;
  }
  return;
}

