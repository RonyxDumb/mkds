/* Decompiled C draft; module arm9; ROM address 0210ba78. No matching claim. */
#include "types.h"
#include "deps/0210ba78_func_0210ba78.h"

void func_0210ba78(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)((uint)piRam0210babc & 0xfffffffc) >> ((uint)piRam0210babc & 3) * 8 |
          *(uint *)((uint)piRam0210babc & 0xfffffffc) << ((uint)piRam0210babc & 3) * -8 + 0x20;
  DriverContext_MaybeQueuePlaySfx(param_1,param_2 + uVar1,0x7fU - ((int)uVar1 >> 1) & 0xff,0);
  *piRam0210babc =
       (*(uint *)((uint)piRam0210babc & 0xfffffffc) >> ((uint)piRam0210babc & 3) * 8 |
       *(uint *)((uint)piRam0210babc & 0xfffffffc) << ((uint)piRam0210babc & 3) * -8 + 0x20) + 10;
  return;
}

