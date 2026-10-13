/* Decompiled C draft; module arm9; ROM address 020ad820. No matching claim. */
#include "types.h"
#include "deps/020ad820_SetB488_b6.h"

void SetB488_b6(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ad830 & 0xfffffffc) >> (uRam020ad830 & 3) * 8 |
    *(uint *)(uRam020ad830 & 0xfffffffc) << (uRam020ad830 & 3) * -8 + 0x20) + 0x14) = param_1;
  return;
}

