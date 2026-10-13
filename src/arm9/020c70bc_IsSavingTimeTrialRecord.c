/* Decompiled C draft; module arm9; ROM address 020c70bc. No matching claim. */
#include "types.h"
#include "deps/020c70bc_IsSavingTimeTrialRecord.h"

uint IsSavingTimeTrialRecord(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020c70d4 & 0xfffffffc) >> (uRam020c70d4 & 3) * 8 |
          *(uint *)(uRam020c70d4 & 0xfffffffc) << (uRam020c70d4 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar2 + 0x18;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

