/* Decompiled C draft; module arm9; ROM address 02128244. No matching claim. */
#include "types.h"
#include "deps/02128244_func_02128244.h"

int func_02128244(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (9 < param_1) {
    param_1 = 9;
  }
  return (int)*(char *)(iRam02128258 + param_1);
}

