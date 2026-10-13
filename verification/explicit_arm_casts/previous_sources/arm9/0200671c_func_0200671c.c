/* Decompiled C draft; module arm9; ROM address 0200671c. No matching claim. */
#include "types.h"
#include "deps/0200671c_func_0200671c.h"

int func_0200671c(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  int iVar1;
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20[0] = 5;
  local_1e = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  Mem_CpuCopy8(local_20,param_1,1);
  Mem_CpuCopy8(&local_1e,param_1 + 1,2);
  Mem_CpuCopy8(&uStack_8,param_1 + 3,1);
  Mem_CpuCopy8(&uStack_4,param_1 + 4,4);
  Mem_CpuCopy8(&param_5,param_1 + 8,4);
  iVar1 = param_1 + 0xc;
  if (param_6 == 0) {
    Mem_CpuFill8(iVar1,0,param_7);
  }
  else {
    Mem_CpuCopy8(param_6,iVar1,param_7);
  }
  return (iVar1 + param_7) - param_1;
}

