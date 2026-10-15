/* Decompiled C draft; module arm9; ROM address 02001a74. No matching claim. */
#include "types.h"
#include "deps/02001a74_Scene_Logo_UpdateImpl.h"

void Scene_Logo_UpdateImpl(int param_1)

{
  StateDualHandler_Execute
            ((*(uint *)(uRam02001ab8 & 0xfffffffc) >> (uRam02001ab8 & 3) * 8 |
             *(uint *)(uRam02001ab8 & 0xfffffffc) << (uRam02001ab8 & 3) * -8 + 0x20) + 0x18);
  if ((param_1 != 0) &&
     (*(short *)((*(uint *)(uRam02001ab8 & 0xfffffffc) >> (uRam02001ab8 & 3) * 8 |
                 *(uint *)(uRam02001ab8 & 0xfffffffc) << (uRam02001ab8 & 3) * -8 + 0x20) + 0x26) ==
      0xb)) {
    *(undefined2 *)(param_1 + 4) = 0;
  }
  NavigationContext_OnSceneUpdate_from_thumb();
  return;
}

