/* Decompiled C draft; module arm9; ROM address 020cc9fc. No matching claim. */
#include "types.h"
#include "deps/020cc9fc_SetNextTeamMode.h"

void SetNextTeamMode(undefined1 param_1)

{
  *(undefined1 *)
   ((*(uint *)(uRam020cca0c & 0xfffffffc) >> (uRam020cca0c & 3) * 8 |
    *(uint *)(uRam020cca0c & 0xfffffffc) << (uRam020cca0c & 3) * -8 + 0x20) + 0x240) = param_1;
  return;
}

