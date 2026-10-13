/* Decompiled C draft; module arm9; ROM address 020ad8e0. No matching claim. */
#include "types.h"
#include "deps/020ad8e0_SetDispcntSubDisplayFrameSelect.h"

void SetDispcntSubDisplayFrameSelect(uint param_1)

{
  *puRam020ad8fc =
       (*(uint *)((uint)puRam020ad8fc & 0xfffffffc) >> ((uint)puRam020ad8fc & 3) * 8 |
       *(uint *)((uint)puRam020ad8fc & 0xfffffffc) << ((uint)puRam020ad8fc & 3) * -8 + 0x20) &
       uRam020ad900 | param_1;
  return;
}

