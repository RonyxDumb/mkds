/* Decompiled C draft; module arm9; ROM address 02061fb8. No matching claim. */
#include "types.h"
#include "deps/02061fb8_GetSomeTimeOrDuration.h"

uint GetSomeTimeOrDuration(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02061fc8 & 0xfffffffc) >> (uRam02061fc8 & 3) * 8 |
          *(uint *)(uRam02061fc8 & 0xfffffffc) << (uRam02061fc8 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

