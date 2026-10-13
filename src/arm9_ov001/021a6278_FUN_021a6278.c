/* Decompiled C draft; module arm9_ov001; ROM address 021a6278. No matching claim. */
#include "types.h"
#include "deps/021a6278_FUN_021a6278.h"

undefined4 FUN_021a6278(void)

{
  uint uVar1;
  
  uVar1 = func_ov001_02181004(*(undefined4 *)(*DAT_021a62a8 + 0x34),
                              *(undefined4 *)(*DAT_021a62a8 + 0x38));
  if ((uVar1 != 0) && (uVar1 != *(byte *)(*DAT_021a62a8 + 8))) {
    *(char *)(*DAT_021a62a8 + 8) = (char)uVar1;
    return 1;
  }
  return 0;
}

