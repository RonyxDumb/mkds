/* Decompiled C draft; module arm9; ROM address 0210f9f0. No matching claim. */
#include "types.h"
#include "deps/0210f9f0_func_0210f9f0.h"

void func_0210f9f0(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((uint)piRam0210fa24 & 0xfffffffc) >> ((uint)piRam0210fa24 & 3) * 8 |
          *(uint *)((uint)piRam0210fa24 & 0xfffffffc) << ((uint)piRam0210fa24 & 3) * -8 + 0x20;
  *piRam0210fa24 = uVar1 + 1;
  DriverContext_MaybeQueuePlaySfx(param_1,uVar1 + 0xea,0x7f,0);
  return;
}

