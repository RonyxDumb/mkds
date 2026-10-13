/* Decompiled C draft; module arm9; ROM address 02005704. No matching claim. */
#include "types.h"
#include "deps/02005704_Fs_OverlayInfo_DoLoad.h"

undefined4
Fs_OverlayInfo_DoLoad
          (int param_1,int param_2,int param_3,undefined4 param_4,int param_5,uint param_6,
          int param_7,uint param_8)

{
  int iVar1;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [36];
  int iStack_40;
  int iStack_3c;
  
  if (param_2 != 0) {
    param_5 = param_7;
    param_6 = param_8;
  }
  if (param_6 <= (uint)(param_3 * 0x20)) {
    return 0;
  }
  Fs_File_Initialize((undefined4 *)(void *)(auStack_64));
  iVar1 = Fs_File_OpenRaw(auStack_64,param_4,param_5 + param_3 * 0x20,param_5 + param_6);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = Fs_File_Read(auStack_64,param_1,0x20);
  if (iVar1 != 0x20) {
    Fs_File_Close((int)(uintptr_t)(auStack_64));
    return 0;
  }
  Fs_File_Close((int)(uintptr_t)(auStack_64));
  *(int *)(param_1 + 0x20) = param_2;
  Fs_GetOverlayFileId(&uStack_6c,param_1);
  iVar1 = Fs_File_OpenById((int)(uintptr_t)(auStack_64),uStack_6c,uStack_68);
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(param_1 + 0x24) = iStack_40;
  *(int *)(param_1 + 0x28) = iStack_3c - iStack_40;
  Fs_File_Close((int)(uintptr_t)(auStack_64));
  return 1;
}

