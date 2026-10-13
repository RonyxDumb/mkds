/* Decompiled C draft; module arm9_ov001; ROM address 02180c24. No matching claim. */
#include "types.h"
#include "deps/02180c24_func_ov001_02180c24.h"

void func_ov001_02180c24(ushort param_1)

{
  *puRam02180c3c = *puRam02180c3c & 0xfffc | param_1;
  return;
}

