/* Decompiled C draft; module arm9; ROM address 020acab8. No matching claim. */
#include "types.h"
#include "deps/020acab8_SetSystemContextOverlayState.h"

void SetSystemContextOverlayState(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020acac8 & 0xfffffffc) >> (uRam020acac8 & 3) * 8 |
    *(uint *)(uRam020acac8 & 0xfffffffc) << (uRam020acac8 & 3) * -8 + 0x20) + 0x20) = param_1;
  return;
}

