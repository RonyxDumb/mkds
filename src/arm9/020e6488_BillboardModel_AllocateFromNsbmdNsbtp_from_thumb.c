/* Decompiled C draft; module arm9; ROM address 020e6488. No matching claim. */
#include "types.h"
#include "deps/020e6488_BillboardModel_AllocateFromNsbmdNsbtp_from_thumb.h"

void BillboardModel_AllocateFromNsbmdNsbtp_from_thumb
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x2c);
  *param_1 = uVar1;
  BillboardModel_CreateFromNsbmdNsbtp_from_thumb(*param_1,param_2,param_3,param_4);
  return;
}

