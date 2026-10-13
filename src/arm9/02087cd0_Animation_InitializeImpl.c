/* Decompiled C draft; module arm9; ROM address 02087cd0. No matching claim. */
#include "types.h"
#include "deps/02087cd0_Animation_InitializeImpl.h"

void Animation_InitializeImpl(undefined2 *param_1,undefined4 param_2)

{
  *param_1 = 1;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 4) = 0x1000;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)(param_1 + 6) = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}

