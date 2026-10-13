/* Decompiled C draft; module arm9_ov000; ROM address 021863cc. No matching claim. */
#include "types.h"
#include "deps/021863cc_FUN_021863cc.h"

undefined4 FUN_021863cc(void)

{
  undefined4 uVar1;
  
  if (*DAT_021863fc == 0) {
    return 0x15;
  }
  func_0x0200ed34(*DAT_021863fc + DAT_02186400);
  uVar1 = *(undefined4 *)(*DAT_021863fc + 4);
  func_0x0200ecc4(*DAT_021863fc + DAT_02186400);
  return uVar1;
}

