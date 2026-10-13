/* Decompiled C draft; module arm9; ROM address 02111584. No matching claim. */
#include "types.h"
#include "deps/02111584_func_02111584.h"

void func_02111584(void)

{
  func_021144b4();
  (**(code **)(*piRam021115ac + 0x1c))();
  func_02111a98();
  ResetGlobalNN_from_thumb();
  DisposeNavigationContext_from_thumb();
  *piRam021115ac = 0;
  return;
}

