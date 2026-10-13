/* Decompiled C draft; module arm9; ROM address 0202f1dc. No matching claim. */
#include "types.h"
#include "deps/0202f1dc_Scene_WLMenu_FinalizeImpl_from_thumb.h"

void Scene_WLMenu_FinalizeImpl_from_thumb(void)

{
  int iVar1;
  
  (**(code **)(*(int *)(*piRam0202f204 + iRam0202f208) + 8))();
  iVar1 = func_0202f19c();
  if (iVar1 == 0) {
    DisposeNavigationContext_from_thumb();
  }
  ResetGlobalNN_from_thumb();
  return;
}

