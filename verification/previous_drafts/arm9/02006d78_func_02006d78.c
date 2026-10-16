/* Decompiled C draft; module arm9; ROM address 02006d78. No matching claim. */
#include "types.h"
#include "deps/02006d78_func_02006d78.h"

void func_02006d78(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  undefined4 local_a8 [2];
  undefined2 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 auStack_8c [64];
  undefined1 auStack_4c [68];
  
  local_a8[0] = 4;
  local_98 = param_6;
  local_a0 = param_1;
  local_94 = param_2;
  local_90 = param_4;
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_3),(undefined4 *)(void *)(auStack_8c),0x40);
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_5),(undefined4 *)(void *)(auStack_4c),0x40);
  func_0200704c((undefined4)(uintptr_t)(local_a8));
  return;
}

