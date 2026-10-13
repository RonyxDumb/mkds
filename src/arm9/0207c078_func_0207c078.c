/* Decompiled C draft; module arm9; ROM address 0207c078. No matching claim. */
#include "types.h"
#include "deps/0207c078_func_0207c078.h"

bool func_0207c078(short *param_1)

{
  short sVar1;
  
  *param_1 = *param_1 + -1;
  sVar1 = *param_1;
  if (sVar1 < 1) {
    *param_1 = 0;
  }
  return sVar1 < 1;
}

