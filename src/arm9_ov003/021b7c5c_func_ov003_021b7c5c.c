/* Decompiled C draft; module arm9_ov003; ROM address 021b7c5c. No matching claim. */
#include "types.h"
#include "deps/021b7c5c_func_ov003_021b7c5c.h"

uint func_ov003_021b7c5c(uint param_1)

{
  return param_1 << 0x18 & uRam021b7c88 |
         param_1 << 8 & uRam021b7c8c | param_1 >> 0x18 | param_1 >> 8 & uRam021b7c90;
}

