/* Decompiled C draft; module arm9; ROM address 0202df34. No matching claim. */
#include "types.h"
#include "deps/0202df34_Scene_Ghost_UpdateImpl_from_thumb.h"

void Scene_Ghost_UpdateImpl_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = iRam0202dfc0;
  iVar5 = iRam0202dfbc;
  piVar1 = piRam0202dfb8;
  iVar3 = *piRam0202dfb8;
  if (*(int *)(iVar3 + iRam0202dfc0) == *(int *)(iVar3 + iRam0202dfbc)) {
    OamBuffer_ResetValues16_from_thumb(iVar3,iVar3 + iRam0202dfd0);
    iVar5 = (**(code **)(*(int *)(*piRam0202dfb8 + iRam0202dfc4) + 4))(param_1);
    if (iVar5 != -1) {
      *(int *)(*piRam0202dfb8 + iRam0202dfbc) = iVar5;
    }
    OamBuffer_SomeFn2_from_thumb(*piRam0202dfb8,*piRam0202dfb8 + iRam0202dfd0);
  }
  else {
    iVar4 = *(int *)(iVar3 + iRam0202dfc4);
    *(int *)(iVar3 + iRam0202dfc4) = *(int *)(iRam0202dfc8 + *(int *)(iVar3 + iRam0202dfbc) * 4);
    *(undefined4 *)(*piVar1 + iVar2) = *(undefined4 *)(*piVar1 + iVar5);
    (**(code **)(iVar4 + 8))();
    iVar5 = *piRam0202dfb8;
    (*(code *)**(undefined4 **)(iVar5 + iRam0202dfc4))
              (*(undefined4 *)(iVar5 + iRam0202dfcc),iVar5,iVar5 + iRam0202dfd0);
  }
  NavigationContext_OnSceneUpdate_from_thumb();
  func_0212a920();
  return;
}

