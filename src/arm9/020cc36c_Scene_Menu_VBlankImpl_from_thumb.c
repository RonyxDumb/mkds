/* Decompiled C draft; module arm9; ROM address 020cc36c. No matching claim. */
#include "types.h"
#include "deps/020cc36c_Scene_Menu_VBlankImpl_from_thumb.h"

void Scene_Menu_VBlankImpl_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_020cbad0();
  if (iVar2 == 0) {
    func_02077c1c();
  }
  (**(code **)(*piRam020cc3ac + *(int *)(*piRam020cc3ac + 0xc) * 8 + 0x14))();
  NavigationContext_OnSceneVblank_from_thumb();
  piVar1 = piRam020cc3ac;
  *(undefined4 *)(*piRam020cc3ac + 4) = 0;
  CopyOamBuffersToMemory_from_thumb(*piVar1 + iRam020cc3b0,*piVar1 + iRam020cc3b4);
  return;
}

