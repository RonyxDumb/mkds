/* Decompiled C draft; module arm9_ov003; ROM address 021c46a8. No matching claim. */
#include "types.h"
#include "deps/021c46a8_FUN_021c46a8.h"

void FUN_021c46a8(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_021c46c8;
  *DAT_021c46c8 = *DAT_021c46c8 + 1;
  if (0x77 < *pbVar1) {
    FUN_021c212c(DAT_021c46cc);
  }
  return;
}

