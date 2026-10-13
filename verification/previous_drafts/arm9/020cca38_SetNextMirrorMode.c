/* Decompiled C draft; module arm9; ROM address 020cca38. No matching claim. */
#include "types.h"
#include "deps/020cca38_SetNextMirrorMode.h"

void SetNextMirrorMode(undefined1 param_1)

{
  *(undefined1 *)
   ((*(uint *)(uRam020cca48 & 0xfffffffc) >> (uRam020cca48 & 3) * 8 |
    *(uint *)(uRam020cca48 & 0xfffffffc) << (uRam020cca48 & 3) * -8 + 0x20) + 0x23f) = param_1;
  return;
}

