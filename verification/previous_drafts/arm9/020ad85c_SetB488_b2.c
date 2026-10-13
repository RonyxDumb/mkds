/* Decompiled C draft; module arm9; ROM address 020ad85c. No matching claim. */
#include "types.h"
#include "deps/020ad85c_SetB488_b2.h"

void SetB488_b2(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ad86c & 0xfffffffc) >> (uRam020ad86c & 3) * 8 |
    *(uint *)(uRam020ad86c & 0xfffffffc) << (uRam020ad86c & 3) * -8 + 0x20) + 4) = param_1;
  return;
}

