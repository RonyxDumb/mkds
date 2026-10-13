/* Decompiled C draft; module arm9_ov003; ROM address 021cc144. No matching claim. */
#include "types.h"
#include "deps/021cc144_FUN_021cc144.h"

void FUN_021cc144(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(0);
  if ((iVar1 == 0) &&
     (((*DAT_021cc1c0 != '\0' || (iVar1 = FUN_021d1f70(1), iVar1 == 0)) &&
      (iVar1 = FUN_021bf2f0(), iVar1 != 0)))) {
    FUN_021d2168(0);
    if (*DAT_021cc1c0 == '\0') {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021d272c(0,0x15);
    if (*DAT_021cc1c0 == '\0') {
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021cc1c4);
      return;
    }
    FUN_021c2120(2,1);
    FUN_021c212c(DAT_021cc1c8);
  }
  return;
}

