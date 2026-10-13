/* Decompiled C draft; module arm9; ROM address 020dfc44. No matching claim. */
#include "types.h"
#include "deps/020dfc44_func_020dfc44.h"

uint func_020dfc44(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  puVar5 = (undefined4 *)Mem_AllocateHeap(uVar4,0x2c);
  puVar3 = puRam020dfcb0;
  piVar2 = piRam020dfcac;
  *piRam020dfcac = (int)puVar5;
  uVar4 = puVar3[1];
  uVar7 = puVar3[2];
  uVar8 = puVar3[3];
  *puVar5 = *puVar3;
  puVar5[1] = uVar4;
  puVar5[2] = uVar7;
  puVar5[3] = uVar8;
  uVar4 = puVar3[5];
  uVar7 = puVar3[6];
  uVar8 = puVar3[7];
  puVar5[4] = puVar3[4];
  puVar5[5] = uVar4;
  puVar5[6] = uVar7;
  puVar5[7] = uVar8;
  uVar4 = puVar3[9];
  uVar7 = puVar3[10];
  puVar5[8] = puVar3[8];
  puVar5[9] = uVar4;
  puVar5[10] = uVar7;
  func_020e6f50(piVar2);
  uVar4 = FX_Div(0x4000000,uRam020dfcb4);
  piVar2 = piRam020dfcac;
  *(undefined4 *)
   ((*(uint *)((uint)piRam020dfcac & 0xfffffffc) >> ((uint)piRam020dfcac & 3) * 8 |
    *(uint *)((uint)piRam020dfcac & 0xfffffffc) << ((uint)piRam020dfcac & 3) * -8 + 0x20) + 0x28) =
       uVar4;
  uVar1 = (uint)piVar2 & 3;
  uVar6 = *(uint *)((uint)piVar2 & 0xfffffffc);
  return uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
}

