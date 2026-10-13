/* Decompiled C draft; module arm9; ROM address 020cca4c. No matching claim. */
#include "types.h"
#include "deps/020cca4c_SetNextCcMode.h"

void SetNextCcMode(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cca5c & 0xfffffffc) >> (uRam020cca5c & 3) * 8 |
    *(uint *)(uRam020cca5c & 0xfffffffc) << (uRam020cca5c & 3) * -8 + 0x20) + 0x1f8) = param_1;
  return;
}

