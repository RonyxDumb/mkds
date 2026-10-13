/* Decompiled C draft; module arm9; ROM address 02109110. No matching claim. */
#include "types.h"
#include "deps/02109110_StructMQRacerEntry_SomeFn_45.h"

void StructMQRacerEntry_SomeFn_45(int param_1,undefined1 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam02109128;
  *(undefined1 *)(param_1 + 0x3c) = param_2;
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x02109124. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_3);
  return;
}

