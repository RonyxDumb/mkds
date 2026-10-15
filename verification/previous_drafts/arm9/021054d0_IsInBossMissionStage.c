/* Decompiled C draft; module arm9; ROM address 021054d0. No matching claim. */
#include "types.h"
#include "deps/021054d0_IsInBossMissionStage.h"

/* WARNING: Removing unreachable block (ram,0x021054f0) */

bool IsInBossMissionStage(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam02105500 & 0xfffffffc) >> (uRam02105500 & 3) * 8 |
          *(uint *)(uRam02105500 & 0xfffffffc) << (uRam02105500 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 4) {
    return false;
  }
  return *(char *)(uVar3 + 0x55) == '\t';
}

