/* Decompiled C draft; module arm9; ROM address 0202dec8. No matching claim. */
#include "types.h"
#include "deps/0202dec8_Scene_Ghost_VblankImpl_from_thumb.h"

void Scene_Ghost_VblankImpl_from_thumb(void)

{
  NavigationContext_OnSceneVblank_from_thumb();
  (**(code **)(*(int *)(*piRam0202def0 + iRam0202def4) + 0xc))();
  CopyOamBuffersToMemory_from_thumb(*piRam0202def0,*piRam0202def0 + iRam0202def8);
  return;
}

