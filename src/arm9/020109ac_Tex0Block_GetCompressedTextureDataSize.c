/* Decompiled C draft; module arm9; ROM address 020109ac. No matching claim. */
#include "types.h"
#include "deps/020109ac_Tex0Block_GetCompressedTextureDataSize.h"

int Tex0Block_GetCompressedTextureDataSize(int param_1)

{
  return (uint)*(ushort *)(param_1 + 0x1c) << 3;
}

