/* Decompiled C draft; module arm9_ov003; ROM address 021c2530. No matching claim. */
#include "types.h"
#include "deps/021c2530_FUN_021c2530.h"

int FUN_021c2530(int *param_1,uint param_2)

{
  return param_1[1] + *(int *)(*param_1 + (param_2 & DAT_021c2540) * 4);
}

