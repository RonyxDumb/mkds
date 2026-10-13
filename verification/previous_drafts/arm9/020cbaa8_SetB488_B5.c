/* Decompiled C draft; module arm9; ROM address 020cbaa8. No matching claim. */
#include "types.h"
#include "deps/020cbaa8_SetB488_B5.h"

void SetB488_B5(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cbab8 & 0xfffffffc) >> (uRam020cbab8 & 3) * 8 |
    *(uint *)(uRam020cbab8 & 0xfffffffc) << (uRam020cbab8 & 3) * -8 + 0x20) + 0x10) = param_1;
  return;
}

