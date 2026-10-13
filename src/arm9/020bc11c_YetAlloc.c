/* Decompiled C draft; module arm9; ROM address 020bc11c. No matching claim. */
#include "types.h"
#include "deps/020bc11c_YetAlloc.h"

void YetAlloc(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x38);
  puVar2 = puRam020bc200;
  *puRam020bc200 = puVar4;
  *puVar4 = 0;
  uVar7 = uRam020bc204;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 8) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x14) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x18) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x1c) = 0;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar5 = uVar7 + 8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 2) &&
     (uVar7 = uVar7 + 0x18, uVar5 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
     (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) == 1)) {
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x1c) = 1;
  }
  uVar6 = *(uint *)(uRam020bc204 & 0xfffffffc) >> (uRam020bc204 & 3) * 8 |
          *(uint *)(uRam020bc204 & 0xfffffffc) << (uRam020bc204 & 3) * -8 + 0x20;
  uVar5 = uVar6 + 8;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) == 4) &&
     (*(char *)(uVar6 + 0x2f) != '\x06')) {
    *(undefined4 *)
     ((*(uint *)((uint)puRam020bc200 & 0xfffffffc) >> ((uint)puRam020bc200 & 3) * 8 |
      *(uint *)((uint)puRam020bc200 & 0xfffffffc) << ((uint)puRam020bc200 & 3) * -8 + 0x20) + 0x1c)
         = 1;
  }
  puVar2 = puRam020bc200;
  iVar8 = 0;
  do {
    uVar5 = (uint)puVar2 & 3;
    uVar7 = *(uint *)((uint)puVar2 & 0xfffffffc);
    iVar1 = iVar8 * 4;
    iVar8 = iVar8 + 1;
    *(undefined4 *)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + iVar1 + 0x20) = 0;
  } while (iVar8 < 6);
  return;
}

