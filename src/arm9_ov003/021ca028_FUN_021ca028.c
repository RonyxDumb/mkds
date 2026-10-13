/* Decompiled C draft; module arm9_ov003; ROM address 021ca028. No matching claim. */
#include "types.h"
#include "deps/021ca028_FUN_021ca028.h"

void FUN_021ca028(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_021ca048;
  *DAT_021ca048 = *DAT_021ca048 + 1;
  if (0x77 < *pbVar1) {
    FUN_021c212c(DAT_021ca04c);
  }
  return;
}

