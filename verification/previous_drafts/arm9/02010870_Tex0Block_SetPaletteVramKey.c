/* Decompiled C draft; module arm9; ROM address 02010870. No matching claim. */
#include "types.h"
#include "deps/02010870_Tex0Block_SetPaletteVramKey.h"

void Tex0Block_SetPaletteVramKey(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  return;
}

