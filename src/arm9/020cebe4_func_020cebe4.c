/* Decompiled C draft; module arm9; ROM address 020cebe4. No matching claim. */
#include "types.h"
#include "deps/020cebe4_func_020cebe4.h"

int func_020cebe4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cebfc & 0xfffffffc) >> (uRam020cebfc & 3) * 8 |
          *(uint *)(uRam020cebfc & 0xfffffffc) << (uRam020cebfc & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1d) >> 0x1f;
}

