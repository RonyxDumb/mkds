/* Decompiled C draft; module arm9; ROM address 020d49f0. No matching claim. */
#include "types.h"
#include "deps/020d49f0_func_020d49f0.h"

void func_020d49f0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,(uint)*(ushort *)(param_1 + 1) << 2);
  *param_1 = uVar1;
  *(undefined2 *)(param_1 + 1) = 0;
  return;
}

