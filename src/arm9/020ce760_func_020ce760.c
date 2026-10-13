/* Decompiled C draft; module arm9; ROM address 020ce760. No matching claim. */
#include "types.h"
#include "deps/020ce760_func_020ce760.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_020ce760(int param_1)

{
  _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | param_1 << 8;
  return;
}

