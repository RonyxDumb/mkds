/* Decompiled C draft; module arm9; ROM address 0212825c. No matching claim. */
#include "types.h"
#include "deps/0212825c_func_0212825c.h"

int func_0212825c(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (9 < param_1) {
    param_1 = 9;
  }
  return (int)*(char *)(iRam02128270 + param_1);
}

