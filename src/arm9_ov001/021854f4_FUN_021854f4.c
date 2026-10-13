/* Decompiled C draft; module arm9_ov001; ROM address 021854f4. No matching claim. */
#include "types.h"
#include "deps/021854f4_FUN_021854f4.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_021854f4(int param_1)

{
  _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | param_1 << 8;
  return;
}

