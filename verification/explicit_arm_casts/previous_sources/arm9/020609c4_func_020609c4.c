/* Decompiled C draft; module arm9; ROM address 020609c4. No matching claim. */
#include "types.h"
#include "deps/020609c4_func_020609c4.h"

uint func_020609c4(undefined4 param_1)

{
  uint uVar1;
  undefined1 auStack_28 [10];
  ushort uStack_1e;
  byte local_6;
  
  GlobalZ_GetOI(param_1,auStack_28);
  if ((int)((uint)local_6 << 0x1f) < 0) {
    uVar1 = (uint)uStack_1e;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

