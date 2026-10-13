/* Decompiled C draft; module arm9_ov000; ROM address 021a56e4. No matching claim. */
#include "types.h"
#include "deps/021a56e4_FUN_021a56e4.h"

void FUN_021a56e4(int param_1)

{
  if (((*(short *)(param_1 + 2) == 8) && (*(short *)(param_1 + 4) == 0x16)) &&
     (*(short *)(param_1 + 6) == 0x25)) {
    switch(*(undefined4 *)(*DAT_021a5744 + DAT_021a5748)) {
    case 8:
      FUN_021a57fc(0xc);
      return;
    case 9:
    case 0xc:
      FUN_021a574c();
      return;
    case 10:
      FUN_021a57fc(0xc);
    }
  }
  return;
}

