/* Decompiled C draft; module arm9; ROM address 02122ae4. No matching claim. */
#include "types.h"
#include "deps/02122ae4_func_02122ae4.h"

bool func_02122ae4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam02122b10 & 0xfffffffc) >> (uRam02122b10 & 3) * 8 |
          *(uint *)(uRam02122b10 & 0xfffffffc) << (uRam02122b10 & 3) * -8 + 0x20;
  if (*(char *)(uVar2 + 0x19ad) != '\x01') {
    return false;
  }
  uVar2 = uVar2 + 0x1950;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0xc;
}

