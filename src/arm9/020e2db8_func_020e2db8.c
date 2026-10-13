/* Decompiled C draft; module arm9; ROM address 020e2db8. No matching claim. */
#include "types.h"
#include "deps/020e2db8_func_020e2db8.h"

uint func_020e2db8(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x40);
  puVar2 = puRam020e2e18;
  piVar1 = piRam020e2e14;
  *piRam020e2e14 = (int)puVar4;
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
  uVar6 = puVar2[0xb];
  puVar4[8] = puVar2[8];
  puVar4[9] = uVar3;
  puVar4[10] = uVar5;
  puVar4[0xb] = uVar6;
  uVar3 = puVar2[0xd];
  uVar5 = puVar2[0xe];
  uVar6 = puVar2[0xf];
  puVar4[0xc] = puVar2[0xc];
  puVar4[0xd] = uVar3;
  puVar4[0xe] = uVar5;
  puVar4[0xf] = uVar6;
  func_020d49d8(piVar1);
  return *(uint *)((uint)piRam020e2e14 & 0xfffffffc) >> ((uint)piRam020e2e14 & 3) * 8 |
         *(uint *)((uint)piRam020e2e14 & 0xfffffffc) << ((uint)piRam020e2e14 & 3) * -8 + 0x20;
}

