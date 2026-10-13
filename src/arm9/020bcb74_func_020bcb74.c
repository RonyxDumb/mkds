/* Decompiled C draft; module arm9; ROM address 020bcb74. No matching claim. */
#include "types.h"
#include "deps/020bcb74_func_020bcb74.h"

void func_020bcb74(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x14);
  puVar2 = puRam020bcbe4;
  *puRam020bcbe4 = puVar4;
  *puVar4 = 0;
  uVar1 = (uint)puVar2 & 3;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 4) = 0;
  iVar6 = GetCurrentLapCount();
  puVar2 = puRam020bcbe4;
  *(uint *)((*(uint *)((uint)puRam020bcbe4 & 0xfffffffc) >> ((uint)puRam020bcbe4 & 3) * 8 |
            *(uint *)((uint)puRam020bcbe4 & 0xfffffffc) << ((uint)puRam020bcbe4 & 3) * -8 + 0x20) +
           8) = iVar6 - 1U & 0xffff;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x10) = 1;
  return;
}

