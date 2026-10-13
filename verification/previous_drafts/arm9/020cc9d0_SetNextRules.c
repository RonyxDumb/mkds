/* Decompiled C draft; module arm9; ROM address 020cc9d0. No matching claim. */
#include "types.h"
#include "deps/020cc9d0_SetNextRules.h"

void SetNextRules(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cc9e0 & 0xfffffffc) >> (uRam020cc9e0 & 3) * 8 |
    *(uint *)(uRam020cc9e0 & 0xfffffffc) << (uRam020cc9e0 & 3) * -8 + 0x20) + 0x204) = param_1;
  return;
}

