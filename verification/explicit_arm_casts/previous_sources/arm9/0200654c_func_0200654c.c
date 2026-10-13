/* Decompiled C draft; module arm9; ROM address 0200654c. No matching claim. */
#include "types.h"
#include "deps/0200654c_func_0200654c.h"

undefined4 func_0200654c(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_28 [2];
  undefined2 local_26 [3];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_28[0] = 10;
  local_26[0] = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  Mem_CpuCopy8(local_28,param_1,1);
  Mem_CpuCopy8(local_26,param_1 + 1,2);
  Mem_CpuCopy8(&uStack_8,param_1 + 3,1);
  Mem_CpuCopy8(&stack0x00000000,param_1 + 4,1);
  Mem_CpuCopy8(param_4,param_1 + 5,9);
  return 0xe;
}

