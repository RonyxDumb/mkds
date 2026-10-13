/* Decompiled C draft; module arm9; ROM address 020c8d30. No matching claim. */
#include "types.h"
#include "deps/020c8d30_AnotherAlloc_0.h"

undefined4 AnotherAlloc_0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = func_021000d0(0xcd);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = func_02100094(iVar2);
  if (iVar3 != 0) {
    GetActiveExecutionContext(iVar3);
    uVar4 = ExecutionContext_GetHeapHandle();
    uVar4 = Mem_AllocateHeap(uVar4,0x44);
    *puRam020c8db8 = uVar4;
    uVar4 = func_02100084(iVar2);
    puVar1 = puRam020c8db8;
    *(undefined4 *)
     (*(uint *)((uint)puRam020c8db8 & 0xfffffffc) >> ((uint)puRam020c8db8 & 3) * 8 |
     *(uint *)((uint)puRam020c8db8 & 0xfffffffc) << ((uint)puRam020c8db8 & 3) * -8 + 0x20) = uVar4;
    *(int *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
             *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = iVar3;
    *(int *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
             *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 8) = iVar3;
    return 1;
  }
  return 0;
}

