/* Decompiled C draft; module arm9; ROM address 020b2d54. No matching claim. */
#include "types.h"
#include "deps/020b2d54_func_020b2d54.h"

uint func_020b2d54(void)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = GetCurrentPlayerRacerId_0();
  iVar3 = IsRacerFinishedRace(uVar2);
  if (iVar3 == 0) {
    uVar4 = 6;
  }
  else {
    uVar4 = (*(uint *)(uRam020b2d8c & 0xfffffffc) >> (uRam020b2d8c & 3) * 8 |
            *(uint *)(uRam020b2d8c & 0xfffffffc) << (uRam020b2d8c & 3) * -8 + 0x20) + 0x4e0;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  }
  return uVar4;
}

