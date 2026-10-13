/* Decompiled C draft; module arm9; ROM address 020cca60. No matching claim. */
#include "types.h"
#include "deps/020cca60_SetNextCourse.h"

void SetNextCourse(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cca70 & 0xfffffffc) >> (uRam020cca70 & 3) * 8 |
    *(uint *)(uRam020cca70 & 0xfffffffc) << (uRam020cca70 & 3) * -8 + 0x20) + 0x1e8) = param_1;
  return;
}

