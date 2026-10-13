/* Decompiled C draft; module arm9; ROM address 0205dee0. No matching claim. */
#include "types.h"
#include "deps/0205dee0_LoadExecuteOverlay1.h"

void LoadExecuteOverlay1(void)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  WaitForWorkerTask();
  uVar4 = (*(uint *)(uRam0205e06c & 0xfffffffc) >> (uRam0205e06c & 3) * 8 |
          *(uint *)(uRam0205e06c & 0xfffffffc) << (uRam0205e06c & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
    func_02145d38();
  }
  if ((*psRam0205e070 != 2) &&
     (uVar4 = (*(uint *)(uRam0205e074 & 0xfffffffc) >> (uRam0205e074 & 3) * 8 |
              *(uint *)(uRam0205e074 & 0xfffffffc) << (uRam0205e074 & 3) * -8 + 0x20) + 0xc,
     uVar1 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0)) {
    DisposeSomeSoundStuff();
    uVar4 = (*(uint *)(uRam0205e074 & 0xfffffffc) >> (uRam0205e074 & 3) * 8 |
            *(uint *)(uRam0205e074 & 0xfffffffc) << (uRam0205e074 & 3) * -8 + 0x20) + 0xc;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    Mem_FreeHeap(uVar3,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    *(undefined4 *)
     ((*(uint *)(uRam0205e074 & 0xfffffffc) >> (uRam0205e074 & 3) * 8 |
      *(uint *)(uRam0205e074 & 0xfffffffc) << (uRam0205e074 & 3) * -8 + 0x20) + 0xc) = 0;
  }
  func_02108ed8();
  uVar5 = Mem_CreateChildExpHeap(uVar3);
  uVar6 = Mem_AllocateHeapAligned(uVar5,0x40000,0x20);
  uVar8 = uRam0205e078;
  iVar7 = Fs_LoadOverlay(0,uRam0205e078);
  if (iVar7 != 0) {
    Os_SetIrqHandler(1,0);
    Os_DisableIrqHandler(1);
    uVar2 = *puRam0205e07c;
    *puRam0205e07c = 0;
    Os_DisableIrq(0,uVar2);
    GX_VBlankIntr(0);
    func_0x021a397c(2);
    uVar9 = 1;
    uVar4 = (*(uint *)(uRam0205e080 & 0xfffffffc) >> (uRam0205e080 & 3) * 8 |
            *(uint *)(uRam0205e080 & 0xfffffffc) << (uRam0205e080 & 3) * -8 + 0x20) + 4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xff;
    if (uVar4 < 6) {
      uVar9 = *(undefined1 *)(iRam0205e084 + uVar4);
    }
    func_0x021c2494(uVar6,uVar9,0);
    EnableVblankIRQ();
    Fs_UnloadOverlay(0,uVar8);
  }
  Mem_DestroyHeap(uVar5);
  SetBrightness(uRam0205e088,0x10);
  SetBrightness(uRam0205e08c,0x10);
  EnableGreenSwap();
  SetGlobalSdatActive();
  uVar8 = ComputeRAudioBufferAllocSize(1);
  uVar3 = Mem_AllocateHeap(uVar3,uVar8);
  SomeAudioInit(1,uVar3);
  *(undefined4 *)
   ((*(uint *)(uRam0205e074 & 0xfffffffc) >> (uRam0205e074 & 3) * 8 |
    *(uint *)(uRam0205e074 & 0xfffffffc) << (uRam0205e074 & 3) * -8 + 0x20) + 0xc) = uVar3;
  return;
}

