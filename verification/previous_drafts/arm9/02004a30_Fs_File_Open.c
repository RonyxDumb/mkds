/* Decompiled C draft; module arm9; ROM address 02004a30. No matching claim. */
#include "types.h"
#include "deps/02004a30_Fs_File_Open.h"

undefined4 Fs_File_Open(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar1 = Fs_FileId_LoadFromPath(&local_10);
  if ((iVar1 != 0) && (iVar1 = Fs_File_OpenById(param_1,local_10,uStack_c), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

