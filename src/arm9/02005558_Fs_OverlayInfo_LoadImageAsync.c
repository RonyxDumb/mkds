/* Decompiled C draft; module arm9; ROM address 02005558. No matching claim. */
#include "types.h"
#include "deps/02005558_Fs_OverlayInfo_LoadImageAsync.h"

undefined4 Fs_OverlayInfo_LoadImageAsync(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_18;
  undefined4 uStack_14;
  
  Fs_File_Initialize((undefined4 *)(uintptr_t)(param_2));
  Fs_GetOverlayFileId(&local_18,param_1);
  iVar2 = Fs_File_OpenById(param_2,local_18,uStack_14);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = Fs_OverlayInfo_GetBinarySize(param_1);
  Fs_OverlayInfo_ClearImage(param_1);
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  iVar3 = Fs_File_ReadAsync(param_2,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,iVar2);
  if (iVar2 != iVar3) {
    Fs_File_Close(param_2);
    return 0;
  }
  return 1;
}

