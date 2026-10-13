/* Decompiled C draft; module arm9; ROM address 020de658. No matching claim. */
#include "types.h"
#include "deps/020de658_Maybe_CreateObj_158528.h"

undefined4 * Maybe_CreateObj_158528(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0x40);
  puVar1 = puRam020de6a4;
  uVar2 = puRam020de6a4[1];
  uVar4 = puRam020de6a4[2];
  uVar5 = puRam020de6a4[3];
  puVar6 = puRam020de6a4 + 4;
  *puVar3 = *puRam020de6a4;
  puVar3[1] = uVar2;
  puVar3[2] = uVar4;
  puVar3[3] = uVar5;
  uVar2 = puVar1[5];
  uVar4 = puVar1[6];
  uVar5 = puVar1[7];
  puVar3[4] = *puVar6;
  puVar3[5] = uVar2;
  puVar3[6] = uVar4;
  puVar3[7] = uVar5;
  uVar2 = puVar1[9];
  uVar4 = puVar1[10];
  uVar5 = puVar1[0xb];
  puVar3[8] = puVar1[8];
  puVar3[9] = uVar2;
  puVar3[10] = uVar4;
  puVar3[0xb] = uVar5;
  uVar2 = puVar1[0xd];
  uVar4 = puVar1[0xe];
  uVar5 = puVar1[0xf];
  puVar3[0xc] = puVar1[0xc];
  puVar3[0xd] = uVar2;
  puVar3[0xe] = uVar4;
  puVar3[0xf] = uVar5;
  return puVar3;
}

