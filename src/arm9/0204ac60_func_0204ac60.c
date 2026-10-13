/* Decompiled C draft; module arm9; ROM address 0204ac60. No matching claim. */
#include "types.h"
#include "deps/0204ac60_func_0204ac60.h"

void func_0204ac60(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam0204acc8;
  uVar4 = *(uint *)(uRam0204acc8 & 0xfffffffc) >> (uRam0204acc8 & 3) * 8 |
          *(uint *)(uRam0204acc8 & 0xfffffffc) << (uRam0204acc8 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x1c;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (-1 < (int)(uVar2 << 0x1e)) {
    return;
  }
  if (-1 < (int)(uVar2 << 0x1f)) {
    *(uint *)(uVar4 + 0x1c) = uVar2 & 0xfffffffe | 1;
    uVar2 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    func_0210dcb8((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 8,
                  *(uint *)(uRam0204accc & 0xfffffffc) >> (uRam0204accc & 3) * 8 |
                  *(uint *)(uRam0204accc & 0xfffffffc) << (uRam0204accc & 3) * -8 + 0x20);
    return;
  }
  return;
}

