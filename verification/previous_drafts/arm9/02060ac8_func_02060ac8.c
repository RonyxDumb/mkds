/* Decompiled C draft; module arm9; ROM address 02060ac8. No matching claim. */
#include "types.h"
#include "deps/02060ac8_func_02060ac8.h"

uint func_02060ac8(undefined4 param_1)

{
  uint uVar1;
  ushort auStack_28 [17];
  byte local_6;
  
  GlobalZ_GetOI(param_1,(int)(uintptr_t)(auStack_28));
  if ((int)((uint)local_6 << 0x1f) < 0) {
    uVar1 = (uint)auStack_28[0];
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

