/* Decompiled C draft; module arm9_ov001; ROM address 02180b94. No matching claim. */
#include "types.h"
#include "deps/02180b94_func_ov001_02180b94.h"

void func_ov001_02180b94(uint param_1,int param_2)

{
  *puRam02180bbc = param_1 & uRam02180bb4 | uRam02180bb8 & param_2 << 0x10;
  return;
}

