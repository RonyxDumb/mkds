/* Decompiled C draft; module arm9_ov003; ROM address 021cc658. No matching claim. */
#include "types.h"
#include "deps/021cc658_FUN_021cc658.h"

void FUN_021cc658(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    FUN_021bf344();
    if ((byte)(*DAT_021cc69c - 2U) < 2) {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x15,8);
    FUN_021c212c(DAT_021cc6a0);
  }
  return;
}

