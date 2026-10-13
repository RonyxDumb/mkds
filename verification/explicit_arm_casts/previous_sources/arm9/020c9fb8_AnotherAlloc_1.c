/* Decompiled C draft; module arm9; ROM address 020c9fb8. No matching claim. */
#include "types.h"
#include "deps/020c9fb8_AnotherAlloc_1.h"

undefined4 AnotherAlloc_1(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar4 = Mem_AllocateHeap(uVar3,0x194);
  *piRam020ca054 = iVar4;
  func_020c0ba8(iVar4 + 400,0x18);
  piVar2 = piRam020ca054;
  iVar4 = 0;
  do {
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + iVar4 * 4) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + iVar4 * 4 + 0x20) =
         0;
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + iVar4 * 8 + 0x60) =
         0;
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + iVar4 * 8 + 100) = 0
    ;
    *(undefined2 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + iVar4 * 2 + 0x100) =
         0;
    iVar1 = iVar4 * 4;
    iVar4 = iVar4 + 1;
    *(undefined4 *)
     ((*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
      *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + iVar1 + 0x130) = 0;
  } while (iVar4 < 8);
  return 1;
}

