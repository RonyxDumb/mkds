/* Decompiled C draft; module arm9; ROM address 020b2a60. No matching claim. */
#include "types.h"
#include "deps/020b2a60_SetB488_B6.h"

void SetB488_B6(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020b2a70 & 0xfffffffc) >> (uRam020b2a70 & 3) * 8 |
    *(uint *)(uRam020b2a70 & 0xfffffffc) << (uRam020b2a70 & 3) * -8 + 0x20) + 0x14) = param_1;
  return;
}

