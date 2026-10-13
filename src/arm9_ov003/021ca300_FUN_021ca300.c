/* Decompiled C draft; module arm9_ov003; ROM address 021ca300. No matching claim. */
#include "types.h"
#include "deps/021ca300_FUN_021ca300.h"

void FUN_021ca300(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    if (*DAT_021ca348 == '\0') {
      FUN_021bf344();
    }
    if (*DAT_021ca348 == '\0') {
      FUN_021d1ee0(3,1,1,8);
    }
    FUN_021d1ee0(3,0,0x14,8);
    FUN_021c212c(DAT_021ca34c);
  }
  return;
}

