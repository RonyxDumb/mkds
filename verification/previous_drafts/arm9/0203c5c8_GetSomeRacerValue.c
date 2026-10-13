/* Decompiled C draft; module arm9; ROM address 0203c5c8. No matching claim. */
#include "types.h"
#include "deps/0203c5c8_GetSomeRacerValue.h"

uint GetSomeRacerValue(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x8c +
          (*(uint *)(uRam0203c5e0 & 0xfffffffc) >> (uRam0203c5e0 & 3) * 8 |
          *(uint *)(uRam0203c5e0 & 0xfffffffc) << (uRam0203c5e0 & 3) * -8 + 0x20) + 0x58;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

