/* Decompiled C draft; module arm9; ROM address 020e5d24. No matching claim. */
#include "types.h"
#include "deps/020e5d24_func_020e5d24.h"

undefined4 * func_020e5d24(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0x28);
  puVar1 = puRam020e5d74;
  *piRam020e5d70 = (int)puVar3;
  uVar2 = puVar1[1];
  uVar4 = puVar1[2];
  uVar5 = puVar1[3];
  *puVar3 = *puVar1;
  puVar3[1] = uVar2;
  puVar3[2] = uVar4;
  puVar3[3] = uVar5;
  uVar2 = puVar1[5];
  uVar4 = puVar1[6];
  uVar5 = puVar1[7];
  puVar3[4] = puVar1[4];
  puVar3[5] = uVar2;
  puVar3[6] = uVar4;
  puVar3[7] = uVar5;
  uVar2 = puVar1[9];
  puVar3[8] = puVar1[8];
  puVar3[9] = uVar2;
  return puVar3;
}

