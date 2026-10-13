/* Decompiled C draft; module arm9_ov003; ROM address 021c31b4. No matching claim. */
#include "types.h"
#include "deps/021c31b4_FUN_021c31b4.h"

void FUN_021c31b4(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    FUN_021bf344();
    if (*DAT_021c31f4 == '\0') {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x15,8);
    FUN_021c212c(DAT_021c31f8);
  }
  return;
}

