/* Decompiled C draft; module arm9_ov003; ROM address 021c9f70. No matching claim. */
#include "types.h"
#include "deps/021c9f70_FUN_021c9f70.h"

void FUN_021c9f70(void)

{
  FUN_021bf620(DAT_021c9fb8,DAT_021c9fbc);
  *DAT_021c9fc0 = *DAT_021c9fc0 & 0xfffc | 3;
  *DAT_021c9fc4 = *DAT_021c9fc4 & 0xfffc | 3;
  *DAT_021c9fc8 = *DAT_021c9fc8 & 0xfffc | 3;
  *DAT_021c9fcc = *DAT_021c9fcc & 0xfffc | 3;
  *DAT_021c9fd0 = *DAT_021c9fd0 & 0xfffc | 3;
  return;
}

