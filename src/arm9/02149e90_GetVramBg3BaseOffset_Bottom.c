/* Decompiled C draft; module arm9; ROM address 02149e90. No matching claim. */
#include "types.h"
#include "deps/02149e90_GetVramBg3BaseOffset_Bottom.h"

int GetVramBg3BaseOffset_Bottom(void)

{
  uint uVar1;
  
  uVar1 = (*(uint *)(uRam02149ed8 & 0xfffffffc) >> (uRam02149ed8 & 3) * 8 |
          *(uint *)(uRam02149ed8 & 0xfffffffc) << (uRam02149ed8 & 3) * -8 + 0x20) & 7;
  if ((2 < uVar1) && ((5 < uVar1 || ((*puRam02149edc & 0x80) != 0)))) {
    return 0;
  }
  return ((*puRam02149edc & 0x3c) >> 2) * 0x4000 + 0x6200000;
}

