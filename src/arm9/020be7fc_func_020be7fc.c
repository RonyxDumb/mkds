/* Decompiled C draft; module arm9; ROM address 020be7fc. No matching claim. */
#include "types.h"
#include "deps/020be7fc_func_020be7fc.h"

void func_020be7fc(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar3 = Mem_AllocateHeap(uVar3,0x15c);
  puVar2 = puRam020be8dc;
  uVar1 = uRam020be8d8;
  uVar7 = uRam020be8d8 & 3;
  uVar4 = *(uint *)(uRam020be8d8 & 0xfffffffc);
  *puRam020be8dc = uVar3;
  uVar5 = 0;
  if (*(char *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x3d0) != '\0') {
    do {
      *(undefined4 *)
       ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
        *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar5 * 4 + 0x80)
           = 1;
      iVar6 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar5 * 4;
      uVar7 = iVar6 + 0x80;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(iVar6 + 0x60) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      *(undefined4 *)
       ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
        *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar5 * 4 + 0xa0)
           = 0;
      *(undefined4 *)
       ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
        *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar5 * 4 + 0xc0)
           = 0;
      uVar7 = uVar1 & 3;
      uVar4 = *(uint *)(uVar1 & 0xfffffffc);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < *(byte *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x3d0));
  }
  uVar3 = uRam020be8e0;
  puVar2 = puRam020be8dc;
  *(undefined4 *)
   ((*(uint *)((uint)puRam020be8dc & 0xfffffffc) >> ((uint)puRam020be8dc & 3) * 8 |
    *(uint *)((uint)puRam020be8dc & 0xfffffffc) << ((uint)puRam020be8dc & 3) * -8 + 0x20) + 0xe0) =
       0;
  *(undefined2 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xe4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xe8) = uVar3;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xec) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xf0) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xf4) = uVar3;
  *(undefined2 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xf8) = 0;
  return;
}

