/* Decompiled C draft; module arm9_ov001; ROM address 021871d0. No matching claim. */
#include "types.h"
#include "deps/021871d0_FUN_021871d0.h"

undefined4 FUN_021871d0(int param_1)

{
  if (((*(uint *)(param_1 + DAT_021871ec) & DAT_021871f0) != 0) &&
     (*(int *)(param_1 + DAT_021871f4) < 1)) {
    return 1;
  }
  return 0;
}

