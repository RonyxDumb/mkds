/* Decompiled C draft; module arm9; ROM address 020c4e48. No matching claim. */
#include "types.h"
#include "deps/020c4e48_LoadRaceIntroDataOam.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadRaceIntroDataOam(void)

{
  int iVar1;
  
  Arm_FlushRange((*(uint *)(uRam020c4f00 & 0xfffffffc) >> (uRam020c4f00 & 3) * 8 |
                 *(uint *)(uRam020c4f00 & 0xfffffffc) << (uRam020c4f00 & 3) * -8 + 0x20) + 0x18,
                 0x400);
  CopyToOamA((*(uint *)(uRam020c4f00 & 0xfffffffc) >> (uRam020c4f00 & 3) * 8 |
             *(uint *)(uRam020c4f00 & 0xfffffffc) << (uRam020c4f00 & 3) * -8 + 0x20) + 0x18,0,0x400)
  ;
  iVar1 = (int)(*puRam020c4f04 & 0x8000) >> 0xf;
  if (iVar1 == 0) {
    _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | ((_DAT_04000000 & 0x1f00) >> 8 & 0xffffffef) << 8;
    return;
  }
  if (iVar1 == 1) {
    _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | ((_DAT_04000000 & 0x1f00) >> 8 | 0x10) << 8;
    return;
  }
  return;
}

