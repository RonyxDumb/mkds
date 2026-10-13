/* Decompiled C draft; module arm9; ROM address 02077a28. No matching claim. */
#include "types.h"
#include "deps/02077a28_ReadEmblemPalette_from_thumb.h"

void ReadEmblemPalette_from_thumb(undefined4 param_1)

{
  undefined4 local_8 [2];
  
  ReadKartModelMenuFile_from_thumb(param_1,uRam02077a44,(undefined4)(uintptr_t)(local_8));
  Gfx_ReadPalette((int *)(uintptr_t)(uRam02077a48),local_8[0]);
  return;
}

