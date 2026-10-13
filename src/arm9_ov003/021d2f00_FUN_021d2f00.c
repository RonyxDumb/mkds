/* Decompiled C draft; module arm9_ov003; ROM address 021d2f00. No matching claim. */
#include "types.h"
#include "deps/021d2f00_FUN_021d2f00.h"

void FUN_021d2f00(uint *param_1)

{
  *param_1 = *param_1 & DAT_021d2f2c | DAT_021d2f30;
                    /* WARNING: Could not recover jumptable at 0x021d2f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_021d2f40)(*(undefined4 *)
                   (*DAT_021d2f34 + (uint)((uint *)(*DAT_021d2f34 + DAT_021d2f38) <= param_1) * 4 +
                   DAT_021d2f3c));
  return;
}

