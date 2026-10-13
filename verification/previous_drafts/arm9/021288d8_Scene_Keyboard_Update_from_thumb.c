/* Decompiled C draft; module arm9; ROM address 021288d8. No matching claim. */
#include "types.h"
#include "deps/021288d8_Scene_Keyboard_Update_from_thumb.h"

void Scene_Keyboard_Update_from_thumb(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  OamBuffer_ResetValues16_from_thumb(*piRam02128914,*piRam02128914 + iRam02128918);
  func_021289e0();
  OamBuffer_SomeFn2_from_thumb(*piRam02128914,*piRam02128914 + iRam02128918);
  if ((param_1 != 0) && (iVar2 = GetKeyboardContextNextSceneId_from_thumb(), iVar2 != -1)) {
    uVar1 = GetKeyboardContextNextSceneId_from_thumb();
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  return;
}

