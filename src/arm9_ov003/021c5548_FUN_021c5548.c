/* Decompiled C draft; module arm9_ov003; ROM address 021c5548. No matching claim. */
#include "types.h"
#include "deps/021c5548_FUN_021c5548.h"

void FUN_021c5548(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_021c5568;
  *DAT_021c5568 = *DAT_021c5568 + 1;
  if (0x77 < *pbVar1) {
    FUN_021c212c(DAT_021c556c);
  }
  return;
}

