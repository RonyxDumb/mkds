/* Decompiled C draft; module arm9; ROM address 020ad834. No matching claim. */
#include "types.h"
#include "deps/020ad834_SetCurrentMissionNotBeaten.h"

void SetCurrentMissionNotBeaten(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ad844 & 0xfffffffc) >> (uRam020ad844 & 3) * 8 |
    *(uint *)(uRam020ad844 & 0xfffffffc) << (uRam020ad844 & 3) * -8 + 0x20) + 0x10) = param_1;
  return;
}

