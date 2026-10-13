/* Decompiled C draft; module arm9; ROM address 02004b54. No matching claim. */
#include "types.h"
#include "deps/02004b54_Fs_FileId_LoadFromPath.h"

bool Fs_FileId_LoadFromPath(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_58 [76];
  
  Fs_File_Initialize((undefined4 *)(void *)(auStack_58));
  iVar1 = Fs_File_FindPath((int)(uintptr_t)(auStack_58),(char *)(uintptr_t)(param_2),param_1,0);
  return iVar1 != 0;
}

