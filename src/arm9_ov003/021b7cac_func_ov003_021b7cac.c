/* Decompiled C draft; module arm9_ov003; ROM address 021b7cac. No matching claim. */
#include "types.h"
#include "deps/021b7cac_func_ov003_021b7cac.h"

uint func_ov003_021b7cac(uint param_1)

{
  return param_1 << 0x18 & uRam021b7cd8 |
         param_1 << 8 & uRam021b7cdc | param_1 >> 0x18 | param_1 >> 8 & uRam021b7ce0;
}

