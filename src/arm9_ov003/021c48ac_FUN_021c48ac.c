/* Decompiled C draft; module arm9_ov003; ROM address 021c48ac. No matching claim. */
#include "types.h"
#include "deps/021c48ac_FUN_021c48ac.h"

void FUN_021c48ac(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    FUN_021bf344();
    if (*DAT_021c48ec == '\0') {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x15,8);
    FUN_021c212c(DAT_021c48f0);
  }
  return;
}

