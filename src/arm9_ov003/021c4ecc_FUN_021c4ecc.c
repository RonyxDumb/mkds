/* Decompiled C draft; module arm9_ov003; ROM address 021c4ecc. No matching claim. */
#include "types.h"
#include "deps/021c4ecc_FUN_021c4ecc.h"

void FUN_021c4ecc(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && ((*DAT_021c4f1c != '\0' || (iVar1 = FUN_021c27e4(), iVar1 != 0)))) {
    FUN_021bf344();
    if (*DAT_021c4f1c == '\0') {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x15,8);
    FUN_021c212c(DAT_021c4f20);
  }
  return;
}

