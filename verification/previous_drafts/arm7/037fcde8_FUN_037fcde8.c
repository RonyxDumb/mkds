/* Decompiled C draft; module arm7; ROM address 037fcde8. No matching claim. */
#include "types.h"
#include "deps/037fcde8_FUN_037fcde8.h"

undefined4 FUN_037fcde8(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *(undefined1 *)(param_1 + 1) = 0;
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = *param_2;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  *(undefined4 *)(param_1 + 0x44) = param_3;
  FUN_037fc5e4(param_1,param_4);
  return 1;
}

