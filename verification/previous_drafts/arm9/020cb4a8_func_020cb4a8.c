/* Decompiled C draft; module arm9; ROM address 020cb4a8. No matching claim. */
#include "types.h"
#include "deps/020cb4a8_func_020cb4a8.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_020cb4a8(int param_1)

{
  _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | param_1 << 8;
  return;
}

