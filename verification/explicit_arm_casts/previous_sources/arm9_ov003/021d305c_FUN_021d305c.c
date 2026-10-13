/* Decompiled C draft; module arm9_ov003; ROM address 021d305c. No matching claim. */
#include "types.h"
#include "deps/021d305c_FUN_021d305c.h"

void FUN_021d305c(uint param_1)

{
  FUN_021d2e90();
  FUN_021d1d0c(*(undefined4 *)
                (*DAT_021d3090 +
                 DAT_021d3094 * (uint)((uint)(*DAT_021d3090 + DAT_021d3094) <= param_1) +
                DAT_021d3098),param_1);
  return;
}

