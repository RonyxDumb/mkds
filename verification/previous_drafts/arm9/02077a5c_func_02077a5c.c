/* Decompiled C draft; module arm9; ROM address 02077a5c. No matching claim. */
#include "types.h"
#include "deps/02077a5c_func_02077a5c.h"

uint func_02077a5c(void)

{
  return *(int *)(*piRam02077a6c + 4) + 1U & 0xffff;
}

