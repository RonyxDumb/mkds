/* Decompiled C draft; module arm9_ov000; ROM address 021a524c. No matching claim. */
#include "types.h"
#include "deps/021a524c_FUN_021a524c.h"

void FUN_021a524c(int param_1)

{
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0:
    FUN_021a57fc(3);
    FUN_021a58a4(0,0,0,DAT_021a52a8);
    return;
  case 1:
    FUN_021a574c();
    return;
  default:
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,0,0,DAT_021a52ac);
    return;
  }
}

