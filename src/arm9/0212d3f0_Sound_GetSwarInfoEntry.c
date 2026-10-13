/* Decompiled C draft; module arm9; ROM address 0212d3f0. No matching claim. */
#include "types.h"
#include "deps/0212d3f0_Sound_GetSwarInfoEntry.h"

int Sound_GetSwarInfoEntry(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  uVar5 = *(uint *)(uRam0212d450 & 0xfffffffc) >> (uRam0212d450 & 3) * 8 |
          *(uint *)(uRam0212d450 & 0xfffffffc) << (uRam0212d450 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x8c;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar3 = uVar4 + 0x14;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = uVar4 + uVar3;
  }
  if (uVar4 == 0) {
    return 0;
  }
  if ((int)param_1 < 0) {
    return 0;
  }
  if (param_1 < (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20)) {
    uVar3 = uVar4 + param_1 * 4 + 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar5 = uVar5 + 0x8c;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (uVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + uVar2;
    }
    return iVar1;
  }
  return 0;
}

