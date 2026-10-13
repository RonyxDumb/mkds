/* Decompiled C draft; module arm9; ROM address 02000130. No matching claim. */
#include "types.h"
#include "deps/02000130_IntrWait.h"

void IntrWait(void)

{
  software_interrupt(4);
  return;
}

