/* Decompiled C draft; module arm9; ROM address 020a2e88. No matching claim. */
#include "types.h"
#include "deps/020a2e88_func_020a2e88.h"

void func_020a2e88(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(undefined4 *)(param_1 + 0xb0) = *param_2;
  *(undefined4 *)(param_1 + 0xb4) = uVar1;
  *(undefined4 *)(param_1 + 0xb8) = uVar2;
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  *(undefined4 *)(param_1 + 0xbc) = *param_3;
  *(undefined4 *)(param_1 + 0xc0) = uVar1;
  *(undefined4 *)(param_1 + 0xc4) = uVar2;
  return;
}

