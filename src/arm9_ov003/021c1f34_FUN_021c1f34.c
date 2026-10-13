/* Decompiled C draft; module arm9_ov003; ROM address 021c1f34. No matching claim. */
#include "types.h"
#include "deps/021c1f34_FUN_021c1f34.h"

undefined4 FUN_021c1f34(void)

{
  int iVar1;
  
  iVar1 = func_ov003_021ba05c(*DAT_021c1f78);
  if (iVar1 == 0) {
    *DAT_021c1f7c = 1;
    return 1;
  }
  if ((*(char *)(*DAT_021c1f78 + DAT_021c1f80) != '\x01') &&
     (2 < (byte)(*(char *)(*DAT_021c1f78 + DAT_021c1f80) - 3U))) {
    return 2;
  }
  return 0;
}

