/* Decompiled C draft; module arm9; ROM address 020ce744. No matching claim. */
#include "types.h"
#include "deps/020ce744_GXS_SetGraphicsMode__mkds_ce744.h"

void GXS_SetGraphicsMode__mkds_ce744(int param_1)

{
  *puRam020ce75c =
       (*(uint *)((uint)puRam020ce75c & 0xfffffffc) >> ((uint)puRam020ce75c & 3) * 8 |
       *(uint *)((uint)puRam020ce75c & 0xfffffffc) << ((uint)puRam020ce75c & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

