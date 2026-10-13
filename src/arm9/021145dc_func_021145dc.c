/* Decompiled C draft; module arm9; ROM address 021145dc. No matching claim. */
#include "types.h"
#include "deps/021145dc_func_021145dc.h"

void func_021145dc(void)

{
  *puRam021145f8 = *puRam021145f8 & uRam02114600 | ((*puRam021145f8 & uRam021145fc) >> 8 | 9) << 8;
  return;
}

