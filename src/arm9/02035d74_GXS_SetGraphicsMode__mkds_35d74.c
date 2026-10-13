/* Decompiled C draft; module arm9; ROM address 02035d74. No matching claim. */
#include "types.h"
#include "deps/02035d74_GXS_SetGraphicsMode__mkds_35d74.h"

void GXS_SetGraphicsMode__mkds_35d74(int param_1)

{
  *puRam02035d8c =
       (*(uint *)((uint)puRam02035d8c & 0xfffffffc) >> ((uint)puRam02035d8c & 3) * 8 |
       *(uint *)((uint)puRam02035d8c & 0xfffffffc) << ((uint)puRam02035d8c & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

