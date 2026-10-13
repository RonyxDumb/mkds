/* Decompiled C draft; module arm9; ROM address 020c5ce0. No matching claim. */
#include "types.h"
#include "deps/020c5ce0_CreateGlobalB3F0.h"

/* WARNING: Removing unreachable block (ram,0x020c5d48) */
/* WARNING: Removing unreachable block (ram,0x020c5d5c) */

void CreateGlobalB3F0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x1c);
  puVar2 = puRam020c5da8;
  *puRam020c5da8 = puVar4;
  *puVar4 = 1;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 4) = 0;
  uVar5 = uRam020c5dac;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 8) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined2 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x10) = 0;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar1 = uVar5 + 8 & 3;
  uVar7 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  if ((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) == 4) {
    iVar6 = IsMissionStageBeaten
                      ((int)*(char *)(uVar5 + 0x54),(int)*(char *)(uVar5 + 0x55),
                       (uint *)(uintptr_t)((*(uint *)((uint)puRam020c5da8 & 0xfffffffc) >> ((uint)puRam020c5da8 & 3) * 8
                       | *(uint *)((uint)puRam020c5da8 & 0xfffffffc) <<
                         ((uint)puRam020c5da8 & 3) * -8 + 0x20) + 0x14));
    if (iVar6 == 0) {
      *(undefined4 *)
       ((*(uint *)((uint)puRam020c5da8 & 0xfffffffc) >> ((uint)puRam020c5da8 & 3) * 8 |
        *(uint *)((uint)puRam020c5da8 & 0xfffffffc) << ((uint)puRam020c5da8 & 3) * -8 + 0x20) + 0x14
       ) = 9;
    }
  }
  else {
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x14) = 9;
  }
  *(undefined4 *)
   ((*(uint *)((uint)puRam020c5da8 & 0xfffffffc) >> ((uint)puRam020c5da8 & 3) * 8 |
    *(uint *)((uint)puRam020c5da8 & 0xfffffffc) << ((uint)puRam020c5da8 & 3) * -8 + 0x20) + 0x18) =
       9;
  return;
}

