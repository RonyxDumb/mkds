/* Decompiled C draft; module arm9; ROM address 0214a530. No matching claim. */
#include "types.h"
#include "deps/0214a530_G3_LoadMtx44.h"

void G3_LoadMtx44(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0214a548;
  *puRam0214a544 = 0x16;
                    /* WARNING: Could not recover jumptable at 0x0214a540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

