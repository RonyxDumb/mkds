/* Decompiled C draft; module arm9_ov003; ROM address 021c460c. No matching claim. */
#include "types.h"
#include "deps/021c460c_FUN_021c460c.h"

void FUN_021c460c(void)

{
  FUN_021bf620(DAT_021c4654,DAT_021c4658);
  *DAT_021c465c = *DAT_021c465c & 0xfffc | 3;
  *DAT_021c4660 = *DAT_021c4660 & 0xfffc | 3;
  *DAT_021c4664 = *DAT_021c4664 & 0xfffc | 3;
  *DAT_021c4668 = *DAT_021c4668 & 0xfffc | 3;
  *DAT_021c466c = *DAT_021c466c & 0xfffc | 3;
  return;
}

