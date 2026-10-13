/* Decompiled C draft; module arm9; ROM address 0205d140. No matching claim. */
#include "types.h"
#include "deps/0205d140_ComputeMissionInternalScore.h"

undefined4 ComputeMissionInternalScore(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (*(uint *)(uRam0205d18c & 0xfffffffc) >> (uRam0205d18c & 3) * 8 |
          *(uint *)(uRam0205d18c & 0xfffffffc) << (uRam0205d18c & 3) * -8 + 0x20) + 0x140;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (99 < (int)uVar2) {
    return 7;
  }
  if (0x59 < (int)uVar2) {
    return 6;
  }
  if (0x45 < (int)uVar2) {
    return 5;
  }
  if ((int)uVar2 < 0x32) {
    if ((int)uVar2 < 0) {
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
    }
    return uVar3;
  }
  return 4;
}

