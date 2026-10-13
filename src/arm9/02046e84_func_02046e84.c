/* Decompiled C draft; module arm9; ROM address 02046e84. No matching claim. */
#include "types.h"
#include "deps/02046e84_func_02046e84.h"

void func_02046e84(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam02046ee0 & 0xfffffffc) >> (uRam02046ee0 & 3) * 8 |
          *(uint *)(uRam02046ee0 & 0xfffffffc) << (uRam02046ee0 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x30;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((int)(uVar1 << 0x1e) < 0) {
    if (-1 < (int)(uVar1 << 0x1d)) {
      uVar3 = uVar3 + 0x3c;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      Struct59C4Sub_SomeFn_2(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    }
    uVar2 = *(uint *)(uRam02046ee0 & 0xfffffffc) >> (uRam02046ee0 & 3) * 8 |
            *(uint *)(uRam02046ee0 & 0xfffffffc) << (uRam02046ee0 & 3) * -8 + 0x20;
    uVar1 = uVar2 + 0x30;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(uVar2 + 0x30) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20 | 4;
    return;
  }
  return;
}

