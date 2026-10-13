/* Decompiled C draft; module arm9; ROM address 020e0650. No matching claim. */
#include "types.h"
#include "deps/020e0650_AllocateNewDriverSub208.h"

void AllocateNewDriverSub208(undefined4 *param_1)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x1c);
  *param_1 = uVar1;
  *(undefined4 *)
   (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) = 0;
  return;
}

