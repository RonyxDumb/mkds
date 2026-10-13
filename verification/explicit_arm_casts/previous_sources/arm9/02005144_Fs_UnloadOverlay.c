/* Decompiled C draft; module arm9; ROM address 02005144. No matching claim. */
#include "types.h"
#include "deps/02005144_Fs_UnloadOverlay.h"

undefined4 Fs_UnloadOverlay(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_30 [48];
  
  iVar1 = Fs_OverlayInfo_Load(auStack_30,param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = Fs_OverlayInfo_UnloadImage(auStack_30), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

