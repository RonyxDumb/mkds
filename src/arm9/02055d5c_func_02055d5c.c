/* Decompiled C draft; module arm9; ROM address 02055d5c. No matching claim. */
#include "types.h"
#include "deps/02055d5c_func_02055d5c.h"

void func_02055d5c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam02055e40;
  uVar3 = *(uint *)(uRam02055e40 & 0xfffffffc) >> (uRam02055e40 & 3) * 8 |
          *(uint *)(uRam02055e40 & 0xfffffffc) << (uRam02055e40 & 3) * -8 + 0x20;
  uVar4 = (uint)*(byte *)(uVar3 + 10);
  uVar3 = uVar3 + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar4 + ((int)((0x10 - uVar4) * (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) >> 0xc)
          & 0xff;
  *puRam02055e48 = uVar3 | uRam02055e44 | (0x10 - uVar3 & 0xff) << 8;
  if (param_1 != 0) {
    return;
  }
  uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar3 + 8) & 2) != 0) {
    uVar1 = uVar3 + 0xc & 3;
    uVar4 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
    uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    if (0 < (int)uVar1) {
      *(uint *)(uVar3 + 0xc) = uVar1 - iRam02055e4c;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar3 = uVar2 + 0xc;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0) {
        *(undefined4 *)(uVar2 + 0xc) = 0;
      }
      return;
    }
    return;
  }
  uVar1 = uVar3 + 0xc & 3;
  uVar4 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
  uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  if ((int)uVar1 < 0x1000) {
    *(uint *)(uVar3 + 0xc) = uVar1 + iRam02055e50;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    uVar3 = uVar2 + 0xc;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (0x1000 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      *(undefined4 *)(uVar2 + 0xc) = 0x1000;
    }
    return;
  }
  return;
}

