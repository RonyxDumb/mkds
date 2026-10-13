/* Decompiled C draft; module arm9_ov003; ROM address 021c6da4. No matching claim. */
#include "types.h"
#include "deps/021c6da4_FUN_021c6da4.h"

void FUN_021c6da4(void)

{
  FUN_021bf620(DAT_021c6e04,DAT_021c6e08);
  FUN_021bf620(DAT_021c6e0c,DAT_021c6e10);
  FUN_021bf620(DAT_021c6e14,DAT_021c6e18);
  FUN_021bf620(DAT_021c6e1c,DAT_021c6e20);
  *DAT_021c6e24 = *DAT_021c6e24 & 0xfffc | 3;
  *DAT_021c6e28 = *DAT_021c6e28 & 0xfffc | 3;
  *DAT_021c6e2c = *DAT_021c6e2c & 0xfffc | 2;
  *DAT_021c6e30 = *DAT_021c6e30 & 0xfffc | 3;
  *DAT_021c6e34 = *DAT_021c6e34 & 0xfffc | 3;
  return;
}

