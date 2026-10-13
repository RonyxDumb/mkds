/* Decompiled C draft; module arm9; ROM address 020cc150. No matching claim. */
#include "types.h"
#include "deps/020cc150_SetDispcntWindows01ObjDisplayFlagsTop.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetDispcntWindows01ObjDisplayFlagsTop(int param_1)

{
  _DAT_04000000 = _DAT_04000000 & 0xffff1fff | param_1 << 0xd;
  return;
}

