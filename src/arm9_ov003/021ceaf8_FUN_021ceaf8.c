/* Decompiled C draft; module arm9_ov003; ROM address 021ceaf8. No matching claim. */
#include "types.h"
#include "deps/021ceaf8_FUN_021ceaf8.h"

void FUN_021ceaf8(undefined4 param_1)

{
  undefined1 auStack_10 [4];
  int local_c;
  
  FUN_021d1770(*(undefined4 *)*DAT_021ceb48,0,(uint *)(void *)(auStack_10),&local_c);
  local_c = local_c + 0xc;
  FUN_021cec50();
  if (0xbf < local_c) {
    if (*(char *)(*DAT_021ceb48 + 0x1e) != '\0') {
      FUN_021d34e0(param_1,DAT_021ceb4c);
      return;
    }
    FUN_021d34e0(param_1,DAT_021ceb50);
  }
  return;
}

