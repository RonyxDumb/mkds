/* Decompiled C draft; module arm9; ROM address 0212891c. No matching claim. */
#include "types.h"
#include "deps/0212891c_Scene_Keyboard_VBlank_from_thumb.h"

void Scene_Keyboard_VBlank_from_thumb(void)

{
  func_0212899c();
  CopyOamBuffersToMemory_from_thumb(*piRam02128938,*piRam02128938 + iRam0212893c);
  return;
}

