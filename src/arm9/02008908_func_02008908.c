/* Decompiled C draft; module arm9; ROM address 02008908. No matching claim. */
#include "types.h"
#include "deps/02008908_func_02008908.h"

void func_02008908(int param_1,undefined4 param_2,undefined4 param_3)

{
  Arm_FlushRange(param_3,param_1 + 0x1fU & 0xffffffe0);
  Mem_DcDrainWriteBuffer();
  func_020099d8(param_3,param_1,param_2);
  return;
}

