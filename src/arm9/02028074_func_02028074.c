/* Decompiled C draft; module arm9; ROM address 02028074. No matching claim. */
#include "types.h"
#include "deps/02028074_func_02028074.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_02028074(int param_1)

{
  _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | param_1 << 8;
  return;
}

