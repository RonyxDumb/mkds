/* Decompiled C draft; module arm9_ov003; ROM address 021bdbd0. No matching claim. */
#include "types.h"
#include "deps/021bdbd0_FUN_021bdbd0.h"

void FUN_021bdbd0(ushort *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort *local_18 [2];
  
  local_18[0] = param_1 + 4;
  FUN_021bdc08(local_18,(int)local_18[0] +
                        ((int)(uint)*param_1 >> 8 | (uint)*param_1 << 8 & DAT_021bdc04 & 0xffff),
               param_2,param_3);
  return;
}

