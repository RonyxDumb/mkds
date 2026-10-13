/* Decompiled C draft; module arm9; ROM address 020ad88c. No matching claim. */
#include "types.h"
#include "deps/020ad88c_SetTopDispcntWindow0Window1ObjDisplayFlag.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetTopDispcntWindow0Window1ObjDisplayFlag(int param_1)

{
  _DAT_04000000 = _DAT_04000000 & 0xffff1fff | param_1 << 0xd;
  return;
}

