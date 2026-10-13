/* Decompiled C draft; module arm9_ov003; ROM address 021c4cd8. No matching claim. */
#include "types.h"
#include "deps/021c4cd8_FUN_021c4cd8.h"

void FUN_021c4cd8(void)

{
  FUN_021bf620(DAT_021c4d20,DAT_021c4d24);
  *DAT_021c4d28 = *DAT_021c4d28 & 0xfffc | 3;
  *DAT_021c4d2c = *DAT_021c4d2c & 0xfffc | 3;
  *DAT_021c4d30 = *DAT_021c4d30 & 0xfffc | 3;
  *DAT_021c4d34 = *DAT_021c4d34 & 0xfffc | 3;
  *DAT_021c4d38 = *DAT_021c4d38 & 0xfffc | 3;
  return;
}

