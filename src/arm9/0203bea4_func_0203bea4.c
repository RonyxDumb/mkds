/* Decompiled C draft; module arm9; ROM address 0203bea4. No matching claim. */
#include "types.h"
#include "deps/0203bea4_func_0203bea4.h"

void func_0203bea4(int param_1,uint param_2,undefined4 param_3)

{
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | (byte)(1 << (param_2 & 0xff));
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}

