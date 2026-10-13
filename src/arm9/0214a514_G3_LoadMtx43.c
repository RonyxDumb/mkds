/* Decompiled C draft; module arm9; ROM address 0214a514. No matching claim. */
#include "types.h"
#include "deps/0214a514_G3_LoadMtx43.h"

void G3_LoadMtx43(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0214a52c;
  *puRam0214a528 = 0x17;
                    /* WARNING: Could not recover jumptable at 0x0214a524. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

