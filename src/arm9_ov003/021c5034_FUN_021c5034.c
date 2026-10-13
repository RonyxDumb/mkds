/* Decompiled C draft; module arm9_ov003; ROM address 021c5034. No matching claim. */
#include "types.h"
#include "deps/021c5034_FUN_021c5034.h"

void FUN_021c5034(void)

{
  FUN_021bf620(DAT_021c507c,DAT_021c5080);
  *DAT_021c5084 = *DAT_021c5084 & 0xfffc | 3;
  *DAT_021c5088 = *DAT_021c5088 & 0xfffc | 3;
  *DAT_021c508c = *DAT_021c508c & 0xfffc | 3;
  *DAT_021c5090 = *DAT_021c5090 & 0xfffc | 3;
  *DAT_021c5094 = *DAT_021c5094 & 0xfffc | 3;
  return;
}

