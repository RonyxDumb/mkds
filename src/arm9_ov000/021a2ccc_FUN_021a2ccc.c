/* Decompiled C draft; module arm9_ov000; ROM address 021a2ccc. No matching claim. */
#include "types.h"
#include "deps/021a2ccc_FUN_021a2ccc.h"

undefined4 FUN_021a2ccc(void)

{
  int iVar1;
  
  if (((*DAT_021a2d10 != 0) && (*(int *)(*DAT_021a2d10 + DAT_021a2d14) != 0)) &&
     (iVar1 = FUN_0219c39c(), iVar1 == 0)) {
    iVar1 = FUN_021a2768(*(undefined4 *)(*DAT_021a2d10 + DAT_021a2d14));
    if (iVar1 == 0) {
      return 1;
    }
    return 0;
  }
  return 0;
}

