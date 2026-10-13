/* Decompiled C draft; module arm9; ROM address 0204ffe8. No matching claim. */
#include "types.h"
#include "deps/0204ffe8_func_0204ffe8.h"

undefined2 func_0204ffe8(int param_1)

{
  uint uVar1;
  bool bVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  
  bVar2 = false;
  uVar5 = *(uint *)(uRam02050030 & 0xfffffffc) >> (uRam02050030 & 3) * 8 |
          *(uint *)(uRam02050030 & 0xfffffffc) << (uRam02050030 & 3) * -8 + 0x20;
  uVar4 = uVar5 + 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  if ((uVar4 == 8) || (uVar4 == 9)) {
    bVar2 = true;
  }
  if (bVar2) {
    uVar5 = uVar5 + 0x15c8;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar3 = *(undefined2 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + param_1 * 8);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

