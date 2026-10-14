/* Decompiled C draft; module arm9; ROM address 0200fc1c. No matching claim. */
#include "types.h"
#include "deps/0200fc1c_Os_InitializeVAlarm.h"

void Os_InitializeVAlarm(void)

{
  undefined4 *puVar1;
  
  puVar1 = puRam0200fc80;
  if (*psRam0200fc7c == 0) {
    *psRam0200fc7c = 1;
    *puVar1 = 0;
    puVar1[1] = 0;
    Os_DisableIrqHandler(4);
    puVar1 = puRam0200fc88;
    *puRam0200fc84 = 0;
    *puVar1 = 0;
    return;
  }
  return;
}

