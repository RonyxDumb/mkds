/* Decompiled C draft; module arm9; ROM address 020a02c8. No matching claim. */
#include "types.h"
#include "deps/020a02c8_func_020a02c8.h"

int func_020a02c8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = func_02100138(10);
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xa4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  return (int)(0x7f000 - (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) >> 0xc;
}

