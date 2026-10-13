/* Decompiled C draft; module arm7; ROM address 03803e7c. No matching claim. */
#include "types.h"
#include "deps/03803e7c_FUN_03803e7c.h"

void FUN_03803e7c(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_03803eb0;
  if ((param_2 & 0x3f) == 1) {
    *DAT_03803eb0 = param_2;
    puVar1[4] = 1;
  }
  else {
    FUN_037fb000();
  }
  return;
}

