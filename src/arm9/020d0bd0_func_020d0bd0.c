/* Decompiled C draft; module arm9; ROM address 020d0bd0. No matching claim. */
#include "types.h"
#include "deps/020d0bd0_func_020d0bd0.h"

void func_020d0bd0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0xb0);
  puVar1 = puRam020d0cb8;
  uVar5 = 0;
  *puRam020d0cb8 = puVar3;
  *puVar3 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 8) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x14) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x18) = 0;
  do {
    iVar4 = uVar5 * 0x1c;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x1c) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x20) = 0;
    uVar5 = uVar5 + 1 & 0xffff;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x24) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x28) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x2c) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x30) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x34) = 0;
  } while (uVar5 < 5);
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xa8) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xac) = 0;
  return;
}

