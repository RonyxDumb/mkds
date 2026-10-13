/* Decompiled C draft; module arm9_ov003; ROM address 021c250c. No matching claim. */
#include "types.h"
#include "deps/021c250c_FUN_021c250c.h"

void FUN_021c250c(int *param_1,uint param_2,int param_3,short param_4)

{
  if (-1 < param_3) {
    *(short *)(param_1[1] + *(int *)(*param_1 + (param_2 & DAT_021c252c) * 4) + param_3 * 2) =
         param_4 + 0x30;
  }
  return;
}

