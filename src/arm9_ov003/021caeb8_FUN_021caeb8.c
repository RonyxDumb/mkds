/* Decompiled C draft; module arm9_ov003; ROM address 021caeb8. No matching claim. */
#include "types.h"
#include "deps/021caeb8_FUN_021caeb8.h"

void FUN_021caeb8(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_021bf334();
  if (iVar1 == 0) {
    iVar1 = FUN_021c20c0();
    if (iVar1 == 0) {
      FUN_021cdc10(7);
      *(undefined1 *)(*DAT_021caf88 + 0x1d) = 2;
    }
    else if (iVar1 == 1) {
      FUN_021bf2d0();
      FUN_021c212c(DAT_021caf8c);
      return;
    }
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    *(undefined1 *)(*DAT_021caf88 + 0x1d) = 1;
    uVar2 = (uint)*DAT_021caf90;
    if (3 < uVar2) {
      iVar1 = FUN_021cd844(uVar2 - 4);
      if (iVar1 != 0xff) {
        FUN_021cdc10(6);
        iVar1 = FUN_021c20d0();
        FUN_021cefc0(0x98,0,1,(int)*(char *)(DAT_021caf94 + iVar1),uVar2 - 3);
        FUN_021caae0();
        FUN_021bf2d0();
        FUN_021c212c(DAT_021caf98);
        return;
      }
      FUN_021cdc10(9);
      FUN_021bf310(0xffffffff);
      return;
    }
    if (uVar2 < 3) {
      FUN_021cd790();
    }
    FUN_021cdc10(6);
    FUN_021ca940();
  }
  FUN_021c212c(DAT_021caf9c);
  return;
}

