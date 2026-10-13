/* Decompiled C draft; module arm9; ROM address 020ea588. No matching claim. */
#include "types.h"
#include "deps/020ea588_func_020ea588.h"

void func_020ea588(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x6c);
  *param_1 = uVar1;
  Model_CreateFromNsbmd(*param_1,param_2);
  return;
}

