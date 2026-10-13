/* Decompiled C draft; module arm9; ROM address 0200f3e0. No matching claim. */
#include "types.h"
#include "deps/0200f3e0_OSi_GetAndDisplayContext.h"

void OSi_GetAndDisplayContext(void)

{
  Os_SaveExceptionContext();
  OSi_DisplayExContext();
  return;
}

