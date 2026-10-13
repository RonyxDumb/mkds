/* Decompiled C draft; module arm9; ROM address 0200fb28. No matching claim. */
#include "types.h"
#include "deps/0200fb28_Os_InitializeAlarm.h"

void Os_InitializeAlarm(void)

{
  undefined4 *puVar1;
  
  if (*psRam0200fb78 == 0) {
    *psRam0200fb78 = 1;
    Os_ReserveTimer();
    puVar1 = puRam0200fb7c;
    *puRam0200fb7c = 0;
    puVar1[1] = 0;
    Os_DisableIrqHandler(0x10);
    return;
  }
  return;
}

