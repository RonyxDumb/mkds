/* Decompiled C draft; module arm9_ov001; ROM address 02180bf8. No matching claim. */
#include "types.h"
#include "deps/02180bf8_func_ov001_02180bf8.h"

void func_ov001_02180bf8(int param_1)

{
  if (param_1 == 0) {
    *puRam02180c20 = *puRam02180c20 & 0xffbf;
  }
  else {
    *puRam02180c20 = *puRam02180c20 | 0x40;
  }
  return;
}

