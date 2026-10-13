/* Decompiled C draft; module arm9; ROM address 0205e548. No matching claim. */
#include "types.h"
#include "deps/0205e548_func_0205e548.h"

/* WARNING: Removing unreachable block (ram,0x0205e568) */

char func_0205e548(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  
  cVar2 = '\0';
  uVar4 = 0;
  do {
    uVar3 = (*(uint *)(uRam0205e5c0 & 0xfffffffc) >> (uRam0205e5c0 & 3) * 8 |
            *(uint *)(uRam0205e5c0 & 0xfffffffc) << (uRam0205e5c0 & 3) * -8 + 0x20) + 0x20;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((int)((uint)*(byte *)(uVar4 * 0x24 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) +
                             0x26) << 0x1f) < 0) {
      cVar2 = cVar2 + '\x01';
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x3c);
  return cVar2;
}

