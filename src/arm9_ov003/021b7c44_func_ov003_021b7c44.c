/* Decompiled C draft; module arm9_ov003; ROM address 021b7c44. No matching claim. */
#include "types.h"
#include "deps/021b7c44_func_ov003_021b7c44.h"

uint func_ov003_021b7c44(int param_1)

{
  return param_1 >> 8 & 0xffU | param_1 << 8 & uRam021b7c58 & 0xffff;
}

