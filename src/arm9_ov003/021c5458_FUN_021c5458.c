/* Decompiled C draft; module arm9_ov003; ROM address 021c5458. No matching claim. */
#include "types.h"
#include "deps/021c5458_FUN_021c5458.h"

void FUN_021c5458(void)

{
  FUN_021bf620(DAT_021c54b0,DAT_021c54b4);
  FUN_021bf620(DAT_021c54b8,DAT_021c54bc);
  FUN_021bf620(DAT_021c54c0,DAT_021c54c4);
  *DAT_021c54c8 = *DAT_021c54c8 & 0xfffc | 3;
  *DAT_021c54cc = *DAT_021c54cc & 0xfffc | 3;
  *DAT_021c54d0 = *DAT_021c54d0 & 0xfffc | 3;
  *DAT_021c54d4 = *DAT_021c54d4 & 0xfffc | 3;
  *DAT_021c54d8 = *DAT_021c54d8 & 0xfffc | 3;
  return;
}

