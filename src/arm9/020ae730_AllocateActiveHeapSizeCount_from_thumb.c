/* Decompiled C draft; module arm9; ROM address 020ae730. No matching claim. */
#include "types.h"
#include "deps/020ae730_AllocateActiveHeapSizeCount_from_thumb.h"

void AllocateActiveHeapSizeCount_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = GetActiveExecutionContextHeapHandle_1(0);
    Mem_AllocateHeap(uVar1,param_1 * param_2);
  }
  return;
}

