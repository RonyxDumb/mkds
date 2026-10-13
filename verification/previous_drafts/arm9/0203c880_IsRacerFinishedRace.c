/* Decompiled C draft; module arm9; ROM address 0203c880. No matching claim. */
#include "types.h"
#include "deps/0203c880_IsRacerFinishedRace.h"

undefined4 IsRacerFinishedRace(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = param_1 * 0x8c +
          (*(uint *)(uRam0203c8bc & 0xfffffffc) >> (uRam0203c8bc & 3) * 8 |
          *(uint *)(uRam0203c8bc & 0xfffffffc) << (uRam0203c8bc & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (((uVar2 == 1) || (uVar2 == 2)) || (uVar2 == 3)) {
    uVar3 = 1;
  }
  return uVar3;
}

