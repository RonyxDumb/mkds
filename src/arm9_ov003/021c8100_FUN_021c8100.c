/* Decompiled C draft; module arm9_ov003; ROM address 021c8100. No matching claim. */
#include "types.h"
#include "deps/021c8100_FUN_021c8100.h"

void FUN_021c8100(int param_1)

{
  undefined1 uVar1;
  
  *DAT_021c8120 = (char)param_1;
  uVar1 = FUN_021c83cc(*(undefined1 *)(DAT_021c8124 + param_1));
  *DAT_021c8128 = uVar1;
  FUN_021c81b8();
  return;
}

