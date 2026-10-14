/* Decompiled C draft; module arm9; ROM address 02088338. No matching claim. */
#include "types.h"
#include "deps/02088338_FormatTeamEmblemNsbtx.h"

char * FormatTeamEmblemNsbtx(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02088380 + (uint)(param_1 == 0) * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  _snprintf(pcRam02088388,0x100,pcRam0208838c,
            *(uint *)(uRam02088384 & 0xfffffffc) >> (uRam02088384 & 3) * 8 |
            *(uint *)(uRam02088384 & 0xfffffffc) << (uRam02088384 & 3) * -8 + 0x20,
            uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return pcRam02088388;
}

