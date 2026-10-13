/* Decompiled C draft; module arm9; ROM address 0204ba2c. No matching claim. */
#include "types.h"
#include "deps/0204ba2c_InitializeSaveDataIoManager_from_thumb.h"

void InitializeSaveDataIoManager_from_thumb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0x70);
  *piRam0204ba70 = iVar1;
  if (*psRam0204ba74 != 2) {
    uVar2 = Mem_AllocateHeapAligned(param_1,uRam0204ba78,0x20);
    *(undefined4 *)(*piRam0204ba70 + 0x60) = uVar2;
    uVar2 = Mem_AllocateHeapAligned(param_1,1,0x20);
    *(undefined4 *)(*piRam0204ba70 + 100) = uVar2;
  }
  *(undefined4 *)(*piRam0204ba70 + 0xc) = 0;
  return;
}

