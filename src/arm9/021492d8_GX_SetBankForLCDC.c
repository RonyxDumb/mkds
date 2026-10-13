/* Decompiled C draft; module arm9; ROM address 021492d8. No matching claim. */
#include "types.h"
#include "deps/021492d8_GX_SetBankForLCDC.h"

void GX_SetBankForLCDC(ushort param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam021492f4;
  *puRam021492f0 = *puRam021492f0 | param_1;
                    /* WARNING: Could not recover jumptable at 0x021492ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

