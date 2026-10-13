/* Decompiled C draft; module arm9; ROM address 020e3e48. No matching claim. */
#include "types.h"
#include "deps/020e3e48_func_020e3e48.h"

uint func_020e3e48(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,0x30);
  puVar2 = puRam020e3ea0;
  piVar1 = piRam020e3e9c;
  *piRam020e3e9c = (int)puVar4;
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
  func_020d49d8(piVar1);
  return *(uint *)((uint)piRam020e3e9c & 0xfffffffc) >> ((uint)piRam020e3e9c & 3) * 8 |
         *(uint *)((uint)piRam020e3e9c & 0xfffffffc) << ((uint)piRam020e3e9c & 3) * -8 + 0x20;
}

