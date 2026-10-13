/* Decompiled C draft; module arm9_ov003; ROM address 021b7e70. No matching claim. */
#include "types.h"
#include "deps/021b7e70_func_ov003_021b7e70.h"

undefined4 func_ov003_021b7e70(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0 < param_2) {
    uVar1 = (*(code *)*puRam021b7e90)(param_2);
    return uVar1;
  }
  return 0;
}

