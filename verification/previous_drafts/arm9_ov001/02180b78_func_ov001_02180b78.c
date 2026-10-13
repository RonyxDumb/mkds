/* Decompiled C draft; module arm9_ov001; ROM address 02180b78. No matching claim. */
#include "types.h"
#include "deps/02180b78_func_ov001_02180b78.h"

void func_ov001_02180b78(ushort param_1)

{
  *puRam02180b90 = *puRam02180b90 & 0xfffc | param_1;
  return;
}

