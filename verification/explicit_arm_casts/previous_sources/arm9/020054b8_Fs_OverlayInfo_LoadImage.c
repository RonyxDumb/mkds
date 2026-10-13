/* Decompiled C draft; module arm9; ROM address 020054b8. No matching claim. */
#include "types.h"
#include "deps/020054b8_Fs_OverlayInfo_LoadImage.h"

undefined4 Fs_OverlayInfo_LoadImage(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [76];
  
  Fs_File_Initialize(auStack_58);
  Fs_GetOverlayFileId(&local_60,param_1);
  iVar2 = Fs_File_OpenById(auStack_58,local_60,uStack_5c);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = Fs_OverlayInfo_GetBinarySize(param_1);
  Fs_OverlayInfo_ClearImage(param_1);
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  iVar3 = Fs_File_Read(auStack_58,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,iVar2);
  if (iVar2 == iVar3) {
    Fs_File_Close(auStack_58);
    return 1;
  }
  Fs_File_Close(auStack_58);
  return 0;
}

