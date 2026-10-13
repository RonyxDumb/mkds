/* Decompiled C draft; module arm9; ROM address 02000354. No matching claim. */
#include "types.h"
#include "deps/02000354_HuffUnCompReadByCallback.h"

void HuffUnCompReadByCallback(void)

{
  software_interrupt(0x13);
  return;
}

