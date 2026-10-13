/* Decompiled C draft; module arm9_ov003; ROM address 021d272c. No matching claim. */
#include "types.h"
#include "deps/021d272c_FUN_021d272c.h"

void FUN_021d272c(int param_1,uint param_2)

{
  if (param_1 == 1) {
    *DAT_021d2774 =
         *DAT_021d2774 & DAT_021d277c | (~param_2 & (*DAT_021d2774 & DAT_021d2778) >> 8) << 8;
    return;
  }
  *DAT_021d2780 =
       *DAT_021d2780 & DAT_021d277c | (~param_2 & (*DAT_021d2780 & DAT_021d2778) >> 8) << 8;
  return;
}

