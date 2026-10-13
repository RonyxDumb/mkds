/* Decompiled C draft; module arm9; ROM address 020109b8. No matching claim. */
#include "types.h"
#include "deps/020109b8_Tex0Block_GetTextureDataSize.h"

int Tex0Block_GetTextureDataSize(int param_1)

{
  return (uint)*(ushort *)(param_1 + 0xc) << 3;
}

