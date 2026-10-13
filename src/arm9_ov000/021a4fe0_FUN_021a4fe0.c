/* Decompiled C draft; module arm9_ov000; ROM address 021a4fe0. No matching claim. */
#include "types.h"
#include "deps/021a4fe0_FUN_021a4fe0.h"

void FUN_021a4fe0(int param_1)

{
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0:
    break;
  case 1:
  case 3:
    FUN_021a57fc(10);
    FUN_021a574c();
    return;
  default:
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,*DAT_021a5070 + DAT_021a507c,0,DAT_021a5084);
    return;
  }
  if (*(int *)(*DAT_021a5070 + DAT_021a5074) == 0xc) {
    FUN_021a57fc(10);
    FUN_021a574c();
    return;
  }
  *(undefined2 *)(*DAT_021a5070 + DAT_021a5078) = 0;
  FUN_021a57fc(3);
  FUN_021a58a4(0,*DAT_021a5070 + DAT_021a507c,0,DAT_021a5080);
  return;
}

