/* Decompiled C draft; module arm9; ROM address 0200c690. No matching claim. */
#include "types.h"
#include "deps/0200c690_Fifo13Handler_0_from_thumb.h"

void Fifo13Handler_0_from_thumb(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x3f) == 1) {
    *puRam0200c6b4 = 1;
    return;
  }
  Os_Terminate();
  return;
}

