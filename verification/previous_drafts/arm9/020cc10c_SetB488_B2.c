/* Decompiled C draft; module arm9; ROM address 020cc10c. No matching claim. */
#include "types.h"
#include "deps/020cc10c_SetB488_B2.h"

void SetB488_B2(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cc11c & 0xfffffffc) >> (uRam020cc11c & 3) * 8 |
    *(uint *)(uRam020cc11c & 0xfffffffc) << (uRam020cc11c & 3) * -8 + 0x20) + 4) = param_1;
  return;
}

