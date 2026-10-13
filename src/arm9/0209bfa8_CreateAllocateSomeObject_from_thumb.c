/* Decompiled C draft; module arm9; ROM address 0209bfa8. No matching claim. */
#include "types.h"
#include "deps/0209bfa8_CreateAllocateSomeObject_from_thumb.h"

void CreateAllocateSomeObject_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               ushort param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  puVar2 = (undefined4 *)Mem_AllocateHeap(uVar1,0x40);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[8] = param_4;
  puVar2[7] = (uint)param_5;
  puVar2[6] = param_3;
  return;
}

