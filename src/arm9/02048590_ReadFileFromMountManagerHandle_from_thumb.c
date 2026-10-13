/* Decompiled C draft; module arm9; ROM address 02048590. No matching claim. */
#include "types.h"
#include "deps/02048590_ReadFileFromMountManagerHandle_from_thumb.h"

int ReadFileFromMountManagerHandle_from_thumb(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r7;
  
  iVar4 = *piRam02048634 + iRam02048638;
  if ((*(uint *)(iVar4 + 0xc) & 1) == 0) {
    if ((*(uint *)(iVar4 + 0xc) & 0x10) != 0) {
      Fs_File_Close(iVar4);
    }
    iVar1 = Fs_File_Open(iVar4,param_1);
    if (iVar1 != 0) {
      unaff_r7 = *(int *)(iVar4 + 0x28) - *(int *)(iVar4 + 0x24);
      iVar2 = Mem_AllocateHeap(param_2,unaff_r7);
      *param_3 = iVar2;
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (iVar3 = Fs_File_Read(iVar4,iVar2,unaff_r7), iVar3 < 0)) {
        iVar1 = 0;
        Mem_FreeHeap(param_2,iVar2);
      }
      Fs_File_Close(iVar4);
    }
    if (iVar1 == 0) {
      unaff_r7 = -1;
      *param_3 = 0;
    }
    return unaff_r7;
  }
  return 0;
}

