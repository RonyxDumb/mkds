/* Decompiled C draft; module arm9_ov003; ROM address 021cc5a8. No matching claim. */
#include "types.h"
#include "deps/021cc5a8_FUN_021cc5a8.h"

void FUN_021cc5a8(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(0);
  if ((iVar1 == 0) &&
     (((*DAT_021cc648 != '\x02' || (iVar1 = FUN_021d1f70(1), iVar1 == 0)) &&
      (iVar1 = FUN_021bf2f0(), iVar1 != 0)))) {
    FUN_021ce848();
    FUN_021beecc();
    FUN_021d2168(0);
    if ((byte)(*DAT_021cc648 - 2U) < 2) {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021d272c(0,0x15);
    if (*DAT_021cc648 == '\x02') {
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021cc64c);
      return;
    }
    if (*DAT_021cc648 == '\x03') {
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021cc650);
      return;
    }
    FUN_021c2120(0,0);
    FUN_021c212c(DAT_021cc654);
  }
  return;
}

