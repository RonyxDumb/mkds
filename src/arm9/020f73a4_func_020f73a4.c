/* Decompiled C draft; module arm9; ROM address 020f73a4. No matching claim. */
#include "types.h"
#include "deps/020f73a4_func_020f73a4.h"

void func_020f73a4(void)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0xc);
  *puRam020f73d0 = uVar1;
  return;
}

