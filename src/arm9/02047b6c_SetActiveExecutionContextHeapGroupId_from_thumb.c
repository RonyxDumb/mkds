/* Decompiled C draft; module arm9; ROM address 02047b6c. No matching claim. */
#include "types.h"
#include "deps/02047b6c_SetActiveExecutionContextHeapGroupId_from_thumb.h"

void SetActiveExecutionContextHeapGroupId_from_thumb(undefined2 param_1)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  Mem_SetExpHeapGroupId(uVar1,param_1);
  return;
}

