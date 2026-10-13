/* Decompiled C draft; module arm9; ROM address 02048504. No matching claim. */
#include "types.h"
#include "deps/02048504_AllocateReadFileBuffer_from_thumb.h"

int AllocateReadFileBuffer_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_60 [36];
  int local_3c;
  int local_38;
  
  iVar3 = 0;
  iVar1 = Fs_IsInitialized();
  if (iVar1 == 0) {
    return 0;
  }
  Fs_File_Initialize(auStack_60);
  iVar1 = Fs_File_Open(auStack_60,param_1);
  if (iVar1 != 0) {
    iVar4 = local_38 - local_3c;
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar3 = Mem_AllocateHeapAligned(uVar2,iVar4,param_2);
    DC_SomeClean(iVar3,iVar4);
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar4 = Fs_File_Read(auStack_60,iVar3,iVar4);
      if (iVar4 < 0) {
        GetActiveExecutionContext();
        uVar2 = ExecutionContext_GetHeapHandle();
        Mem_FreeHeap(uVar2,iVar3);
        iVar1 = 0;
      }
      Fs_File_Close(auStack_60);
    }
  }
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  return iVar3;
}

