/* Decompiled C draft; module arm9; ROM address 020cab58. No matching claim. */
#include "types.h"
#include "deps/020cab58_GXS_SetGraphicsMode__mkds_cab58.h"

void GXS_SetGraphicsMode__mkds_cab58(int param_1)

{
  *puRam020cab70 =
       (*(uint *)((uint)puRam020cab70 & 0xfffffffc) >> ((uint)puRam020cab70 & 3) * 8 |
       *(uint *)((uint)puRam020cab70 & 0xfffffffc) << ((uint)puRam020cab70 & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

