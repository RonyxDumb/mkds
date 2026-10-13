/* Decompiled C draft; module arm9; ROM address 020e6f9c. No matching claim. */
#include "types.h"
#include "deps/020e6f9c_func_020e6f9c.h"

void func_020e6f9c(undefined4 *param_1)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,(uint)*(ushort *)(param_1 + 1) << 2);
  *param_1 = uVar1;
  *(undefined2 *)(param_1 + 1) = 0;
  param_1[6] = 3;
  param_1[7] = 0;
  param_1[8] = 3;
  return;
}

