/* Decompiled C draft; module arm9_ov003; ROM address 021c3a7c. No matching claim. */
#include "types.h"
#include "deps/021c3a7c_FUN_021c3a7c.h"

void FUN_021c3a7c(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    if (*DAT_021c3abc != '\0') {
      FUN_021bf344();
    }
    FUN_021d1ee0(3,1,1,8);
    FUN_021d1ee0(3,0,0x14,8);
    FUN_021c212c(DAT_021c3ac0);
  }
  return;
}

