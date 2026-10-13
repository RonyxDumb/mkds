/* Decompiled C draft; module arm9; ROM address 02000664. No matching claim. */
#include "types.h"
#include "deps/02000664_WaitByLoop.h"

void WaitByLoop(void)

{
  software_interrupt(3);
  return;
}

