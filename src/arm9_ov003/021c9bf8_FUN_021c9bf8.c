/* Decompiled C draft; module arm9_ov003; ROM address 021c9bf8. No matching claim. */
#include "types.h"
#include "deps/021c9bf8_FUN_021c9bf8.h"

void FUN_021c9bf8(void)

{
  FUN_021bf620(DAT_021c9c40,DAT_021c9c44);
  *DAT_021c9c48 = *DAT_021c9c48 & 0xfffc | 3;
  *DAT_021c9c4c = *DAT_021c9c4c & 0xfffc | 3;
  *DAT_021c9c50 = *DAT_021c9c50 & 0xfffc | 3;
  *DAT_021c9c54 = *DAT_021c9c54 & 0xfffc | 3;
  *DAT_021c9c58 = *DAT_021c9c58 & 0xfffc | 3;
  return;
}

