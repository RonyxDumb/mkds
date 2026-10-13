/* Decompiled C draft; module arm9_ov000; ROM address 021a2c64. No matching claim. */
#include "types.h"
#include "deps/021a2c64_FUN_021a2c64.h"

undefined4 FUN_021a2c64(void)

{
  int iVar1;
  
  iVar1 = FUN_0219c39c();
  if (iVar1 != 0) {
    return 0;
  }
  if (((*DAT_021a2ca4 != 0) && (iVar1 = FUN_0219bab4(), iVar1 == 5)) &&
     (*(char *)(*DAT_021a2ca4 + DAT_021a2ca8) == '\0')) {
    return 1;
  }
  return 0;
}

