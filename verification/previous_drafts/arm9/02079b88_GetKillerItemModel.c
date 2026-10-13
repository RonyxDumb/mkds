/* Decompiled C draft; module arm9; ROM address 02079b88. No matching claim. */
#include "types.h"
#include "deps/02079b88_GetKillerItemModel.h"

int GetKillerItemModel(void)

{
  return (*(uint *)(uRam02079b98 & 0xfffffffc) >> (uRam02079b98 & 3) * 8 |
         *(uint *)(uRam02079b98 & 0xfffffffc) << (uRam02079b98 & 3) * -8 + 0x20) + 0x2c;
}

