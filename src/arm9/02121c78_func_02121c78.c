/* Decompiled C draft; module arm9; ROM address 02121c78. No matching claim. */
#include "types.h"
#include "deps/02121c78_func_02121c78.h"

undefined4 func_02121c78(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(uRam02121ccc & 0xfffffffc) >> (uRam02121ccc & 3) * 8 |
          *(uint *)(uRam02121ccc & 0xfffffffc) << (uRam02121ccc & 3) * -8 + 0x20;
  uVar4 = uVar1 + 0x1950 & 3;
  uVar3 = *(uint *)(uVar1 + 0x1950 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (4 < (int)uVar4) {
    if (*(byte *)(uVar1 + 0x1f52) < 2) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
    return uVar2;
  }
  if ((*(char *)(uVar1 + 0x19ad) == '\x01') && (uVar4 == 0xc)) {
    return 2;
  }
  if (uVar4 == 0xc) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

