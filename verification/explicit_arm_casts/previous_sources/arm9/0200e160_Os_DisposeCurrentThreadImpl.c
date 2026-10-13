/* Decompiled C draft; module arm9; ROM address 0200e160. No matching claim. */
#include "types.h"
#include "deps/0200e160_Os_DisposeCurrentThreadImpl.h"

void Os_DisposeCurrentThreadImpl(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(uRam0200e1a8 & 0xfffffffc) >> (uRam0200e1a8 & 3) * 8 |
          *(uint *)(uRam0200e1a8 & 0xfffffffc) << (uRam0200e1a8 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  Os_DisableScheduler();
  Os_UnlockAllMutexes(uVar2);
  Os_PopThread(uVar2);
  *(undefined4 *)(uVar2 + 100) = 2;
  Os_Thread_WakeUp(uVar2 + 0x9c);
  Os_EnableScheduler();
  Os_RescheduleThread();
  Os_Terminate();
  return;
}

