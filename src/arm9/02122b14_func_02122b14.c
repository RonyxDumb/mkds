/* Decompiled C draft; module arm9; ROM address 02122b14. No matching claim. */
#include "types.h"
#include "deps/02122b14_func_02122b14.h"

void func_02122b14(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar6;
  bool bVar7;
  uint uVar5;
  
  uVar1 = uRam02122bec;
  uVar3 = 0xff;
  uVar2 = *(uint *)(uRam02122bec & 0xfffffffc) >> (uRam02122bec & 3) * 8 |
          *(uint *)(uRam02122bec & 0xfffffffc) << (uRam02122bec & 3) * -8 + 0x20;
  uVar5 = uVar2 + 0x1950 & 3;
  uVar4 = *(uint *)(uVar2 + 0x1950 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < 5) {
    return;
  }
  if ((int)uVar5 < 9) {
    uVar5 = 0;
    if (*(char *)(uVar2 + 0x1f53) != '\0') {
      do {
        uVar4 = (uint)*(byte *)(uVar2 + 0x1f55) & 1 << uVar5;
        bVar7 = uVar4 != 0;
        if (bVar7) {
          uVar4 = (uint)*(byte *)(uVar5 * 0x44 + uVar2 + 0x1e1a);
        }
        uVar5 = uVar5 + 1 & 0xff;
        if (bVar7) {
          uVar3 = uVar3 & uVar4;
        }
      } while (uVar5 < *(byte *)(uVar2 + 0x1f53));
    }
    bVar6 = 0;
    if (*(char *)(uVar2 + 0x1f53) != '\0') {
      do {
        uVar5 = 1 << bVar6;
        if (((*(byte *)(uVar2 + 0x1f55) & uVar5) != 0) && ((uVar3 & uVar5) == 0)) {
          *(byte *)(uVar2 + 0x1f56) = *(byte *)(uVar2 + 0x1f56) | (byte)uVar5;
        }
        uVar5 = uVar1 & 3;
        uVar2 = *(uint *)(uVar1 & 0xfffffffc);
        uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
        bVar6 = bVar6 + 1;
      } while (bVar6 < *(byte *)(uVar2 + 0x1f53));
      return;
    }
    return;
  }
  return;
}

