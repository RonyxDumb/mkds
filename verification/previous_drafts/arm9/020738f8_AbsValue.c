/* Decompiled C draft; module arm9; ROM address 020738f8. No matching claim. */
#include "types.h"
#include "deps/020738f8_AbsValue.h"

int AbsValue(int param_1)

{
  if (param_1 < 1) {
    param_1 = -param_1;
  }
  return param_1;
}

