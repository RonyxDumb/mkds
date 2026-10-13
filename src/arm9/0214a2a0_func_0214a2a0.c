/* Decompiled C draft; module arm9; ROM address 0214a2a0. No matching claim. */
#include "types.h"
#include "deps/0214a2a0_func_0214a2a0.h"

int func_0214a2a0(void)

{
  return ((int)(*puRam0214a2bc & 0x1f00) >> 8) * 0x800 + 0x6200000;
}

