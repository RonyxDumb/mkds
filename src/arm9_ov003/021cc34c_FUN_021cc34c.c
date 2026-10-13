/* Decompiled C draft; module arm9_ov003; ROM address 021cc34c. No matching claim. */
#include "types.h"
#include "deps/021cc34c_FUN_021cc34c.h"

void FUN_021cc34c(void)

{
  FUN_021bf620(DAT_021cc3a4,DAT_021cc3a8);
  FUN_021bf620(DAT_021cc3ac,DAT_021cc3b0);
  FUN_021bf620(DAT_021cc3b4,DAT_021cc3b8);
  *DAT_021cc3bc = *DAT_021cc3bc & 0xfffc | 3;
  *DAT_021cc3c0 = *DAT_021cc3c0 & 0xfffc | 3;
  *DAT_021cc3c4 = *DAT_021cc3c4 & 0xfffc | 3;
  *DAT_021cc3c8 = *DAT_021cc3c8 & 0xfffc | 3;
  *DAT_021cc3cc = *DAT_021cc3cc & 0xfffc | 3;
  return;
}

