/* Decompiled C draft; module arm9; ROM address 0210f068. No matching claim. */
#include "types.h"
#include "deps/0210f068_Struct59C4Sub_SomeFn_3.h"

void Struct59C4Sub_SomeFn_3(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0210f078;
  *(undefined4 *)(param_1 + 0x41c) = 2;
                    /* WARNING: Could not recover jumptable at 0x0210f074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

