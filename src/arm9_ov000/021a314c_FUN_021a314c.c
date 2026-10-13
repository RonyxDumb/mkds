/* Decompiled C draft; module arm9_ov000; ROM address 021a314c. No matching claim. */
#include "types.h"
#include "deps/021a314c_FUN_021a314c.h"

void FUN_021a314c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(*DAT_021a3174 + DAT_021a3178) != 0) {
    uVar1 = FUN_0219b9c4();
    (**(code **)(*DAT_021a3174 + DAT_021a3178))(param_2,uVar1);
  }
  return;
}

