/* Decompiled C draft; module arm9; ROM address 02059c04. No matching claim. */
#include "types.h"
#include "deps/02059c04_IsAddressInOverlayRegion.h"

undefined4 IsAddressInOverlayRegion(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar3 = *(uint *)(uRam02059c30 & 0xfffffffc) >> (uRam02059c30 & 3) * 8 |
          *(uint *)(uRam02059c30 & 0xfffffffc) << (uRam02059c30 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0xa8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) <= param_1) &&
     (uVar3 = uVar3 + 0xac, uVar2 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     param_1 <= (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))) {
    uVar4 = 1;
  }
  return uVar4;
}

