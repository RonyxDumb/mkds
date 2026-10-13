/* Decompiled C draft; module arm9; ROM address 02146b80. No matching claim. */
#include "types.h"
#include "deps/02146b80_Card_InitializePulledOutCallback.h"

void Card_InitializePulledOutCallback(void)

{
  func_0214d5b8();
  Fifo_RegisterHandler(0xe,uRam02146bb0);
  *puRam02146bb4 = 0;
  return;
}

