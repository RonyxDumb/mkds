/* Decompiled C draft; module arm9_ov003; ROM address 021c4b78. No matching claim. */
#include "types.h"
#include "deps/021c4b78_FUN_021c4b78.h"

void FUN_021c4b78(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) {
    if ((*DAT_021c4bb8 == '\0') && (*DAT_021c4bbc == '\x01')) {
      thunk_FUN_021d11a0();
    }
    else {
      FUN_021c2824();
    }
    FUN_021c212c(DAT_021c4bc0);
  }
  return;
}

