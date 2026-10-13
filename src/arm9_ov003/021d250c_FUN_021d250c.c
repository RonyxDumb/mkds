/* Decompiled C draft; module arm9_ov003; ROM address 021d250c. No matching claim. */
#include "types.h"
#include "deps/021d250c_FUN_021d250c.h"

void FUN_021d250c(short *param_1,short *param_2,short *param_3)

{
  *param_3 = *param_1;
  param_3[1] = param_1[1];
  param_3[2] = *param_1 + *param_2;
  param_3[3] = param_1[1] + param_2[1];
  return;
}

