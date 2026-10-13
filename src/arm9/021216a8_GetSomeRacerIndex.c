/* Decompiled C draft; module arm9; ROM address 021216a8. No matching claim. */
#include "types.h"
#include "deps/021216a8_GetSomeRacerIndex.h"

uint GetSomeRacerIndex(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = uRam021217e4;
  uVar3 = *(uint *)(uRam021217e4 & 0xfffffffc) >> (uRam021217e4 & 3) * 8 |
          *(uint *)(uRam021217e4 & 0xfffffffc) << (uRam021217e4 & 3) * -8 + 0x20;
  if (*(byte *)(uVar3 + 0x19ac) < 2) {
    *(byte *)(uVar3 + 0x19ac) = *(byte *)(uVar3 + 0x19ac) + 1;
    return (uint)*(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                           *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1f53);
  }
  uVar5 = (uint)*(byte *)(uVar3 + 0x1999);
  if (uVar5 < *(byte *)(uVar3 + 0x1f53)) {
    do {
      uVar3 = func_0x0219bb50();
      if ((uVar5 != uVar3) &&
         (uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
         ((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar5) != 0)) break;
      uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < *(byte *)(uVar3 + 0x1f53));
  }
  uVar2 = uRam021217e4;
  uVar4 = *(uint *)(uRam021217e4 & 0xfffffffc) >> (uRam021217e4 & 3) * 8 |
          *(uint *)(uRam021217e4 & 0xfffffffc) << (uRam021217e4 & 3) * -8 + 0x20;
  bVar1 = *(byte *)(uVar4 + 0x1999);
  if (*(byte *)(uVar4 + 0x1f53) <= bVar1) {
    uVar5 = 0;
    if (bVar1 != 0) {
      do {
        uVar3 = func_0x0219bb50();
        if ((uVar5 != uVar3) &&
           (uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
           ((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar5) != 0)) break;
        uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < *(byte *)(uVar3 + 0x1999));
    }
    if (*(byte *)(uVar3 + 0x1999) <= uVar5) {
      return (uint)*(byte *)(uVar3 + 0x1f53);
    }
  }
  uVar4 = uRam021217e4;
  *(char *)(uVar3 + 0x1999) = (char)uVar5 + '\x01';
  uVar2 = uVar4 & 3;
  uVar3 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined1 *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x19ac) = 0;
  return uVar5;
}

