/* Decompiled C draft; module arm9; ROM address 0204af70. No matching claim. */
#include "types.h"
#include "deps/0204af70_InitializeSystemContext.h"

void InitializeSystemContext(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = Os_GetMemoryRegionStartAddress(4);
  iVar2 = Os_GetMemoryRegionEndAddress(4);
  uVar3 = Mem_AllocateHeap(param_1,0x7c);
  *puRam0204afcc = uVar3;
  uVar3 = Mem_Frame_Create(iVar1,iVar2 - iVar1,1);
  *(undefined4 *)
   ((*(uint *)((uint)puRam0204afcc & 0xfffffffc) >> ((uint)puRam0204afcc & 3) * 8 |
    *(uint *)((uint)puRam0204afcc & 0xfffffffc) << ((uint)puRam0204afcc & 3) * -8 + 0x20) + 0x24) =
       uVar3;
  PopulateSystemContext();
  return;
}

