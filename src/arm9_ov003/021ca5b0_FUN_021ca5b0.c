/* Decompiled C draft; module arm9_ov003; ROM address 021ca5b0. No matching claim. */
#include "types.h"
#include "deps/021ca5b0_FUN_021ca5b0.h"

void FUN_021ca5b0(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) &&
     (iVar1 = FUN_021bf2f0(), iVar1 != 0)) {
    do {
      iVar1 = FUN_021cd118();
    } while (iVar1 == 0);
    FUN_021beecc();
    FUN_021d2168(0);
    FUN_021bf410();
    FUN_021d272c(1,1);
    FUN_021d272c(0,0x15);
    if (*DAT_021ca640 != '\x01') {
      FUN_021cd27c();
      iVar1 = FUN_021cdb6c();
      FUN_021cd790(*(undefined1 *)(iVar1 + 0xf4));
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021ca644);
      return;
    }
    FUN_021c2120(0,1);
    FUN_021c20f8(0,0);
    FUN_021c212c(DAT_021ca648);
  }
  return;
}

