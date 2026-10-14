/* Decompiled C draft; module arm9; ROM address 0202a5d8. No matching claim. */
#include "types.h"
#include "deps/0202a5d8_Scene_Result_FinalizeImpl_from_thumb.h"

void Scene_Result_FinalizeImpl_from_thumb(void)

{
  if (*(int *)(*piRam0202a5fc + iRam0202a600) == 0) {
    func_02029a98();
  }
  else {
    func_02032ab0();
  }
  ResetGlobalNN_from_thumb();
  return;
}

