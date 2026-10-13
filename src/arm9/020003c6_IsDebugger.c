/* Decompiled C draft; module arm9; ROM address 020003c6. No matching claim. */
#include "types.h"
#include "deps/020003c6_IsDebugger.h"

void IsDebugger(void)

{
  software_interrupt(0xf);
  return;
}

