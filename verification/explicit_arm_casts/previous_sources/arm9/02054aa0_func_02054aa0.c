/* Decompiled C draft; module arm9; ROM address 02054aa0. No matching claim. */
#include "types.h"
#include "deps/02054aa0_func_02054aa0.h"

void func_02054aa0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [12];
  
  uVar2 = *(uint *)(uRam02054b40 & 0xfffffffc) >> (uRam02054b40 & 3) * 8 |
          *(uint *)(uRam02054b40 & 0xfffffffc) << (uRam02054b40 & 3) * -8 + 0x20;
  uVar3 = uVar2 + 4 & 3;
  uVar1 = *(uint *)(uVar2 + 4 & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 0xb) {
    return;
  }
  uVar3 = uVar2 + 0xc & 3;
  uVar1 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 0x2c) {
    uVar3 = uVar2 + 0x1da0 & 3;
    uVar1 = *(uint *)(uVar2 + 0x1da0 & 0xfffffffc);
    uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    func_02006f50(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20,0,auStack_10,auStack_c);
  }
  uVar3 = *(uint *)(uRam02054b40 & 0xfffffffc) >> (uRam02054b40 & 3) * 8 |
          *(uint *)(uRam02054b40 & 0xfffffffc) << (uRam02054b40 & 3) * -8 + 0x20;
  if (*(short *)(uVar3 + 0x1e42) == 0) {
    if (uVar3 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    }
    if (uVar3 != 0) {
      func_0204ed84();
      return;
    }
    return;
  }
  *(short *)(uVar3 + 0x1e42) = *(short *)(uVar3 + 0x1e42) + -1;
  return;
}

