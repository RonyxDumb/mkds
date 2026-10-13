/* Decompiled C draft; module arm9; ROM address 02060a94. No matching claim. */
#include "types.h"
#include "deps/02060a94_func_02060a94.h"

uint func_02060a94(undefined4 param_1)

{
  uint uVar1;
  undefined1 auStack_28 [2];
  ushort uStack_26;
  byte local_6;
  
  GlobalZ_GetOI(param_1,(int)(uintptr_t)(auStack_28));
  if ((int)((uint)local_6 << 0x1f) < 0) {
    uVar1 = (uint)uStack_26;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

