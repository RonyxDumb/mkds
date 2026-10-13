/* Decompiled C draft; module arm9; ROM address 020cc9bc. No matching claim. */
#include "types.h"
#include "deps/020cc9bc_SetNextCourseMode.h"

void SetNextCourseMode(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cc9cc & 0xfffffffc) >> (uRam020cc9cc & 3) * 8 |
    *(uint *)(uRam020cc9cc & 0xfffffffc) << (uRam020cc9cc & 3) * -8 + 0x20) + 0x208) = param_1;
  return;
}

