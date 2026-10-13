/* Decompiled C draft; module arm9; ROM address 020cc9e4. No matching claim. */
#include "types.h"
#include "deps/020cc9e4_MaybeSetNextRuleParam.h"

void MaybeSetNextRuleParam(undefined2 param_1)

{
  *(undefined2 *)
   ((*(uint *)(uRam020cc9f8 & 0xfffffffc) >> (uRam020cc9f8 & 3) * 8 |
    *(uint *)(uRam020cc9f8 & 0xfffffffc) << (uRam020cc9f8 & 3) * -8 + 0x20) + 0x3d8) = param_1;
  return;
}

