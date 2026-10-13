/* Decompiled C draft; module arm9; ROM address 02027fb8. No matching claim. */
#include "types.h"
#include "deps/02027fb8_GXS_SetGraphicsMode.h"

void GXS_SetGraphicsMode(int param_1)

{
  *puRam02027fd0 =
       (*(uint *)((uint)puRam02027fd0 & 0xfffffffc) >> ((uint)puRam02027fd0 & 3) * 8 |
       *(uint *)((uint)puRam02027fd0 & 0xfffffffc) << ((uint)puRam02027fd0 & 3) * -8 + 0x20) &
       0xffff1fff | param_1 << 0xd;
  return;
}

