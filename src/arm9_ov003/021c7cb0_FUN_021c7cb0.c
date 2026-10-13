/* Decompiled C draft; module arm9_ov003; ROM address 021c7cb0. No matching claim. */
#include "types.h"
#include "deps/021c7cb0_FUN_021c7cb0.h"

void FUN_021c7cb0(void)

{
  FUN_021bf620(DAT_021c7cf8,DAT_021c7cfc);
  *DAT_021c7d00 = *DAT_021c7d00 & 0xfffc | 3;
  *DAT_021c7d04 = *DAT_021c7d04 & 0xfffc | 3;
  *DAT_021c7d08 = *DAT_021c7d08 & 0xfffc | 3;
  *DAT_021c7d0c = *DAT_021c7d0c & 0xfffc | 3;
  *DAT_021c7d10 = *DAT_021c7d10 & 0xfffc | 3;
  return;
}

