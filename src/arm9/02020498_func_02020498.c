/* Decompiled C draft; module arm9; ROM address 02020498. No matching claim. */
#include "types.h"
#include "deps/02020498_func_02020498.h"

int func_02020498(int param_1)

{
  if ((0x7f < param_1) && (param_1 < 0xff)) {
    return param_1 + -0x7f;
  }
  return 0x7f - param_1;
}

