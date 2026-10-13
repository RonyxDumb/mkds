/* Decompiled C draft; module arm9; ROM address 02053e54. No matching claim. */
#include "types.h"
#include "deps/02053e54_func_02053e54.h"

void func_02053e54(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam02053e70 & 0xfffffffc) >> (uRam02053e70 & 3) * 8 |
          *(uint *)(uRam02053e70 & 0xfffffffc) << (uRam02053e70 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x454) = *(ushort *)(uVar1 + 0x454) & 0xfff7;
  return;
}

