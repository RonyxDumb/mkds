/* Decompiled C draft; module arm9; ROM address 02035d48. No matching claim. */
#include "types.h"
#include "deps/02035d48_func_02035d48.h"

void func_02035d48(uint param_1,int param_2)

{
  *puRam02035d70 = param_1 & uRam02035d68 | uRam02035d6c & param_2 << 0x10;
  return;
}

