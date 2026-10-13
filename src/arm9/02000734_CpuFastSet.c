/* Decompiled C draft; module arm9; ROM address 02000734. No matching claim. */
#include "types.h"
#include "deps/02000734_CpuFastSet.h"

void CpuFastSet(void)

{
  software_interrupt(0xc);
  return;
}

