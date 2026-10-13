/* Decompiled C draft; module arm9_ov003; ROM address 021c5120. No matching claim. */
#include "types.h"
#include "deps/021c5120_FUN_021c5120.h"

void FUN_021c5120(void)

{
  ushort *puVar1;
  
  FUN_021c52f4();
  FUN_021c52f0();
  FUN_021c52d0();
  puVar1 = DAT_021c5150;
  *DAT_021c5150 = *DAT_021c5150 + 1;
  if (DAT_021c5154 <= *puVar1) {
    FUN_021cdbd0();
    FUN_021c212c(DAT_021c5158);
  }
  return;
}

