/* Decompiled C draft; module arm9; ROM address 020ea55c. No matching claim. */
#include "types.h"
#include "deps/020ea55c_func_020ea55c.h"

void func_020ea55c(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x74);
  *param_1 = uVar1;
  StructAD00Sh_SomeFn_2(*param_1,param_2,param_3);
  return;
}

