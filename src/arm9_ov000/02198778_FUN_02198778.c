/* Decompiled C draft; module arm9_ov000; ROM address 02198778. No matching claim. */
#include "types.h"
#include "deps/02198778_FUN_02198778.h"

undefined4 FUN_02198778(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(int *)(param_1 + 0xc) != 4) {
    return 0;
  }
  FUN_02198df8();
  *(undefined4 *)(param_1 + 0xc) = 5;
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = param_2[1];
    *(undefined4 *)(param_1 + 0x28) = *param_2;
    *(undefined4 *)(param_1 + 0x2c) = uVar1;
    uVar1 = param_2[3];
    *(undefined4 *)(param_1 + 0x30) = param_2[2];
    *(undefined4 *)(param_1 + 0x34) = uVar1;
  }
  return 1;
}

