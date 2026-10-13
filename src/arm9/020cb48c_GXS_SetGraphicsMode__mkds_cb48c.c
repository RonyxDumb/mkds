/* Decompiled C draft; module arm9; ROM address 020cb48c. No matching claim. */
#include "types.h"
#include "deps/020cb48c_GXS_SetGraphicsMode__mkds_cb48c.h"

void GXS_SetGraphicsMode__mkds_cb48c(int param_1)

{
  *puRam020cb4a4 =
       (*(uint *)((uint)puRam020cb4a4 & 0xfffffffc) >> ((uint)puRam020cb4a4 & 3) * 8 |
       *(uint *)((uint)puRam020cb4a4 & 0xfffffffc) << ((uint)puRam020cb4a4 & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

