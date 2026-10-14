/* Decompiled C draft; module arm9; ROM address 020609f8. No matching claim. */
#include "types.h"
#include "deps/020609f8_func_020609f8.h"

uint func_020609f8(undefined4 param_1)

{
  uint uVar1;
  undefined1 auStack_28 [8];
  ushort uStack_20;
  byte local_6;
  
  GlobalZ_GetOI(param_1,(int)(uintptr_t)(auStack_28));
  if ((int)((uint)local_6 << 0x1f) < 0) {
    uVar1 = (uint)uStack_20;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

