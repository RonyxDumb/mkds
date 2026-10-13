/* Decompiled C draft; module arm9; ROM address 02028010. No matching claim. */
#include "types.h"
#include "deps/02028010_func_02028010.h"

void func_02028010(ushort param_1)

{
  *puRam02028028 = *puRam02028028 & 0xfffc | param_1;
  return;
}

