/* Decompiled C draft; module arm9; ROM address 0210f07c. No matching claim. */
#include "types.h"
#include "deps/0210f07c_Struct59C4Sub_SomeFn_2.h"

void Struct59C4Sub_SomeFn_2(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0210f08c;
  *(undefined4 *)(param_1 + 0x41c) = 1;
                    /* WARNING: Could not recover jumptable at 0x0210f088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

