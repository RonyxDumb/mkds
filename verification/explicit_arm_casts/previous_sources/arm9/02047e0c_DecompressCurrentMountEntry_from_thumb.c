/* Decompiled C draft; module arm9; ROM address 02047e0c. No matching claim. */
#include "types.h"
#include "deps/02047e0c_DecompressCurrentMountEntry_from_thumb.h"

void DecompressCurrentMountEntry_from_thumb(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *piRam02047e8c + iRam02047e90;
  uVar2 = **(uint **)(iVar3 + 0x80) >> 8;
  if (*(int *)(iVar3 + 0x90) == 0) {
    GetActiveExecutionContext();
    uVar1 = ExecutionContext_GetHeapHandle();
    uVar1 = Mem_AllocateHeapAligned(uVar1,uVar2,0x20);
    *(undefined4 *)(iVar3 + 0x84) = uVar1;
  }
  else {
    GetActiveExecutionContext();
    uVar1 = ExecutionContext_GetHeapHandle();
    uVar1 = Mem_AllocateHeapAligned(uVar1,uVar2,0xffffffe0);
    *(undefined4 *)(iVar3 + 0x84) = uVar1;
  }
  DecompressLzss(*(undefined4 *)(iVar3 + 0x80),*(undefined4 *)(iVar3 + 0x84));
  DC_SomeClean(*(undefined4 *)(iVar3 + 0x84),uVar2);
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  Mem_GetExpHeapTotalFreeSize();
  return;
}

