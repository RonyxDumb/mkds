/* Decompiled C draft; module arm9_ov000; ROM address 02189868. No matching claim. */
#include "types.h"
#include "deps/02189868_FUN_02189868.h"

void FUN_02189868(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  if (0xc < param_3) {
    param_3 = 0xc;
  }
  FUN_021a61c4(param_1,param_2,param_4 | *(uint *)(DAT_02189884 + param_3 * 4));
  return;
}

