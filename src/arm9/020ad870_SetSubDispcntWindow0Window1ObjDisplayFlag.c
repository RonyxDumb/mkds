/* Decompiled C draft; module arm9; ROM address 020ad870. No matching claim. */
#include "types.h"
#include "deps/020ad870_SetSubDispcntWindow0Window1ObjDisplayFlag.h"

void SetSubDispcntWindow0Window1ObjDisplayFlag(int param_1)

{
  *puRam020ad888 =
       (*(uint *)((uint)puRam020ad888 & 0xfffffffc) >> ((uint)puRam020ad888 & 3) * 8 |
       *(uint *)((uint)puRam020ad888 & 0xfffffffc) << ((uint)puRam020ad888 & 3) * -8 + 0x20) &
       0xffff1fff | param_1 << 0xd;
  return;
}

