/* Decompiled C draft; module arm9_ov003; ROM address 021c76b4. No matching claim. */
#include "types.h"
#include "deps/021c76b4_FUN_021c76b4.h"

void FUN_021c76b4(void)

{
  FUN_021bf620(DAT_021c7714,DAT_021c7718);
  FUN_021bf620(DAT_021c771c,DAT_021c7720);
  FUN_021bf620(DAT_021c7724,DAT_021c7728);
  FUN_021bf620(DAT_021c772c,DAT_021c7730);
  *DAT_021c7734 = *DAT_021c7734 & 0xfffc | 3;
  *DAT_021c7738 = *DAT_021c7738 & 0xfffc | 3;
  *DAT_021c773c = *DAT_021c773c & 0xfffc | 2;
  *DAT_021c7740 = *DAT_021c7740 & 0xfffc | 3;
  *DAT_021c7744 = *DAT_021c7744 & 0xfffc | 3;
  return;
}

