/* Decompiled C draft; module arm9; ROM address 020ceb54. No matching claim. */
#include "types.h"
#include "deps/020ceb54_GXS_SetGraphicsMode__mkds_ceb54.h"

void GXS_SetGraphicsMode__mkds_ceb54(int param_1)

{
  *puRam020ceb6c =
       (*(uint *)((uint)puRam020ceb6c & 0xfffffffc) >> ((uint)puRam020ceb6c & 3) * 8 |
       *(uint *)((uint)puRam020ceb6c & 0xfffffffc) << ((uint)puRam020ceb6c & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

