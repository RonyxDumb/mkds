/* Decompiled C draft; module arm9; ROM address 02006648. No matching claim. */
#include "types.h"
#include "deps/02006648_func_02006648.h"

int func_02006648(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  int iVar1;
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20[0] = 7;
  local_1e = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  Mem_CpuCopy8((ushort *)(void *)(local_20),(uint *)(uintptr_t)(param_1),1);
  Mem_CpuCopy8(&local_1e,(uint *)(uintptr_t)(param_1 + 1),2);
  Mem_CpuCopy8((ushort *)(void *)(&uStack_8),(uint *)(uintptr_t)(param_1 + 3),1);
  Mem_CpuCopy8((ushort *)(void *)(&uStack_4),(uint *)(uintptr_t)(param_1 + 4),4);
  Mem_CpuCopy8((ushort *)(void *)(&param_5),(uint *)(uintptr_t)(param_1 + 8),4);
  iVar1 = param_1 + 0xc;
  if (param_6 == 0) {
    Mem_CpuFill8((uint *)(uintptr_t)(iVar1),0,param_7);
  }
  else {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_6),(uint *)(uintptr_t)(iVar1),param_7);
  }
  return (iVar1 + param_7) - param_1;
}

