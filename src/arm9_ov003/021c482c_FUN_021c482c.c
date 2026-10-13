/* Decompiled C draft; module arm9_ov003; ROM address 021c482c. No matching claim. */
#include "types.h"
#include "deps/021c482c_FUN_021c482c.h"

void FUN_021c482c(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) &&
     (iVar1 = FUN_021bf2f0(), iVar1 != 0)) {
    FUN_021d2168(0);
    if (*DAT_021c48a0 == '\0') {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021d272c(0,0x15);
    if (*DAT_021c48a0 == '\0') {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c48a4);
      return;
    }
    FUN_021c2120(0,1);
    FUN_021c212c(DAT_021c48a8);
  }
  return;
}

