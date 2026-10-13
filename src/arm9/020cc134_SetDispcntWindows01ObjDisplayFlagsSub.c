/* Decompiled C draft; module arm9; ROM address 020cc134. No matching claim. */
#include "types.h"
#include "deps/020cc134_SetDispcntWindows01ObjDisplayFlagsSub.h"

void SetDispcntWindows01ObjDisplayFlagsSub(int param_1)

{
  *puRam020cc14c =
       (*(uint *)((uint)puRam020cc14c & 0xfffffffc) >> ((uint)puRam020cc14c & 3) * 8 |
       *(uint *)((uint)puRam020cc14c & 0xfffffffc) << ((uint)puRam020cc14c & 3) * -8 + 0x20) &
       0xffff1fff | param_1 << 0xd;
  return;
}

