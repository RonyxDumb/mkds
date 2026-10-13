/* Decompiled C draft; module arm9; ROM address 020617a8. No matching claim. */
#include "types.h"
#include "deps/020617a8_func_020617a8.h"

bool func_020617a8(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(uRam020617d4 & 0xfffffffc) >> (uRam020617d4 & 3) * 8 |
          *(uint *)(uRam020617d4 & 0xfffffffc) << (uRam020617d4 & 3) * -8 + 0x20;
  uVar3 = uVar2 + 0x3c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar2 = uVar2 + 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *param_1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - uVar3;
  }
  return uVar3 != 0;
}

