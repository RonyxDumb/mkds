/* Decompiled C draft; module arm9; ROM address 0200eec0. No matching claim. */
#include "types.h"
#include "deps/0200eec0_Os_Initialize.h"

void Os_Initialize(void)

{
  Os_InitializeMemoryRegionAddresses();
  func_0214d5b8();
  Os_InitializeLock();
  Os_InitializeMainExMemoryRegionAddress();
  Os_InitializeIrqThreadQueue();
  Os_InitializeSvcStack();
  Os_InitializeExceptionHandler();
  Mem_Initialize();
  Os_InitializeVAlarm();
  OSi_InitVramExclusive();
  Os_InitializeThread();
  Os_InitializeResetFifoHandler();
  CTRDG_Initialize_from_thumb();
  Card_Initialize();
  PM_Initialize();
  return;
}

