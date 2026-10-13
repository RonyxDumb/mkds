/* Decompiled C draft; module arm9_ov003; ROM address 021c7850. No matching claim. */
#include "types.h"
#include "deps/021c7850_FUN_021c7850.h"

void FUN_021c7850(void)

{
  int iVar1;
  int local_8 [2];
  
  iVar1 = FUN_021d1f70(1);
  if (((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) &&
     (iVar1 = FUN_021bf2f0(), iVar1 != 0)) {
    FUN_021d2168(0);
    FUN_021bf410();
    FUN_021d272c(1,1);
    FUN_021d272c(0,0x15);
    FUN_021c20dc(0,local_8);
    if (local_8[0] != 0) {
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021c78d0);
      return;
    }
    FUN_021c2120(2,0);
    FUN_021c20f8(0,0);
    FUN_021c7d30(0);
    FUN_021c212c(DAT_021c78d4);
  }
  return;
}

