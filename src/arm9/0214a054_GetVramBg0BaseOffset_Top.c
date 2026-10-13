/* Decompiled C draft; module arm9; ROM address 0214a054. No matching claim. */
#include "types.h"
#include "deps/0214a054_GetVramBg0BaseOffset_Top.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GetVramBg0BaseOffset_Top(void)

{
  return ((_DAT_04000000 & 0x7000000) >> 0x18) * 0x10000 + 0x6000000 +
         ((int)(*puRam0214a084 & 0x3c) >> 2) * 0x4000;
}

