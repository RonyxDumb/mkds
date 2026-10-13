/* Decompiled C draft; module arm9; ROM address 02000198. No matching claim. */
#include "types.h"
#include "deps/02000198_Halt.h"

void Halt(void)

{
  software_interrupt(6);
  return;
}

