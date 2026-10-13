/* Decompiled C draft; module arm9; ROM address 0203be88. No matching claim. */
#include "types.h"
#include "deps/0203be88_func_0203be88.h"

void func_0203be88(byte *param_1,uint param_2,undefined4 param_3)

{
  *param_1 = *param_1 | (byte)(1 << (param_2 & 0xff));
  *(undefined4 *)(param_1 + param_2 * 4 + 0x24) = param_3;
  return;
}

