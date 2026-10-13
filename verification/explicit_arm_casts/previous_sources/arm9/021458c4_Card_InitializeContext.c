/* Decompiled C draft; module arm9; ROM address 021458c4. No matching claim. */
#include "types.h"
#include "deps/021458c4_Card_InitializeContext.h"

void Card_InitializeContext(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  puVar2 = puRam021459ac;
  puRam021459ac[2] = 0xfffffffd;
  puVar2[3] = 0;
  uVar3 = uRam021459b0;
  puVar2[6] = 0;
  *puVar2 = uVar3;
  Mem_CpuFastMemorySet(0,uVar3,0x40);
  Arm_FlushRange(uRam021459b0,0x40);
  if (*psRam021459b4 != 2) {
    Mem_CpuCopy8(uRam021459b8,uRam021459bc,0x160);
  }
  puVar2[5] = 0;
  uVar1 = (uint)(puVar2 + 5) & 3;
  uVar4 = *(uint *)((uint)(puVar2 + 5) & 0xfffffffc);
  puVar2[4] = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  puVar2[0x44] = 0;
  uVar1 = (uint)(puVar2 + 0x44) & 3;
  uVar4 = *(uint *)((uint)(puVar2 + 0x44) & 0xfffffffc);
  puVar2[0x43] = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  puVar2[0x42] = 4;
  uVar1 = (uint)(puVar2 + 0x42) & 3;
  uVar4 = *(uint *)((uint)(puVar2 + 0x42) & 0xfffffffc);
  Os_Thread_Create(puVar2 + 0x11,uRam021459c0,0,uRam021459c4,0x400,
                   uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  Os_Thread_WakeUpDirect(puVar2 + 0x11);
  Fifo_RegisterHandler(0xb,uRam021459c8);
  if (*psRam021459b4 != 2) {
    Card_SetEnabled(1);
    return;
  }
  return;
}

