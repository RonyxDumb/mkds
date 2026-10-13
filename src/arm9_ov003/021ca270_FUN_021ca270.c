/* Decompiled C draft; module arm9_ov003; ROM address 021ca270. No matching claim. */
#include "types.h"
#include "deps/021ca270_FUN_021ca270.h"

void FUN_021ca270(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(0);
  if ((iVar1 == 0) &&
     (((*DAT_021ca2f4 != '\0' || (iVar1 = FUN_021d1f70(1), iVar1 == 0)) &&
      (iVar1 = FUN_021bf2f0(), iVar1 != 0)))) {
    FUN_021beecc();
    FUN_021d2168(0);
    if (*DAT_021ca2f4 == '\0') {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021d272c(0,0x15);
    if (*DAT_021ca2f4 == '\0') {
      FUN_021c29b8();
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021ca2f8);
      return;
    }
    FUN_021c2120(0,0);
    FUN_021c212c(DAT_021ca2fc);
  }
  return;
}

