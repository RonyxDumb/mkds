/* Decompiled C draft; module arm9; ROM address 020e64b8. No matching claim. */
#include "types.h"
#include "deps/020e64b8_BillboardModel_CreateFromNsbmdNsbtp_from_thumb.h"

void BillboardModel_CreateFromNsbmdNsbtp_from_thumb(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x6c);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  Model_CreateFromNsbmd(*(undefined4 *)(param_1 + 0x24),param_2);
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  else {
    GetActiveExecutionContext();
    uVar1 = ExecutionContext_GetHeapHandle();
    uVar1 = Mem_AllocateHeap(uVar1,0x38);
    *(undefined4 *)(param_1 + 0x28) = uVar1;
    SomeAnimationLoadWrapper_from_thumb
              (2,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),param_2,param_3);
  }
  func_020e6514(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),param_1);
  return;
}

