/* Decompiled C draft; module arm9; ROM address 02005198. No matching claim. */
#include "types.h"
#include "deps/02005198_Fs_LoadOverlay.h"

undefined4 Fs_LoadOverlay(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_30 [48];
  
  iVar1 = Fs_OverlayInfo_Load((int)(uintptr_t)(auStack_30),param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = Fs_OverlayInfo_LoadImage((int)(uintptr_t)(auStack_30)), iVar1 != 0)) {
    Fs_OverlayInfo_Start((uint)(uintptr_t)(auStack_30));
    return 1;
  }
  return 0;
}

