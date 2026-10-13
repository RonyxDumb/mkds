/* Decompiled C draft; module arm9; ROM address 020b65f0. No matching claim. */
#include "types.h"
#include "deps/020b65f0_func_020b65f0.h"

void func_020b65f0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  uVar2 = GetActiveExecutionContextHeapHandle_2();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0x9c);
  puVar1 = puRam020b67f8;
  *puRam020b67f8 = puVar3;
  *puVar3 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x14) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x18) = 0;
  *(undefined2 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x1c) = 0;
  *(undefined2 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x1e) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x20) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x24) = 0;
  func_020b6b54((undefined4)(uintptr_t)(&local_38),(undefined4)(uintptr_t)(&local_30));
  uVar4 = *(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
          *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20;
  *(int *)(uVar4 + 0x2c) = local_38;
  *(int *)(uVar4 + 0x30) = local_34;
  *(int *)(uVar4 + 0x34) = local_30;
  *(int *)(uVar4 + 0x38) = local_2c;
  uVar7 = FX_Inv64(local_30 - local_38);
  *(undefined8 *)
   ((*(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
    *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20) + 0x3c) =
       uVar7;
  uVar7 = FX_Inv64(local_2c - local_34);
  *(undefined8 *)
   ((*(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
    *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20) + 0x44) =
       uVar7;
  func_020b6a98((undefined4)(uintptr_t)(&local_28),(undefined4)(uintptr_t)(&local_20));
  uVar4 = *(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
          *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20;
  *(int *)(uVar4 + 0x4c) = local_28;
  *(int *)(uVar4 + 0x50) = local_24;
  *(int *)(uVar4 + 0x54) = local_20;
  *(int *)(uVar4 + 0x58) = local_1c;
  uVar7 = FX_Inv64(local_20 - local_28);
  *(undefined8 *)
   ((*(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
    *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20) + 0x5c) =
       uVar7;
  uVar7 = FX_Inv64(local_1c - local_24);
  *(undefined8 *)
   ((*(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
    *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20) + 100) =
       uVar7;
  uVar2 = FX_Div(local_20 - local_28,0x200000);
  uVar2 = SomeFxProduct(uVar2,0xb0000);
  *(undefined4 *)
   ((*(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
    *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20) + 0x28) =
       uVar2;
  func_020b681c((undefined4)(uintptr_t)(&local_18),(undefined4)(uintptr_t)(&local_10));
  puVar1 = puRam020b67f8;
  uVar4 = *(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
          *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20;
  *(int *)(uVar4 + 0x6c) = local_18;
  *(int *)(uVar4 + 0x70) = local_14;
  *(int *)(uVar4 + 0x74) = local_10;
  *(int *)(uVar4 + 0x78) = local_c;
  uVar4 = (uint)puVar1 & 3;
  uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar7 = FX_Inv64(local_10 - local_18);
  *(undefined8 *)(uVar4 + 0x7c) = uVar7;
  uVar7 = FX_Inv64(local_c - local_14);
  *(undefined8 *)(uVar4 + 0x84) = uVar7;
  *(undefined4 *)(uVar4 + 0x8c) = 0;
  uVar4 = *(uint *)((uint)puRam020b67f8 & 0xfffffffc) >> ((uint)puRam020b67f8 & 3) * 8 |
          *(uint *)((uint)puRam020b67f8 & 0xfffffffc) << ((uint)puRam020b67f8 & 3) * -8 + 0x20;
  uVar2 = puRam020b67fc[1];
  uVar5 = puRam020b67fc[2];
  *(undefined4 *)(uVar4 + 0x90) = *puRam020b67fc;
  *(undefined4 *)(uVar4 + 0x94) = uVar2;
  *(undefined4 *)(uVar4 + 0x98) = uVar5;
  return;
}

