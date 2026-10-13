/* Decompiled C draft; module arm9_ov003; ROM address 021c47b0. No matching claim. */
#include "types.h"
#include "deps/021c47b0_FUN_021c47b0.h"

void FUN_021c47b0(void)

{
  FUN_021bf620(DAT_021c47ec,DAT_021c47f0);
  *DAT_021c47f4 = *DAT_021c47f4 & 0xfffc | 3;
  *DAT_021c47f8 = *DAT_021c47f8 & 0xfffc | 3;
  *DAT_021c47fc = *DAT_021c47fc & 0xfffc | 3;
  *DAT_021c4800 = *DAT_021c4800 & 0xfffc | 3;
  return;
}

