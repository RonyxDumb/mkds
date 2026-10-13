/* Decompiled C draft; module arm9; ROM address 0202802c. No matching claim. */
#include "types.h"
#include "deps/0202802c_func_0202802c.h"

void func_0202802c(uint param_1,int param_2)

{
  *puRam02028054 = param_1 & uRam0202804c | uRam02028050 & param_2 << 0x10;
  return;
}

