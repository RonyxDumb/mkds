/* Decompiled C draft; module arm9_ov003; ROM address 021c4a40. No matching claim. */
#include "types.h"
#include "deps/021c4a40_FUN_021c4a40.h"

void FUN_021c4a40(void)

{
  FUN_021bf620(DAT_021c4a88,DAT_021c4a8c);
  *DAT_021c4a90 = *DAT_021c4a90 & 0xfffc | 3;
  *DAT_021c4a94 = *DAT_021c4a94 & 0xfffc | 3;
  *DAT_021c4a98 = *DAT_021c4a98 & 0xfffc | 3;
  *DAT_021c4a9c = *DAT_021c4a9c & 0xfffc | 3;
  *DAT_021c4aa0 = *DAT_021c4aa0 & 0xfffc | 3;
  return;
}

