/* Decompiled C draft; module arm9_ov003; ROM address 021cb3d8. No matching claim. */
#include "types.h"
#include "deps/021cb3d8_FUN_021cb3d8.h"

void FUN_021cb3d8(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) &&
     (iVar1 = FUN_021bf2f0(), iVar1 != 0)) {
    FUN_021bf698();
    FUN_021bf410();
    FUN_021d1490(*DAT_021cb4b0);
    FUN_021d272c(1,1);
    FUN_021d272c(0,0x14);
    if (*DAT_021cb4b4 == '\0') {
      FUN_021c2120(2,0);
      FUN_021c212c(DAT_021cb4b8);
      return;
    }
    switch(*DAT_021cb4bc) {
    case 0:
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021cb4c0);
      return;
    case 1:
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021cb4c4);
      return;
    case 2:
      FUN_021c2120(2,1);
      FUN_021c212c(DAT_021cb4c8);
      return;
    case 3:
      FUN_021c2120(2);
      FUN_021c20f8(0,0);
      FUN_021c7d30(1);
      FUN_021c212c(DAT_021cb4cc);
    }
  }
  return;
}

