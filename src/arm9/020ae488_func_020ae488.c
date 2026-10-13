/* Decompiled C draft; module arm9; ROM address 020ae488. No matching claim. */
#include "types.h"
#include "deps/020ae488_func_020ae488.h"

int func_020ae488(int param_1)

{
  if (param_1 < 0) {
    return 0;
  }
  if (param_1 < 3) {
    return param_1 * -0x30000 >> 0x10;
  }
  if (param_1 < 7) {
    return -9;
  }
  if (param_1 < 10) {
    return ((param_1 + -7) * 3 + -9) * 0x10000 >> 0x10;
  }
  return 0;
}

