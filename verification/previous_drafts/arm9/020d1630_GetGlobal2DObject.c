/* Decompiled C draft; module arm9; ROM address 020d1630. No matching claim. */
#include "types.h"
#include "deps/020d1630_GetGlobal2DObject.h"

uint GetGlobal2DObject(void)

{
  return *(uint *)(uRam020d163c & 0xfffffffc) >> (uRam020d163c & 3) * 8 |
         *(uint *)(uRam020d163c & 0xfffffffc) << (uRam020d163c & 3) * -8 + 0x20;
}

