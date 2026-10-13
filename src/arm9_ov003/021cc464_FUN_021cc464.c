/* Decompiled C draft; module arm9_ov003; ROM address 021cc464. No matching claim. */
#include "types.h"
#include "deps/021cc464_FUN_021cc464.h"

void FUN_021cc464(void)

{
  int iVar1;
  
  iVar1 = FUN_021cef80();
  if (iVar1 == 0) {
    *DAT_021cc4a0 = 1;
    FUN_021cdc10(7);
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    *DAT_021cc4a0 = 3;
    FUN_021cdc10(6);
  }
  FUN_021cef90();
  FUN_021c212c(DAT_021cc4a4);
  return;
}

