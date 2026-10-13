/* Decompiled C draft; module arm9; ROM address 0212d8e0. No matching claim. */
#include "types.h"
#include "deps/0212d8e0_Sound_ReadSdatFromPathImpl.h"

void Sound_ReadSdatFromPathImpl
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  iVar1 = Fs_FileId_LoadFromPath(param_1 + 0x7c);
  if (iVar1 == 0) {
    return;
  }
  Fs_File_Initialize((undefined4 *)(uintptr_t)(param_1 + 0x34));
  iVar1 = Fs_File_OpenById(param_1 + 0x34,*(undefined4 *)(param_1 + 0x7c),
                           *(undefined4 *)(param_1 + 0x80));
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x30) = 1;
    iVar1 = Sound_ReadSdatFromOpenedFile(param_1,param_3,param_4);
    if (iVar1 != 0) {
      *piRam0212d964 = param_1;
    }
    return;
  }
  return;
}

