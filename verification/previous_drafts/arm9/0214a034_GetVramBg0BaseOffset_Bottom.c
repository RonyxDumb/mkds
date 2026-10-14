/* Decompiled C draft; module arm9; ROM address 0214a034. No matching claim. */
#include "types.h"
#include "deps/0214a034_GetVramBg0BaseOffset_Bottom.h"

int GetVramBg0BaseOffset_Bottom(void)

{
  return ((int)(*puRam0214a050 & 0x3c) >> 2) * 0x4000 + 0x6200000;
}

