/* Decompiled C draft; module arm9; ROM address 02048684. No matching claim. */
#include "types.h"
#include "deps/02048684_OpenReadEntireFileBuffer_from_thumb.h"

int OpenReadEntireFileBuffer_from_thumb(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_58 [36];
  int local_34;
  int local_30;
  
  Fs_File_Initialize((undefined4 *)(void *)(auStack_58));
  iVar1 = Fs_File_Open(auStack_58,param_1);
  if (iVar1 != 0) {
    if ((param_3 == 0) || ((uint)(local_30 - local_34) <= param_3)) {
      iVar2 = Fs_File_Read(auStack_58,param_2);
      if (iVar2 < 0) {
        iVar1 = 0;
      }
      Fs_File_Close((int)(uintptr_t)(auStack_58));
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

