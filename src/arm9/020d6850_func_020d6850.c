/* Decompiled C draft; module arm9; ROM address 020d6850. No matching claim. */
#include "types.h"
#include "deps/020d6850_func_020d6850.h"

uint func_020d6850(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  puVar3 = (undefined4 *)Mem_AllocateHeap(uVar2,0x5c);
  puVar1 = puRam020d68ac;
  *puRam020d68a8 = puVar3;
  iVar7 = 5;
  do {
    puVar8 = puVar1;
    puVar6 = puVar3;
    uVar2 = puVar8[1];
    uVar4 = puVar8[2];
    uVar5 = puVar8[3];
    *puVar6 = *puVar8;
    puVar6[1] = uVar2;
    puVar6[2] = uVar4;
    puVar6[3] = uVar5;
    iVar7 = iVar7 + -1;
    puVar3 = puVar6 + 4;
    puVar1 = puVar8 + 4;
  } while (iVar7 != 0);
  uVar2 = puVar8[5];
  uVar4 = puVar8[6];
  puVar6[4] = puVar8[4];
  puVar6[5] = uVar2;
  puVar6[6] = uVar4;
  func_020d49d8(puRam020d68a8);
  return *(uint *)((uint)puRam020d68a8 & 0xfffffffc) >> ((uint)puRam020d68a8 & 3) * 8 |
         *(uint *)((uint)puRam020d68a8 & 0xfffffffc) << ((uint)puRam020d68a8 & 3) * -8 + 0x20;
}

