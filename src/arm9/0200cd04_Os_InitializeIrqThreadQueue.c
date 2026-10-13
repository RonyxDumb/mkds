/* Decompiled C draft; module arm9; ROM address 0200cd04. No matching claim. */
#include "types.h"
#include "deps/0200cd04_Os_InitializeIrqThreadQueue.h"

void Os_InitializeIrqThreadQueue(void)

{
  undefined4 *puVar1;
  
  puVar1 = puRam0200cd18;
  puRam0200cd18[1] = 0;
  *puVar1 = 0;
  return;
}

