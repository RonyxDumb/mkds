/* Decompiled C draft; module arm9; ROM address 02149ee0. No matching claim. */
#include "types.h"
#include "deps/02149ee0_GetVramBg3BaseOffset_Top.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GetVramBg3BaseOffset_Top(void)

{
  if ((2 < (_DAT_04000000 & 7)) && ((5 < (_DAT_04000000 & 7) || ((*puRam02149f3c & 0x80) != 0)))) {
    return 0;
  }
  return ((_DAT_04000000 & 0x7000000) >> 0x18) * 0x10000 + 0x6000000 +
         ((*puRam02149f3c & 0x3c) >> 2) * 0x4000;
}

