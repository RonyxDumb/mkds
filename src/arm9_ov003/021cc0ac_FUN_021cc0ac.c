/* Decompiled C draft; module arm9_ov003; ROM address 021cc0ac. No matching claim. */
#include "types.h"
#include "deps/021cc0ac_FUN_021cc0ac.h"

void FUN_021cc0ac(void)

{
  FUN_021bf620(DAT_021cc0f4,DAT_021cc0f8);
  *DAT_021cc0fc = *DAT_021cc0fc & 0xfffc | 3;
  *DAT_021cc100 = *DAT_021cc100 & 0xfffc | 3;
  *DAT_021cc104 = *DAT_021cc104 & 0xfffc | 3;
  *DAT_021cc108 = *DAT_021cc108 & 0xfffc | 3;
  *DAT_021cc10c = *DAT_021cc10c & 0xfffc | 3;
  return;
}

