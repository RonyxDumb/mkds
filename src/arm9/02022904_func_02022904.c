/* Decompiled C draft; module arm9; ROM address 02022904. No matching claim. */
#include "types.h"
#include "deps/02022904_func_02022904.h"

void func_02022904(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x30) = param_3;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  func_02022474((undefined4 *)(uintptr_t)(param_1 + 0x38),1);
  func_020220b0((undefined4 *)(uintptr_t)(param_1));
  func_020228e8(param_1,param_2);
  return;
}

