/* Decompiled C draft; module arm9; ROM address 020545e8. No matching claim. */
#include "types.h"
#include "deps/020545e8_InitializeGlobalZE.h"

void InitializeGlobalZE(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)Mem_AllocateHeapAligned(param_1,0x1f00,0x20);
  puVar1 = puRam02054658;
  *puRam02054658 = puVar2;
  *puVar2 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 8) = 9;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined2 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x454) = 0;
  uVar3 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  *(byte *)(uVar3 + 0x456) = *(byte *)(uVar3 + 0x456) & 0xfe;
  return;
}

