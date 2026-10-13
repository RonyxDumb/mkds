/* Decompiled C draft; module arm9; ROM address 020ad9fc. No matching claim. */
#include "types.h"
#include "deps/020ad9fc_GetB488TitleMenuSkipIntro.h"

uint GetB488TitleMenuSkipIntro(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020ada0c & 0xfffffffc) >> (uRam020ada0c & 3) * 8 |
          *(uint *)(uRam020ada0c & 0xfffffffc) << (uRam020ada0c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

