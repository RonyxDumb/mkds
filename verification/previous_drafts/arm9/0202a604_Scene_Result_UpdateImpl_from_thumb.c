/* Decompiled C draft; module arm9; ROM address 0202a604. No matching claim. */
#include "types.h"
#include "deps/0202a604_Scene_Result_UpdateImpl_from_thumb.h"

void Scene_Result_UpdateImpl_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02049b6c();
  if (iVar1 == 0) {
    OamBuffer_ResetValues16_from_thumb(*piRam0202a64c,*piRam0202a64c + iRam0202a650);
    if (*(int *)(*piRam0202a64c + iRam0202a654) == 0) {
      HandleEarnedSecrets_from_thumb(param_1);
    }
    else {
      func_02032ac4(param_1);
    }
    OamBuffer_SomeFn2_from_thumb(*piRam0202a64c,*piRam0202a64c + iRam0202a650);
    func_0212a920();
  }
  return;
}

