/* Decompiled C draft; module arm9_ov003; ROM address 021c4410. No matching claim. */
#include "types.h"
#include "deps/021c4410_FUN_021c4410.h"

void FUN_021c4410(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(0);
  if ((iVar1 == 0) &&
     (((*DAT_021c448c != '\0' || (iVar1 = FUN_021d1f70(1), iVar1 == 0)) &&
      (iVar1 = FUN_021bf2f0(), iVar1 != 0)))) {
    FUN_021d2168(0);
    if (*DAT_021c448c == '\0') {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021d272c(0,0x15);
    if (*DAT_021c448c == '\0') {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c4490);
      return;
    }
    FUN_021c2120(0,1);
    FUN_021c212c(DAT_021c4494);
  }
  return;
}

