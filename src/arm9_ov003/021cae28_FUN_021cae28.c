/* Decompiled C draft; module arm9_ov003; ROM address 021cae28. No matching claim. */
#include "types.h"
#include "deps/021cae28_FUN_021cae28.h"

void FUN_021cae28(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if (iVar1 == 0) {
    if ((*(char *)(*DAT_021cae7c + 0x1d) == '\x01') &&
       ((*DAT_021cae80 == '\x03' || (iVar1 = FUN_021cdb6c(), *(char *)(iVar1 + 0xe7) != -1)))) {
      FUN_021bf344();
    }
    FUN_021d1ee0(3,1,1,8);
    FUN_021d1ee0(3,0,0x14,8);
    FUN_021c212c(DAT_021cae84);
    return;
  }
  return;
}

