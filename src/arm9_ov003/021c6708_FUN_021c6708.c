/* Decompiled C draft; module arm9_ov003; ROM address 021c6708. No matching claim. */
#include "types.h"
#include "deps/021c6708_FUN_021c6708.h"

void FUN_021c6708(void)

{
  int iVar1;
  
  iVar1 = FUN_021cef6c();
  if (iVar1 == 0) {
    **(uint **)(*DAT_021c6730 + 4) = **(uint **)(*DAT_021c6730 + 4) & DAT_021c6734;
    FUN_021c212c(DAT_021c6738);
  }
  return;
}

