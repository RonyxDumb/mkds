/* Decompiled C draft; module arm9; ROM address 02017568. No matching claim. */
#include "types.h"
#include "deps/02017568_Mem_FinalizeHeapHead.h"

void Mem_FinalizeHeapHead(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_FindTopParentHeapHeadList();
  IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(uVar1),param_1);
  return;
}

