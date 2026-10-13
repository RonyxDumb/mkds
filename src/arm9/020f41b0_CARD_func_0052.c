/* Decompiled C draft; module arm9; ROM address 020f41b0. No matching claim. */
#include "types.h"
#include "deps/020f41b0_CARD_func_0052.h"

void CARD_func_0052(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam020f41c0;
  *(undefined4 *)(param_1 + 0x20) = 10;
                    /* WARNING: Could not recover jumptable at 0x020f41bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

