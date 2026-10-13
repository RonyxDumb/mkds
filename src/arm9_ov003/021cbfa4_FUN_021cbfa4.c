/* Decompiled C draft; module arm9_ov003; ROM address 021cbfa4. No matching claim. */
#include "types.h"
#include "deps/021cbfa4_FUN_021cbfa4.h"

void FUN_021cbfa4(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_021cbfc4;
  *DAT_021cbfc4 = *DAT_021cbfc4 + 1;
  if (0x77 < *pbVar1) {
    FUN_021c212c(DAT_021cbfc8);
  }
  return;
}

