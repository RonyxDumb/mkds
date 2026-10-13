/* Decompiled C draft; module arm9; ROM address 0211fe24. No matching claim. */
#include "types.h"
#include "deps/0211fe24_func_0211fe24.h"

void func_0211fe24(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0211fe40 & 0xfffffffc) >> (uRam0211fe40 & 3) * 8 |
          *(uint *)(uRam0211fe40 & 0xfffffffc) << (uRam0211fe40 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar1 + 0x18) = 1;
  *(undefined2 *)(uVar1 + 0x1a) = 1;
  return;
}

