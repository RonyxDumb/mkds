/* Decompiled C draft; module arm9; ROM address 020d9bb8. No matching claim. */
#include "types.h"
#include "deps/020d9bb8_LoadBeachWaterModels.h"

void LoadBeachWaterModels(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam020d9c24);
  *piRam020d9c28 = iVar3;
  func_020d9cf4(uRam020d9c3c,uRam020d9c40,uRam020d9c44,uRam020d9c48,uRam020d9c2c,uRam020d9c30,
                uRam020d9c34,uRam020d9c38,0x96,0x96,1,6,10,10,1);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9c4c);
  *(undefined4 *)(*piRam020d9c28 + 0x60) = uVar2;
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9c50);
  piVar1 = piRam020d9c28;
  *(undefined4 *)(*piRam020d9c28 + 100) = uVar2;
  func_020d4980(*piVar1);
  return;
}

