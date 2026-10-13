/* Decompiled C draft; module arm9; ROM address 020ada94. No matching claim. */
#include "types.h"
#include "deps/020ada94_Scene_Title_VBlankImpl_from_thumb.h"

void Scene_Title_VBlankImpl_from_thumb(void)

{
  (**(code **)(*piRam020adac8 + *(int *)(*piRam020adac8 + 0xc) * 8 + 0x14))();
  *(undefined4 *)(*piRam020adac8 + 4) = 0;
  NavigationContext_OnSceneVblank_from_thumb();
  CopyOamBuffersToMemory_from_thumb(*piRam020adac8 + 0xb0,*piRam020adac8 + iRam020adacc);
  return;
}

