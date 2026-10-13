/* Decompiled C draft; module arm7; ROM address 06009e98. No matching claim. */
#include "types.h"
#include "deps/06009e98_FUN_06009e98.h"

undefined2 FUN_06009e98(ushort param_1)

{
  *DAT_06009ec4 = param_1 | 0x6000;
  FUN_0600f00c();
  return *DAT_06009ec8;
}

