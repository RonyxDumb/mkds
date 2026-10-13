/* Decompiled C draft; module arm9; ROM address 020d20a8. No matching claim. */
#include "types.h"
#include "deps/020d20a8_func_020d20a8.h"

void func_020d20a8(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (uint *)Mem_AllocateHeap(uVar2,0x28);
  puVar1 = puRam020d2174;
  uVar5 = uRam020d2170;
  uVar4 = uRam020d2170 & 3;
  uVar6 = *(uint *)(uRam020d2170 & 0xfffffffc);
  *puRam020d2174 = puVar3;
  *puVar3 = (uint)*(ushort *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x60);
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = uVar6 + 8 & 3;
  uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if (uVar4 == 5) {
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 4;
  }
  else if ((uVar4 == 3) &&
          (uVar4 = uVar6 + 0x1c & 3, uVar5 = *(uint *)(uVar6 + 0x1c & 0xfffffffc),
          (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 2)) {
    *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) =
         (uint)*(ushort *)(uVar6 + 0x3d8);
  }
  else {
    *(undefined4 *)
     ((*(uint *)((uint)puRam020d2174 & 0xfffffffc) >> ((uint)puRam020d2174 & 3) * 8 |
      *(uint *)((uint)puRam020d2174 & 0xfffffffc) << ((uint)puRam020d2174 & 3) * -8 + 0x20) + 4) = 0
    ;
  }
  func_020b4cec((uint *)(uintptr_t)((*(uint *)((uint)puRam020d2174 & 0xfffffffc) >> ((uint)puRam020d2174 & 3) * 8 |
                *(uint *)((uint)puRam020d2174 & 0xfffffffc) << ((uint)puRam020d2174 & 3) * -8 + 0x20
                ) + 8),0x1000);
  puVar1 = puRam020d2174;
  *(undefined4 *)
   ((*(uint *)((uint)puRam020d2174 & 0xfffffffc) >> ((uint)puRam020d2174 & 3) * 8 |
    *(uint *)((uint)puRam020d2174 & 0xfffffffc) << ((uint)puRam020d2174 & 3) * -8 + 0x20) + 0x18) =
       0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x1c) = 0;
  *(undefined2 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x20) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x24) = 0;
  return;
}

