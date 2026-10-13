/* Decompiled C draft; module arm9_ov003; ROM address 021ca864. No matching claim. */
#include "types.h"
#include "deps/021ca864_FUN_021ca864.h"

void FUN_021ca864(void)

{
  FUN_021bf620(DAT_021ca8bc,DAT_021ca8c0);
  FUN_021bf620(DAT_021ca8c4,DAT_021ca8c8);
  FUN_021bf620(DAT_021ca8cc,DAT_021ca8d0);
  *DAT_021ca8d4 = *DAT_021ca8d4 & 0xfffc | 3;
  *DAT_021ca8d8 = *DAT_021ca8d8 & 0xfffc | 3;
  *DAT_021ca8dc = *DAT_021ca8dc & 0xfffc | 3;
  *DAT_021ca8e0 = *DAT_021ca8e0 & 0xfffc | 3;
  *DAT_021ca8e4 = *DAT_021ca8e4 & 0xfffc | 3;
  return;
}

