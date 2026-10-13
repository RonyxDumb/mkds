/* Decompiled C draft; module arm9; ROM address 020d9b20. No matching claim. */
#include "types.h"
#include "deps/020d9b20_LoadTownWaterModel.h"

void LoadTownWaterModel(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam020d9b90);
  *piRam020d9b94 = iVar3;
  func_020d9cf4(0,0,uRam020d9ba8,uRam020d9bac,uRam020d9b98,uRam020d9b9c,uRam020d9ba0,uRam020d9ba4,
                0x78,0x1e,1,0xd,0x19,0x10,0);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9bb0);
  *(undefined4 *)(*piRam020d9b94 + 0x60) = uVar2;
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9bb4);
  piVar1 = piRam020d9b94;
  *(undefined4 *)(*piRam020d9b94 + 100) = uVar2;
  func_020d4980(*piVar1);
  return;
}

