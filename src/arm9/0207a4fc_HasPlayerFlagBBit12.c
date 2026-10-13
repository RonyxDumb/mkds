/* Decompiled C draft; module arm9; ROM address 0207a4fc. No matching claim. */
#include "types.h"
#include "deps/0207a4fc_HasPlayerFlagBBit12.h"

bool HasPlayerFlagBBit12(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(char *)((*(uint *)(uRam0207a52c & 0xfffffffc) >> (uRam0207a52c & 3) * 8 |
                    *(uint *)(uRam0207a52c & 0xfffffffc) << (uRam0207a52c & 3) * -8 + 0x20) + 0x62)
          * iRam0207a534 +
          (*(uint *)(uRam0207a530 & 0xfffffffc) >> (uRam0207a530 & 3) * 8 |
          *(uint *)(uRam0207a530 & 0xfffffffc) << (uRam0207a530 & 3) * -8 + 0x20) + 0x48;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x1000) != 0;
}

