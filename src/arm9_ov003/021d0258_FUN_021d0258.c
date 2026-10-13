/* Decompiled C draft; module arm9_ov003; ROM address 021d0258. No matching claim. */
#include "types.h"
#include "deps/021d0258_FUN_021d0258.h"

undefined4 FUN_021d0258(void)

{
  int iVar1;
  
  if (*(int *)(*DAT_021d0298 + 0x40) != 6) {
    return 0;
  }
  FUN_021d07b0(3);
  iVar1 = func_0x021453b4(*DAT_021d0298 + DAT_021d029c);
  if (iVar1 != 2) {
    FUN_021d079c();
    return 0;
  }
  return 1;
}

