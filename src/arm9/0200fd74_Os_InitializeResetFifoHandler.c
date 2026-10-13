/* Decompiled C draft; module arm9; ROM address 0200fd74. No matching claim. */
#include "types.h"
#include "deps/0200fd74_Os_InitializeResetFifoHandler.h"

void Os_InitializeResetFifoHandler(void)

{
  int iVar1;
  
  if (*psRam0200fdd4 == 0) {
    *psRam0200fdd4 = 1;
    func_0214d5b8();
    do {
      iVar1 = Fifo_IsHandlerReady(0xc,1);
    } while (iVar1 == 0);
    Fifo_RegisterHandler(0xc,uRam0200fdd8);
    return;
  }
  return;
}

