/* Decompiled C draft; module arm9; ROM address 02016554. No matching claim. */
#include "types.h"
#include "deps/02016554_InitializeGlobalTEQ.h"

void InitializeGlobalTEQ(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam02016570;
  puVar1 = puRam0201656c;
  *puRam0201656c = param_1;
  puVar1[1] = param_2;
                    /* WARNING: Could not recover jumptable at 0x02016568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(puVar1);
  return;
}

