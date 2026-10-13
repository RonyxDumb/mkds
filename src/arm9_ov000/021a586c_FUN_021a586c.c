/* Decompiled C draft; module arm9_ov000; ROM address 021a586c. No matching claim. */
#include "types.h"
#include "deps/021a586c_FUN_021a586c.h"

void FUN_021a586c(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*(int *)(*DAT_021a589c + DAT_021a58a0) != 0) {
    local_14 = param_5;
    local_20 = param_1;
    local_1e = param_2;
    local_1c = param_3;
    local_18 = param_4;
    (**(code **)(*DAT_021a589c + DAT_021a58a0))(&local_20);
  }
  return;
}

