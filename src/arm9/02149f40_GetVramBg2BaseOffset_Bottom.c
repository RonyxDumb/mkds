/* Decompiled C draft; module arm9; ROM address 02149f40. No matching claim. */
#include "types.h"
#include "deps/02149f40_GetVramBg2BaseOffset_Bottom.h"

int GetVramBg2BaseOffset_Bottom(void)

{
  if ((4 < ((*(uint *)(uRam02149f80 & 0xfffffffc) >> (uRam02149f80 & 3) * 8 |
            *(uint *)(uRam02149f80 & 0xfffffffc) << (uRam02149f80 & 3) * -8 + 0x20) & 7)) &&
     ((*puRam02149f84 & 0x80) != 0)) {
    return 0;
  }
  return ((*puRam02149f84 & 0x3c) >> 2) * 0x4000 + 0x6200000;
}

