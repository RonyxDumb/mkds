/* Decompiled C draft; module arm9_ov001; ROM address 02180c40. No matching claim. */
#include "types.h"
#include "deps/02180c40_func_ov001_02180c40.h"

void func_ov001_02180c40(uint param_1,int param_2)

{
  *puRam02180c68 = param_1 & uRam02180c60 | uRam02180c64 & param_2 << 0x10;
  return;
}

