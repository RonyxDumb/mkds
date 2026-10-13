/* Decompiled C draft; module arm9; ROM address 02020f84. No matching claim. */
#include "types.h"
#include "deps/02020f84_Sound_RegisterFifoHandler.h"

void Sound_RegisterFifoHandler(void)

{
  int iVar1;
  
  Fifo_RegisterHandler(7,uRam02020fec);
  iVar1 = Sound_IsCommandAvailable();
  if (iVar1 == 0) {
    return;
  }
  iVar1 = Fifo_IsHandlerReady(7,1);
  if (iVar1 != 0) {
    return;
  }
  do {
    Os_SpinWait(100);
    iVar1 = Fifo_IsHandlerReady(7,1);
  } while (iVar1 == 0);
  return;
}

