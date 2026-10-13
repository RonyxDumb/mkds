/* Decompiled C draft; module arm9_ov000; ROM address 02198514. No matching claim. */
#include "types.h"
#include "deps/02198514_FUN_02198514.h"

void FUN_02198514(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0xc) != 7) {
    *(undefined4 *)(param_1 + 0xc) = 7;
    local_10 = param_1;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    FUN_0218de8c(*(undefined4 *)(*(int *)(param_1 + 8) + 0xc),&local_10);
    FUN_0218dbc0(*(undefined4 *)(*(int *)(local_10 + 8) + 0x10),&local_10);
  }
  return;
}

