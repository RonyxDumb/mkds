/* Decompiled C draft; module arm9; ROM address 02088390. No matching claim. */
#include "types.h"
#include "deps/02088390_FormatEmblemNsbtx.h"

char * FormatEmblemNsbtx(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam020883d4 + param_1 * 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  _snprintf(pcRam020883dc,0x100,pcRam020883e0,
            *(uint *)(uRam020883d8 & 0xfffffffc) >> (uRam020883d8 & 3) * 8 |
            *(uint *)(uRam020883d8 & 0xfffffffc) << (uRam020883d8 & 3) * -8 + 0x20,
            uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return pcRam020883dc;
}

