/* Decompiled C draft; module arm9; ROM address 0212899c. No matching claim. */
#include "types.h"
#include "deps/0212899c_func_0212899c.h"

void func_0212899c(void)

{
  func_020ab94c(0,*(short *)(*piRam021289d4 + 0x84) + 0x28);
  *puRam021289dc = *(short *)(*piRam021289d4 + 0x84) * -0x10000 & uRam021289d8;
  func_020aba9c();
  NavigationContext_OnSceneVblank_from_thumb();
  return;
}

