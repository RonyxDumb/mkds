/* Decompiled C draft; module arm9; ROM address 02047e94. No matching claim. */
#include "types.h"
#include "deps/02047e94_ReadDecompressCurrentMountEntry_from_thumb.h"

void ReadDecompressCurrentMountEntry_from_thumb(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [72];
  
  iVar4 = *piRam02047f6c + iRam02047f70;
  Fs_File_Initialize(auStack_5c);
  iVar1 = Fs_File_Open(auStack_5c,iVar4);
  if (((iVar1 != 0) &&
      (iVar1 = Fs_File_Read(auStack_5c,*(undefined4 *)(iVar4 + 0x88),4), -1 < iVar1)) &&
     (uVar2 = **(uint **)(iVar4 + 0x88) >> 8, uVar2 <= uRam02047f74)) {
    if (*(int *)(iVar4 + 0x90) == 0) {
      GetActiveExecutionContext();
      uVar3 = ExecutionContext_GetHeapHandle();
      uVar3 = Mem_AllocateHeapAligned(uVar3,uVar2,0x20);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
    }
    else {
      GetActiveExecutionContext();
      uVar3 = ExecutionContext_GetHeapHandle();
      uVar3 = Mem_AllocateHeapAligned(uVar3,uVar2,0xffffffe0);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
    }
    LzDecompressContext_Create
              (auStack_6c,*(undefined4 *)(iVar4 + 0x84),*(undefined4 *)(iVar4 + 0x88));
    uVar3 = uRam02047f78;
    do {
      iVar1 = Fs_File_Read(auStack_5c,*(undefined4 *)(iVar4 + 0x88),uVar3);
      if (iVar1 < 1) {
        return;
      }
      iVar1 = LzDecompressContext_DoCycle(auStack_6c,*(undefined4 *)(iVar4 + 0x88));
    } while (iVar1 != 0);
    DC_SomeClean(*(undefined4 *)(iVar4 + 0x84),uVar2);
    GetActiveExecutionContext();
    ExecutionContext_GetHeapHandle();
    Mem_GetExpHeapTotalFreeSize();
  }
  return;
}

