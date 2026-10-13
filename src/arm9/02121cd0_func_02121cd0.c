/* Decompiled C draft; module arm9; ROM address 02121cd0. No matching claim. */
#include "types.h"
#include "deps/02121cd0_func_02121cd0.h"

undefined4 func_02121cd0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(uRam02121d08 & 0xfffffffc) >> (uRam02121d08 & 3) * 8 |
          *(uint *)(uRam02121d08 & 0xfffffffc) << (uRam02121d08 & 3) * -8 + 0x20;
  uVar3 = uVar2 + 0x1950;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (9 < (int)uVar3) {
    return 1;
  }
  if ((*(char *)(uVar2 + 0x19ad) == '\x01') && (uVar3 == 0xc)) {
    return 1;
  }
  return 0;
}

