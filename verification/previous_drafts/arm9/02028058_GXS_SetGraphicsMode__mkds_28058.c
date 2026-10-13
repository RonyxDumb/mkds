/* Decompiled C draft; module arm9; ROM address 02028058. No matching claim. */
#include "types.h"
#include "deps/02028058_GXS_SetGraphicsMode__mkds_28058.h"

void GXS_SetGraphicsMode__mkds_28058(int param_1)

{
  *puRam02028070 =
       (*(uint *)((uint)puRam02028070 & 0xfffffffc) >> ((uint)puRam02028070 & 3) * 8 |
       *(uint *)((uint)puRam02028070 & 0xfffffffc) << ((uint)puRam02028070 & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

