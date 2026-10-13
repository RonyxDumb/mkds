/* Decompiled C draft; module arm9; ROM address 02057ed8. No matching claim. */
#include "types.h"
#include "deps/02057ed8_InitializeWorker.h"

void InitializeWorker(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  uint uVar4;
  
  uVar2 = Mem_AllocateHeap(param_1,0xfc);
  *puRam02057f84 = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x800,0x20);
  puVar1 = puRam02057f84;
  *(undefined4 *)
   ((*(uint *)((uint)puRam02057f84 & 0xfffffffc) >> ((uint)puRam02057f84 & 3) * 8 |
    *(uint *)((uint)puRam02057f84 & 0xfffffffc) << ((uint)puRam02057f84 & 3) * -8 + 0x20) + 0xf4) =
       uVar2;
  uVar5 = (uint)puVar1 & 3;
  uVar3 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 + 0xf4;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  Os_Thread_Create(uVar4 + 0x2c,uRam02057f88,0,
                   (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x800,0x800,0x11);
  Os_Thread_WakeUpDirect
            ((*(uint *)((uint)puRam02057f84 & 0xfffffffc) >> ((uint)puRam02057f84 & 3) * 8 |
             *(uint *)((uint)puRam02057f84 & 0xfffffffc) << ((uint)puRam02057f84 & 3) * -8 + 0x20) +
             0x2c);
  puVar1 = puRam02057f84;
  iVar6 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puRam02057f84 & 0xfffffffc) >> ((uint)puRam02057f84 & 3) * 8 |
    *(uint *)((uint)puRam02057f84 & 0xfffffffc) << ((uint)puRam02057f84 & 3) * -8 + 0x20) + 0xf8) =
       0;
  uVar5 = (uint)puVar1 & 3;
  uVar3 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  do {
    *(undefined4 *)(uVar5 + iVar6 * 4) = 0;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 10);
  *(undefined1 *)(uVar5 + 0x28) = 0;
  return;
}

