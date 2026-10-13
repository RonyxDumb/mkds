/* Decompiled C draft; module arm9; ROM address 020b57e4. No matching claim. */
#include "types.h"
#include "deps/020b57e4_func_020b57e4.h"

uint func_020b57e4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b57f4 & 0xfffffffc) >> (uRam020b57f4 & 3) * 8 |
          *(uint *)(uRam020b57f4 & 0xfffffffc) << (uRam020b57f4 & 3) * -8 + 0x20) + 0x2c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

