/* Decompiled C draft; module arm9; ROM address 02006d3c. No matching claim. */
#include "types.h"
#include "deps/02006d3c_func_02006d3c.h"

undefined4 func_02006d3c(undefined2 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_a8 [2];
  undefined2 local_a0;
  undefined4 local_98;
  undefined1 auStack_94 [9];
  undefined1 local_8b;
  
  if ((-1 < param_3) && (param_3 < 10)) {
    local_a8[0] = 10;
    local_a0 = param_1;
    local_98 = param_4;
    Mem_CpuCopy8(param_2,auStack_94);
    local_8b = (undefined1)param_3;
    uVar1 = func_0200704c((undefined4)(uintptr_t)(local_a8));
    return uVar1;
  }
  return 0;
}

