/* Decompiled C draft; module arm9; ROM address 02039e08. No matching claim. */
#include "types.h"
#include "deps/02039e08_AllocateHeapsAndBuffers.h"

undefined4
AllocateHeapsAndBuffers
          (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*psRam02039ee8 == 2) {
    uVar1 = Mem_CreateChildFrameHeapFromTail(param_1,0x19000);
    *param_2 = uVar1;
  }
  else {
    uVar1 = Mem_CreateChildFrameHeapFromTail(param_1,0x1b800);
    *param_2 = uVar1;
  }
  if (*psRam02039ee8 == 2) {
    uVar1 = Mem_CreateChildFrameHeapFromHead(param_1,0x19000);
    *param_4 = uVar1;
    uVar1 = Mem_CreateChildFrameHeapFromHead(param_1,0x4b000);
    *param_5 = uVar1;
    uVar1 = Mem_CreateChildFrameHeapFromHead(param_1,0x1b800);
    *param_6 = uVar1;
  }
  else {
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
  }
  if (*psRam02039ee8 == 2) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  uVar1 = GetSoundBufferAllocationSize(uVar1);
  uVar2 = Mem_AllocateHeap(param_1,uVar1);
  *param_3 = uVar2;
  Mem_GetExpHeapTotalFreeSize(param_1);
  return uVar1;
}

