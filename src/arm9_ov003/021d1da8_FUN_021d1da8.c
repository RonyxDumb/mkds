/* Decompiled C draft; module arm9_ov003; ROM address 021d1da8. No matching claim. */
#include "types.h"
#include "deps/021d1da8_FUN_021d1da8.h"

void FUN_021d1da8(undefined4 param_1,int param_2)

{
  *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + 1;
  if ((int)(uint)*(ushort *)(param_2 + 6) <= (int)*(short *)(param_2 + 4)) {
    *(undefined1 *)(param_2 + 9) = 0;
    FUN_021d34c8(1,param_1);
  }
  return;
}

