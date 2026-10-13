/* Decompiled C draft; module arm9; ROM address 020617d8. No matching claim. */
#include "types.h"
#include "deps/020617d8_func_020617d8.h"

void func_020617d8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020617ec & 0xfffffffc) >> (uRam020617ec & 3) * 8 |
          *(uint *)(uRam020617ec & 0xfffffffc) << (uRam020617ec & 3) * -8 + 0x20;
  uVar2 = uVar3 + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x3c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

