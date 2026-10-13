/* Decompiled C draft; module arm9; ROM address 020d12b0. No matching claim. */
#include "types.h"
#include "deps/020d12b0_SomeAlloc2.h"

void SomeAlloc2(void)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,4);
  *puRam020d12dc = uVar1;
  return;
}

