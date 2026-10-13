/* Decompiled C draft; module arm9_ov003; ROM address 021c4dd4. No matching claim. */
#include "types.h"
#include "deps/021c4dd4_FUN_021c4dd4.h"

void FUN_021c4dd4(int param_1)

{
  FUN_021cdbd0();
  if (param_1 == 0) {
    *DAT_021c4e0c = 1;
    FUN_021cdc10(0x10);
  }
  else {
    *DAT_021c4e0c = 2;
    FUN_021cdc10(0x12);
  }
  FUN_021c27d0(0);
  FUN_021c212c(DAT_021c4e10);
  return;
}

