/* Decompiled C draft; module arm9; ROM address 02047220. No matching claim. */
#include "types.h"
#include "deps/02047220_ResizeActiveExecutionContextHeapHandle_from_thumb.h"

void ResizeActiveExecutionContextHeapHandle_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*piRam02047248 + iRam0204724c);
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  Mem_ResizeExpHeap(uVar1,iVar2,param_2 + (param_1 - iVar2));
  return;
}

