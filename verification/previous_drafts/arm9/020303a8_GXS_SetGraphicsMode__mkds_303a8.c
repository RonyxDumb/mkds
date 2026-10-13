/* Decompiled C draft; module arm9; ROM address 020303a8. No matching claim. */
#include "types.h"
#include "deps/020303a8_GXS_SetGraphicsMode__mkds_303a8.h"

void GXS_SetGraphicsMode__mkds_303a8(int param_1)

{
  *puRam020303c0 =
       (*(uint *)((uint)puRam020303c0 & 0xfffffffc) >> ((uint)puRam020303c0 & 3) * 8 |
       *(uint *)((uint)puRam020303c0 & 0xfffffffc) << ((uint)puRam020303c0 & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

