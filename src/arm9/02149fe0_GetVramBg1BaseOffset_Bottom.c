/* Decompiled C draft; module arm9; ROM address 02149fe0. No matching claim. */
#include "types.h"
#include "deps/02149fe0_GetVramBg1BaseOffset_Bottom.h"

int GetVramBg1BaseOffset_Bottom(void)

{
  return ((int)(*puRam02149ffc & 0x3c) >> 2) * 0x4000 + 0x6200000;
}

