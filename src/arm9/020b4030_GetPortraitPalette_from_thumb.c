/* Decompiled C draft; module arm9; ROM address 020b4030. No matching claim. */
#include "types.h"
#include "deps/020b4030_GetPortraitPalette_from_thumb.h"

undefined4 GetPortraitPalette_from_thumb(int param_1)

{
  return *(undefined4 *)(iRam020b4038 + param_1 * 4);
}

