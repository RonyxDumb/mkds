/* Decompiled C draft; module arm9_ov001; ROM address 021886f8. No matching claim. */
#include "types.h"
#include "deps/021886f8_FUN_021886f8.h"

void FUN_021886f8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  if (param_5 == 0) {
    *(undefined4 *)(param_1 + DAT_02188738) = 0;
  }
  else {
    *(undefined4 *)(param_1 + DAT_02188738) = 2;
  }
  *(undefined4 *)(param_1 + DAT_0218873c) = 0;
  *(undefined4 *)(param_1 + DAT_02188740) = param_2;
  *(undefined4 *)(param_1 + DAT_02188744) = 0;
  *(undefined4 *)(param_1 + DAT_02188748) = param_3;
  *(undefined4 *)(param_1 + DAT_0218874c) = param_4;
  *(int *)(param_1 + DAT_02188750) = param_5;
  *(undefined4 *)(param_1 + DAT_02188754) = param_4;
  *(undefined4 *)(param_1 + DAT_02188758) = param_6;
  return;
}

