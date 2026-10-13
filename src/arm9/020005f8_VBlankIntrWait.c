/* Decompiled C draft; module arm9; ROM address 020005f8. No matching claim. */
#include "types.h"
#include "deps/020005f8_VBlankIntrWait.h"

void VBlankIntrWait(void)

{
  software_interrupt(5);
  return;
}

