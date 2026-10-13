/* Decompiled C draft; module arm9; ROM address 020b4d9c. No matching claim. */
#include "types.h"
#include "deps/020b4d9c_GetCurrentPlayerRacerId.h"

ushort GetCurrentPlayerRacerId(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020b4dc0 & 0xfffffffc) >> (uRam020b4dc0 & 3) * 8 |
          *(uint *)(uRam020b4dc0 & 0xfffffffc) << (uRam020b4dc0 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0xc & 3;
  uVar3 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) {
    uVar2 = (ushort)*(byte *)(uVar4 + 99);
  }
  else {
    uVar2 = (ushort)*(char *)(uVar4 + 0x62);
  }
  return uVar2;
}

