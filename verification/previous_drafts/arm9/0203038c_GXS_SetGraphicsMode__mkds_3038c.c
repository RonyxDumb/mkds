/* Decompiled C draft; module arm9; ROM address 0203038c. No matching claim. */
#include "types.h"
#include "deps/0203038c_GXS_SetGraphicsMode__mkds_3038c.h"

void GXS_SetGraphicsMode__mkds_3038c(int param_1)

{
  *puRam020303a4 =
       (*(uint *)((uint)puRam020303a4 & 0xfffffffc) >> ((uint)puRam020303a4 & 3) * 8 |
       *(uint *)((uint)puRam020303a4 & 0xfffffffc) << ((uint)puRam020303a4 & 3) * -8 + 0x20) &
       0xffff1fff | param_1 << 0xd;
  return;
}

