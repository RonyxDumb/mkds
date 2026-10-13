/* Decompiled C draft; module arm9_ov003; ROM address 021cc1cc. No matching claim. */
#include "types.h"
#include "deps/021cc1cc_FUN_021cc1cc.h"

void FUN_021cc1cc(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    FUN_021bf344();
    if (*DAT_021cc20c == '\0') {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x15,8);
    FUN_021c212c(DAT_021cc210);
  }
  return;
}

