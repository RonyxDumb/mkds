/* Decompiled C draft; module arm9_ov000; ROM address 02198748. No matching claim. */
#include "types.h"
#include "deps/02198748_FUN_02198748.h"

void FUN_02198748(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(int *)(param_1 + 0xc) == 4) {
    local_c = param_2;
    local_8 = param_3;
    uStack_4 = param_4;
    FUN_0219a61c(&local_c,&local_8);
    FUN_02198d9c(param_1,local_c,local_8);
    *(undefined4 *)(param_1 + 0xc) = 6;
  }
  return;
}

