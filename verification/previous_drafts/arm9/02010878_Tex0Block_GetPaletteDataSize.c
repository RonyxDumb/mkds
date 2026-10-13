/* Decompiled C draft; module arm9; ROM address 02010878. No matching claim. */
#include "types.h"
#include "deps/02010878_Tex0Block_GetPaletteDataSize.h"

int Tex0Block_GetPaletteDataSize(int param_1)

{
  return (uint)*(ushort *)(param_1 + 0x30) << 3;
}

