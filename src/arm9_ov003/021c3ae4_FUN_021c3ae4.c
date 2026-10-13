/* Decompiled C draft; module arm9_ov003; ROM address 021c3ae4. No matching claim. */
#include "types.h"
#include "deps/021c3ae4_FUN_021c3ae4.h"

void FUN_021c3ae4(void)

{
  int iVar1;
  int local_18;
  int local_14;
  
  iVar1 = FUN_021bf334();
  if (iVar1 == 0) {
    FUN_021cdc10(7);
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    func_0x02151910(&local_18);
    if (*DAT_021c3b50 != '\0') {
      if (local_14 == 0 && local_18 == 0) {
        FUN_021cdc10(9);
        FUN_021bf310(0xffffffff);
        return;
      }
    }
    FUN_021cdc10(6);
    FUN_021c391c();
    *DAT_021c3b54 = 1;
  }
  FUN_021c212c(DAT_021c3b58);
  return;
}

