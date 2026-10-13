/* Decompiled C draft; module arm9_ov003; ROM address 021c6d0c. No matching claim. */
#include "types.h"
#include "deps/021c6d0c_FUN_021c6d0c.h"

void FUN_021c6d0c(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) {
    FUN_021c0d2c();
    FUN_021cdc10(0x14);
    if (*(char *)(*DAT_021c6d60 + 0x29) == '\0') {
      FUN_021c0cd0(0);
    }
    if (*(char *)(*DAT_021c6d60 + 0x29) == ' ') {
      FUN_021c0cbc(0);
    }
    FUN_021c212c(DAT_021c6d64);
  }
  return;
}

