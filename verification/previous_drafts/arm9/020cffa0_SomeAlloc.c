/* Decompiled C draft; module arm9; ROM address 020cffa0. No matching claim. */
#include "types.h"
#include "deps/020cffa0_SomeAlloc.h"

void SomeAlloc(void)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x38);
  *puRam020cffcc = uVar1;
  return;
}

