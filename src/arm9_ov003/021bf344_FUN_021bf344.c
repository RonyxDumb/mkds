/* Decompiled C draft; module arm9_ov003; ROM address 021bf344. No matching claim. */
#include "types.h"
#include "deps/021bf344_FUN_021bf344.h"

void FUN_021bf344(void)

{
  int *piVar1;
  
  piVar1 = DAT_021bf358;
  *(undefined1 *)(*DAT_021bf358 + 0x19) = 1;
                    /* WARNING: Could not recover jumptable at 0x021bf354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_021bf360)(*(undefined4 *)(*piVar1 + 0xc),DAT_021bf35c);
  return;
}

