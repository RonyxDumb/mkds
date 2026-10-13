/* Decompiled C draft; module arm9; ROM address 020067f0. No matching claim. */
#include "types.h"
#include "deps/020067f0_func_020067f0.h"

undefined4 func_020067f0(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20[0] = 3;
  local_1e = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  Mem_CpuCopy8(local_20,param_1,1);
  Mem_CpuCopy8(&local_1e,param_1 + 1,2);
  Mem_CpuCopy8(&uStack_8,param_1 + 3,1);
  Mem_CpuCopy8(&uStack_4,param_1 + 4,2);
  Mem_CpuCopy8(&stack0x00000000,param_1 + 6,2);
  Mem_CpuCopy8(&stack0x00000004,param_1 + 8,2);
  return 10;
}

