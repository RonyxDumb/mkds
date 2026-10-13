/* Decompiled C draft; module arm9; ROM address 02000272. No matching claim. */
#include "types.h"
#include "deps/02000272_RLUnCompReadByCallbackWrite16bit.h"

void RLUnCompReadByCallbackWrite16bit(void)

{
  software_interrupt(0x15);
  return;
}

