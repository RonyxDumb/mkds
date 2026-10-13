/* Decompiled C draft; module arm9; ROM address 020dd804. No matching claim. */
#include "types.h"
#include "deps/020dd804_Maybe_CreateObj_15835c.h"

uint Maybe_CreateObj_15835c(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x2c);
  puVar2 = puRam020dd85c;
  piVar1 = piRam020dd858;
  *piRam020dd858 = (int)puVar4;
  uVar3 = puVar2[1];
  uVar5 = puVar2[2];
  uVar6 = puVar2[3];
  *puVar4 = *puVar2;
  puVar4[1] = uVar3;
  puVar4[2] = uVar5;
  puVar4[3] = uVar6;
  uVar3 = puVar2[5];
  uVar5 = puVar2[6];
  uVar6 = puVar2[7];
  puVar4[4] = puVar2[4];
  puVar4[5] = uVar3;
  puVar4[6] = uVar5;
  puVar4[7] = uVar6;
  uVar3 = puVar2[9];
  uVar5 = puVar2[10];
  puVar4[8] = puVar2[8];
  puVar4[9] = uVar3;
  puVar4[10] = uVar5;
  func_020d49d8(piVar1);
  return *(uint *)((uint)piRam020dd858 & 0xfffffffc) >> ((uint)piRam020dd858 & 3) * 8 |
         *(uint *)((uint)piRam020dd858 & 0xfffffffc) << ((uint)piRam020dd858 & 3) * -8 + 0x20;
}

