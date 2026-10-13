/* Decompiled C draft; module arm9; ROM address 0200fd04. No matching claim. */
#include "types.h"
#include "deps/0200fd04_Os_Halt.h"

undefined4 Os_Halt(void)

{
  coproc_moveto_Wait_for_interrupt(0);
  return 0;
}

