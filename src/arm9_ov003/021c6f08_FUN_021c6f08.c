/* Decompiled C draft; module arm9_ov003; ROM address 021c6f08. No matching claim. */
#include "types.h"
#include "deps/021c6f08_FUN_021c6f08.h"

void FUN_021c6f08(void)

{
  int iVar1;
  
  iVar1 = FUN_021cef6c();
  if (iVar1 == 0) {
    **(uint **)(*DAT_021c6f30 + 4) = **(uint **)(*DAT_021c6f30 + 4) & DAT_021c6f34;
    FUN_021c212c(DAT_021c6f38);
  }
  return;
}

