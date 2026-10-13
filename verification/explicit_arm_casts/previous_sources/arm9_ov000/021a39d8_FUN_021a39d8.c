/* Decompiled C draft; module arm9_ov000; ROM address 021a39d8. No matching claim. */
#include "types.h"
#include "deps/021a39d8_FUN_021a39d8.h"

void FUN_021a39d8(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*DAT_021a3a10 == 0) {
    func_0x0214d168(param_1,0,0xc);
    *(undefined2 *)(param_1 + 8) = param_2;
    *(undefined2 *)(param_1 + 10) = 1;
    *(undefined2 *)(param_1 + 4) = 1;
    *(undefined2 *)(param_1 + 6) = 0;
    *DAT_021a3a10 = param_1;
    FUN_021a397c();
    *DAT_021a3a14 = param_4;
  }
  return;
}

