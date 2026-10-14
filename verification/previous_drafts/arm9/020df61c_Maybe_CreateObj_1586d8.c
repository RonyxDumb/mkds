/* Decompiled C draft; module arm9; ROM address 020df61c. No matching claim. */
#include "types.h"
#include "deps/020df61c_Maybe_CreateObj_1586d8.h"

uint Maybe_CreateObj_1586d8(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x28);
  puVar2 = puRam020df674;
  piVar1 = piRam020df670;
  *piRam020df670 = (int)puVar4;
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
  puVar4[8] = puVar2[8];
  puVar4[9] = uVar3;
  func_020e6f50(piVar1);
  return *(uint *)((uint)piRam020df670 & 0xfffffffc) >> ((uint)piRam020df670 & 3) * 8 |
         *(uint *)((uint)piRam020df670 & 0xfffffffc) << ((uint)piRam020df670 & 3) * -8 + 0x20;
}

