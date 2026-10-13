/* Decompiled C draft; module arm9; ROM address 020b36dc. No matching claim. */
#include "types.h"
#include "deps/020b36dc_InitializeGlobalB358.h"

void InitializeGlobalB358(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0xc);
  puVar1 = puRam020b3720;
  *puRam020b3720 = puVar3;
  *puVar3 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 8) = 0;
  return;
}

