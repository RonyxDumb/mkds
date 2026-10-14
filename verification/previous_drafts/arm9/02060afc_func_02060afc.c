/* Decompiled C draft; module arm9; ROM address 02060afc. No matching claim. */
#include "types.h"
#include "deps/02060afc_func_02060afc.h"

uint func_02060afc(undefined4 param_1)

{
  uint uVar1;
  undefined1 auStack_28 [34];
  byte local_6;
  
  GlobalZ_GetOI(param_1,(int)(uintptr_t)(auStack_28));
  if ((int)((uint)local_6 << 0x1f) < 0) {
    uVar1 = ((uint)local_6 << 0x1c) >> 0x1f;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

