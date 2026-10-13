/* Decompiled C draft; module arm9; ROM address 020d99f8. No matching claim. */
#include "types.h"
#include "deps/020d99f8_LoadGhostHouseWaterModel.h"

void LoadGhostHouseWaterModel(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam020d9a68);
  *piRam020d9a6c = iVar3;
  func_020d9cf4(0,0,uRam020d9a80,uRam020d9a84,uRam020d9a70,uRam020d9a74,uRam020d9a78,uRam020d9a7c,
                0x78,0x1e,1,0xf,0x19,0x10,0);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9a88);
  *(undefined4 *)(*piRam020d9a6c + 0x60) = uVar2;
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9a8c);
  piVar1 = piRam020d9a6c;
  *(undefined4 *)(*piRam020d9a6c + 100) = uVar2;
  func_020d4980(*piVar1);
  return;
}

