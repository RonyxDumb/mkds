/* Decompiled C draft; module arm9; ROM address 0205e0b0. No matching claim. */
#include "types.h"
#include "deps/0205e0b0_func_0205e0b0.h"

void func_0205e0b0(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int unaff_r5;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar2 = *(uint *)(uRam0205e178 & 0xfffffffc) >> (uRam0205e178 & 3) * 8 |
          *(uint *)(uRam0205e178 & 0xfffffffc) << (uRam0205e178 & 3) * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    if (*psRam0205e17c == 2) {
      unaff_r5 = 2;
    }
    else {
      unaff_r5 = 0;
      UpdateOverlayStatusWithKind(1);
      WaitOverlayLoadedStarted();
    }
    InitializeSomeZEPointers(uVar1);
  }
  else if (uVar3 == 1) {
    unaff_r5 = 1;
    UpdateOverlayStatusWithKind(0);
    WaitOverlayLoadedStarted();
    CreateStructBHeap_from_thumb(uVar1);
  }
  if (unaff_r5 == 2) {
    return;
  }
  uVar4 = ComputeRAudioBufferAllocSize(unaff_r5);
  uVar1 = Mem_AllocateHeap(uVar1,uVar4);
  SomeAudioInit(unaff_r5,uVar1);
  *(undefined4 *)
   ((*(uint *)(uRam0205e178 & 0xfffffffc) >> (uRam0205e178 & 3) * 8 |
    *(uint *)(uRam0205e178 & 0xfffffffc) << (uRam0205e178 & 3) * -8 + 0x20) + 0xc) = uVar1;
  return;
}

