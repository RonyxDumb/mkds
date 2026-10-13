/* Decompiled C draft; module arm9_ov003; ROM address 021ca480. No matching claim. */
#include "types.h"
#include "deps/021ca480_FUN_021ca480.h"

void FUN_021ca480(void)

{
  FUN_021bf620(DAT_021ca4d8,DAT_021ca4dc);
  FUN_021bf620(DAT_021ca4e0,DAT_021ca4e4);
  FUN_021bf620(DAT_021ca4e8,DAT_021ca4ec);
  *DAT_021ca4f0 = *DAT_021ca4f0 & 0xfffc | 3;
  *DAT_021ca4f4 = *DAT_021ca4f4 & 0xfffc | 3;
  *DAT_021ca4f8 = *DAT_021ca4f8 & 0xfffc | 3;
  *DAT_021ca4fc = *DAT_021ca4fc & 0xfffc | 3;
  *DAT_021ca500 = *DAT_021ca500 & 0xfffc | 3;
  return;
}

