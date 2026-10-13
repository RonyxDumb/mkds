/* Decompiled C draft; module arm9; ROM address 02060a2c. No matching claim. */
#include "types.h"
#include "deps/02060a2c_func_02060a2c.h"

uint func_02060a2c(undefined4 param_1)

{
  uint uVar1;
  undefined1 auStack_28 [6];
  ushort uStack_22;
  byte local_6;
  
  GlobalZ_GetOI(param_1,auStack_28);
  if ((int)((uint)local_6 << 0x1f) < 0) {
    uVar1 = (uint)uStack_22;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

