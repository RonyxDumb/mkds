/* Decompiled C draft; module arm9_ov001; ROM address 02180b4c. No matching claim. */
#include "types.h"
#include "deps/02180b4c_func_ov001_02180b4c.h"

void func_ov001_02180b4c(int param_1)

{
  if (param_1 == 0) {
    *puRam02180b74 = *puRam02180b74 & 0xffbf;
  }
  else {
    *puRam02180b74 = *puRam02180b74 | 0x40;
  }
  return;
}

