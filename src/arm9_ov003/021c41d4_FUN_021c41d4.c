/* Decompiled C draft; module arm9_ov003; ROM address 021c41d4. No matching claim. */
#include "types.h"
#include "deps/021c41d4_FUN_021c41d4.h"

void FUN_021c41d4(void)

{
  *DAT_021c420c = *DAT_021c420c & 0xfffc | 3;
  *DAT_021c4210 = *DAT_021c4210 & 0xfffc | 3;
  *DAT_021c4214 = *DAT_021c4214 & 0xfffc | 3;
  *DAT_021c4218 = *DAT_021c4218 & 0xfffc | 3;
  *DAT_021c421c = *DAT_021c421c & 0xfffc | 3;
  return;
}

