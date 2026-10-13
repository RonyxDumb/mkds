/* Decompiled C draft; module arm9_ov003; ROM address 021c2d18. No matching claim. */
#include "types.h"
#include "deps/021c2d18_FUN_021c2d18.h"

void FUN_021c2d18(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) {
    FUN_021bf698();
    FUN_021bf410();
    FUN_021d1490(*DAT_021c2d8c);
    FUN_021d272c(1,1);
    FUN_021d272c(0,0x14);
    if (*DAT_021c2d90 == '\0') {
      FUN_021c2120(1,0);
      FUN_021c212c(DAT_021c2d94);
      return;
    }
    if (*DAT_021c2d90 != '\x01') {
      return;
    }
    FUN_021c2120(0,0);
    FUN_021c212c(DAT_021c2d98);
  }
  return;
}

