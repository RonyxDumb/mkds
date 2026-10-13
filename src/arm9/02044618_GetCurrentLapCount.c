/* Decompiled C draft; module arm9; ROM address 02044618. No matching claim. */
#include "types.h"
#include "deps/02044618_GetCurrentLapCount.h"

uint GetCurrentLapCount(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam02044654 & 0xfffffffc) >> (uRam02044654 & 3) * 8 |
          *(uint *)(uRam02044654 & 0xfffffffc) << (uRam02044654 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 2) {
    uVar2 = (uint)*(char *)(uVar3 + 100);
    if ((int)uVar2 < 1) {
      uVar2 = (*(uint *)(uRam02044658 & 0xfffffffc) >> (uRam02044658 & 3) * 8 |
              *(uint *)(uRam02044658 & 0xfffffffc) << (uRam02044658 & 3) * -8 + 0x20) + 0x18;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = (uint)*(ushort *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 2);
    }
    else {
      uVar2 = uVar2 & 0xffff;
    }
    return uVar2;
  }
  return 1;
}

