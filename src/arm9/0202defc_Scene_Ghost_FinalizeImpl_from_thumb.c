/* Decompiled C draft; module arm9; ROM address 0202defc. No matching claim. */
#include "types.h"
#include "deps/0202defc_Scene_Ghost_FinalizeImpl_from_thumb.h"

void Scene_Ghost_FinalizeImpl_from_thumb(void)

{
  uint uVar1;
  
  uVar1 = uRam0202df2c;
  *puRam0202df28 = *puRam0202df28 & uRam0202df2c;
  *puRam0202df30 = *puRam0202df30 & uVar1;
  DisposeNavigationContext_from_thumb();
  ResetGlobalNN_from_thumb();
  func_02117218();
  func_0204f7f4();
  return;
}

