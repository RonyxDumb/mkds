/* Decompiled C draft; module arm9; ROM address 0202f160. No matching claim. */
#include "types.h"
#include "deps/0202f160_Scene_WLMenu_VblankImpl_from_thumb.h"

void Scene_WLMenu_VblankImpl_from_thumb(void)

{
  int iVar1;
  
  iVar1 = func_0202f19c();
  if (iVar1 == 0) {
    NavigationContext_OnSceneVblank_from_thumb();
  }
  (**(code **)(*(int *)(*piRam0202f190 + iRam0202f194) + 0xc))();
  CopyOamBuffersToMemory_from_thumb(*piRam0202f190,*piRam0202f190 + iRam0202f198);
  return;
}

