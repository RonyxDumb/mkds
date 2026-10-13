/* Decompiled C draft; module arm9_ov003; ROM address 021cc410. No matching claim. */
#include "types.h"
#include "deps/021cc410_FUN_021cc410.h"

void FUN_021cc410(void)

{
  int iVar1;
  
  iVar1 = FUN_021cef6c();
  if (iVar1 == 0) {
    if (*DAT_021cc454 == '\x01') {
      FUN_021c212c(DAT_021cc458);
      return;
    }
    FUN_021cdc10(0xb);
    FUN_021bf2e0();
    *DAT_021cc454 = '\0';
    FUN_021ce834(DAT_021cc45c);
    FUN_021c212c(DAT_021cc460);
  }
  return;
}

