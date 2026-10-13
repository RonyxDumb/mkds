/* Decompiled C draft; module arm9_ov003; ROM address 021c98d0. No matching claim. */
#include "types.h"
#include "deps/021c98d0_FUN_021c98d0.h"

void FUN_021c98d0(void)

{
  FUN_021bf620(DAT_021c991c,DAT_021c9920);
  FUN_021bf620(DAT_021c9924,DAT_021c9928);
  FUN_021bf620(DAT_021c992c,DAT_021c9930);
  *DAT_021c9934 = *DAT_021c9934 & 0xfffc | 3;
  *DAT_021c9938 = *DAT_021c9938 & 0xfffc | 3;
  *DAT_021c993c = *DAT_021c993c & 0xfffc | 3;
  *DAT_021c9940 = *DAT_021c9940 & 0xfffc | 3;
  return;
}

