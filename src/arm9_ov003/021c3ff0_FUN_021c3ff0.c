/* Decompiled C draft; module arm9_ov003; ROM address 021c3ff0. No matching claim. */
#include "types.h"
#include "deps/021c3ff0_FUN_021c3ff0.h"

void FUN_021c3ff0(void)

{
  FUN_021bf620(DAT_021c4038,DAT_021c403c);
  *DAT_021c4040 = *DAT_021c4040 & 0xfffc | 3;
  *DAT_021c4044 = *DAT_021c4044 & 0xfffc | 3;
  *DAT_021c4048 = *DAT_021c4048 & 0xfffc | 3;
  *DAT_021c404c = *DAT_021c404c & 0xfffc | 3;
  *DAT_021c4050 = *DAT_021c4050 & 0xfffc | 3;
  return;
}

