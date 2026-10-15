/* Decompiled C draft; module arm9; ROM address 020c4bb0. No matching claim. */
#include "types.h"
#include "deps/020c4bb0_IncrementRaceIntroFrameCounter.h"

undefined2 IncrementRaceIntroFrameCounter(void)

{
  undefined2 *puVar1;
  int *piVar2;
  
  puVar1 = puRam020c4bd4;
  piVar2 = (int *)(*(uint *)(uRam020c4bd0 & 0xfffffffc) >> (uRam020c4bd0 & 3) * 8 |
                  *(uint *)(uRam020c4bd0 & 0xfffffffc) << (uRam020c4bd0 & 3) * -8 + 0x20);
  *piVar2 = (*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
            *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) + 1;
  return *puVar1;
}

