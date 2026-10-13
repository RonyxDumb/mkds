/* Decompiled C draft; module arm9_ov003; ROM address 021cbd68. No matching claim. */
#include "types.h"
#include "deps/021cbd68_FUN_021cbd68.h"

void FUN_021cbd68(void)

{
  FUN_021bf620(DAT_021cbda4,DAT_021cbda8);
  *DAT_021cbdac = *DAT_021cbdac & 0xfffc | 3;
  *DAT_021cbdb0 = *DAT_021cbdb0 & 0xfffc | 3;
  *DAT_021cbdb4 = *DAT_021cbdb4 & 0xfffc | 3;
  *DAT_021cbdb8 = *DAT_021cbdb8 & 0xfffc | 3;
  return;
}

