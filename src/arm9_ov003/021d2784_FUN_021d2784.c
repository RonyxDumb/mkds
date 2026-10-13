/* Decompiled C draft; module arm9_ov003; ROM address 021d2784. No matching claim. */
#include "types.h"
#include "deps/021d2784_FUN_021d2784.h"

void FUN_021d2784(int param_1,uint param_2)

{
  if (param_1 == 1) {
    *DAT_021d27c8 =
         *DAT_021d27c8 & DAT_021d27d0 | (param_2 | (*DAT_021d27c8 & DAT_021d27cc) >> 8) << 8;
    return;
  }
  *DAT_021d27d4 =
       *DAT_021d27d4 & DAT_021d27d0 | (param_2 | (*DAT_021d27d4 & DAT_021d27cc) >> 8) << 8;
  return;
}

