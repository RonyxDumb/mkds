/* Decompiled C draft; module arm9; ROM address 0200020e. No matching claim. */
#include "types.h"
#include "deps/0200020e_SoftReset.h"

void SoftReset(void)

{
  software_interrupt(0);
  return;
}

