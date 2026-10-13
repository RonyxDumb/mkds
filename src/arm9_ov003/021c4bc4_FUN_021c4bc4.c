/* Decompiled C draft; module arm9_ov003; ROM address 021c4bc4. No matching claim. */
#include "types.h"
#include "deps/021c4bc4_FUN_021c4bc4.h"

void FUN_021c4bc4(void)

{
  int iVar1;
  
  iVar1 = FUN_021cef6c();
  if (iVar1 == 0) {
    if (*DAT_021c4bfc == '\0') {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x15,8);
    FUN_021c212c(DAT_021c4c00);
  }
  return;
}

