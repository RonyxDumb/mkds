/* Decompiled C draft; module arm9; ROM address 0214a4f8. No matching claim. */
#include "types.h"
#include "deps/0214a4f8_G3_MultMtx43.h"

void G3_MultMtx43(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0214a510;
  *puRam0214a50c = 0x19;
                    /* WARNING: Could not recover jumptable at 0x0214a508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

