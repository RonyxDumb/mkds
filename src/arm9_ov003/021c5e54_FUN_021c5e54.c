/* Decompiled C draft; module arm9_ov003; ROM address 021c5e54. No matching claim. */
#include "types.h"
#include "deps/021c5e54_FUN_021c5e54.h"

void FUN_021c5e54(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    if (*(char *)(*DAT_021c5e9c + 0x54) == '\0') {
      FUN_021bf2d0();
    }
    else {
      FUN_021bf344();
    }
    FUN_021d1ee0(3,1,1,8);
    FUN_021d1ee0(3,0,0x1d,8);
    FUN_021c212c(DAT_021c5ea0);
  }
  return;
}

