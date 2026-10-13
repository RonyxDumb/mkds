/* Decompiled C draft; module arm9; ROM address 020cab2c. No matching claim. */
#include "types.h"
#include "deps/020cab2c_func_020cab2c.h"

void func_020cab2c(uint param_1,int param_2)

{
  *puRam020cab54 = param_1 & uRam020cab4c | uRam020cab50 & param_2 << 0x10;
  return;
}

