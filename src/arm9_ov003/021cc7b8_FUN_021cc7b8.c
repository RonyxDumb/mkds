/* Decompiled C draft; module arm9_ov003; ROM address 021cc7b8. No matching claim. */
#include "types.h"
#include "deps/021cc7b8_FUN_021cc7b8.h"

void FUN_021cc7b8(void)

{
  FUN_021bf620(DAT_021cc810,DAT_021cc814);
  FUN_021bf620(DAT_021cc818,DAT_021cc81c);
  FUN_021bf620(DAT_021cc820,DAT_021cc824);
  *DAT_021cc828 = *DAT_021cc828 & 0xfffc | 3;
  *DAT_021cc82c = *DAT_021cc82c & 0xfffc | 3;
  *DAT_021cc830 = *DAT_021cc830 & 0xfffc | 3;
  *DAT_021cc834 = *DAT_021cc834 & 0xfffc | 3;
  *DAT_021cc838 = *DAT_021cc838 & 0xfffc | 3;
  return;
}

