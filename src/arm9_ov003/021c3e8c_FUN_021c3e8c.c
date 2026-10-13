/* Decompiled C draft; module arm9_ov003; ROM address 021c3e8c. No matching claim. */
#include "types.h"
#include "deps/021c3e8c_FUN_021c3e8c.h"

void FUN_021c3e8c(int param_1)

{
  if (param_1 == 2) {
    FUN_021cd42c();
    *DAT_021c3ee8 = 1;
    FUN_021cdbd0();
    FUN_021cdc10(0x10);
  }
  else if (param_1 == 3) {
    *DAT_021c3ee8 = 2;
    FUN_021cdbd0();
    FUN_021cdc10(0x12);
  }
  else {
    *DAT_021c3ee8 = 0;
    FUN_021cdbd0();
    FUN_021cdc10(0x12);
  }
  FUN_021c27d0(0);
  FUN_021c2824();
  FUN_021c212c(DAT_021c3eec);
  return;
}

