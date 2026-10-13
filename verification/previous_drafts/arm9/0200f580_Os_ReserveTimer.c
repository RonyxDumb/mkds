/* Decompiled C draft; module arm9; ROM address 0200f580. No matching claim. */
#include "types.h"
#include "deps/0200f580_Os_ReserveTimer.h"

void Os_ReserveTimer(uint param_1)

{
  *puRam0200f598 = *puRam0200f598 | (ushort)(1 << (param_1 & 0xff));
  return;
}

