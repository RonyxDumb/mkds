/* Decompiled C draft; module arm9; ROM address 0202a5a0. No matching claim. */
#include "types.h"
#include "deps/0202a5a0_Scene_Result_VBlankImpl_from_thumb.h"

void Scene_Result_VBlankImpl_from_thumb(void)

{
  if (*(int *)(*piRam0202a5cc + iRam0202a5d0) == 0) {
    func_02029a90();
  }
  else {
    func_02032aa8();
  }
  CopyOamBuffersToMemory_from_thumb(*piRam0202a5cc,*piRam0202a5cc + iRam0202a5d4);
  return;
}

