/* Decompiled C draft; module arm9; ROM address 0202f20c. No matching claim. */
#include "types.h"
#include "deps/0202f20c_Scene_WLMenu_UpdateImpl_from_thumb.h"

void Scene_WLMenu_UpdateImpl_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = iRam0202f2a0;
  iVar5 = iRam0202f29c;
  piVar1 = piRam0202f298;
  iVar3 = *piRam0202f298;
  if (*(int *)(iVar3 + iRam0202f2a0) == *(int *)(iVar3 + iRam0202f29c)) {
    OamBuffer_ResetValues16_from_thumb(iVar3,iVar3 + iRam0202f2b0);
    iVar5 = (**(code **)(*(int *)(*piRam0202f298 + iRam0202f2a4) + 4))(param_1);
    if (iVar5 != -1) {
      *(int *)(*piRam0202f298 + iRam0202f29c) = iVar5;
    }
    func_0212a920();
    OamBuffer_SomeFn2_from_thumb(*piRam0202f298,*piRam0202f298 + iRam0202f2b0);
  }
  else {
    iVar4 = *(int *)(iVar3 + iRam0202f2a4);
    *(int *)(iVar3 + iRam0202f2a4) = *(int *)(iRam0202f2a8 + *(int *)(iVar3 + iRam0202f29c) * 4);
    *(undefined4 *)(*piVar1 + iVar2) = *(undefined4 *)(*piVar1 + iVar5);
    (**(code **)(iVar4 + 8))();
    iVar5 = *piRam0202f298;
    (*(code *)**(undefined4 **)(iVar5 + iRam0202f2a4))
              (*(undefined4 *)(iVar5 + iRam0202f2ac),iVar5,iVar5 + iRam0202f2b0);
  }
  iVar5 = func_0202f19c();
  if (iVar5 == 0) {
    NavigationContext_OnSceneUpdate_from_thumb();
  }
  return;
}

