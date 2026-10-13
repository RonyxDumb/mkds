/* Decompiled C draft; module arm9_ov003; ROM address 021c3348. No matching claim. */
#include "types.h"
#include "deps/021c3348_FUN_021c3348.h"

void FUN_021c3348(void)

{
  FUN_021bf620(DAT_021c3390,DAT_021c3394);
  *DAT_021c3398 = *DAT_021c3398 & 0xfffc | 3;
  *DAT_021c339c = *DAT_021c339c & 0xfffc | 3;
  *DAT_021c33a0 = *DAT_021c33a0 & 0xfffc | 3;
  *DAT_021c33a4 = *DAT_021c33a4 & 0xfffc | 3;
  *DAT_021c33a8 = *DAT_021c33a8 & 0xfffc | 3;
  return;
}

