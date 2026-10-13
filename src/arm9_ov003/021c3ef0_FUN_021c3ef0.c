/* Decompiled C draft; module arm9_ov003; ROM address 021c3ef0. No matching claim. */
#include "types.h"
#include "deps/021c3ef0_FUN_021c3ef0.h"

void FUN_021c3ef0(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(0);
  if ((iVar1 == 0) && (iVar1 = FUN_021c27e4(), iVar1 != 0)) {
    FUN_021bf9b8();
    FUN_021beecc();
    FUN_021d2168(0);
    FUN_021d272c(0,0x15);
    FUN_021c2120(0,1);
    if (*DAT_021c3f54 == '\0') {
      FUN_021c212c(DAT_021c3f58);
      return;
    }
    if (*DAT_021c3f54 == '\x02') {
      FUN_021c212c(DAT_021c3f5c);
      return;
    }
    FUN_021c212c(DAT_021c3f60);
  }
  return;
}

