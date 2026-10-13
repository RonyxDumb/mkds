/* Decompiled C draft; module arm9_ov003; ROM address 021c4e14. No matching claim. */
#include "types.h"
#include "deps/021c4e14_FUN_021c4e14.h"

void FUN_021c4e14(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(0);
  if (((iVar1 == 0) &&
      (((*DAT_021c4ebc != '\0' || (iVar1 = FUN_021d1f70(1), iVar1 == 0)) &&
       (iVar1 = FUN_021bf2f0(), iVar1 != 0)))) &&
     ((*DAT_021c4ebc != '\0' || (iVar1 = FUN_021c27e4(), iVar1 != 0)))) {
    FUN_021beecc();
    FUN_021d2168(0);
    if (*DAT_021c4ebc == '\0') {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021d272c(0,0x15);
    if (*DAT_021c4ebc == '\0') {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c4ec0);
      return;
    }
    if (*DAT_021c4ebc == '\x02') {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c4ec4);
      return;
    }
    FUN_021c2120(0,1);
    FUN_021c212c(DAT_021c4ec8);
  }
  return;
}

