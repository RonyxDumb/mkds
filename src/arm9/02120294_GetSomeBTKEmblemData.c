/* Decompiled C draft; module arm9; ROM address 02120294. No matching claim. */
#include "types.h"
#include "deps/02120294_GetSomeBTKEmblemData.h"

int GetSomeBTKEmblemData(int param_1)

{
  return param_1 * 0x244 +
         (*(uint *)(uRam021202ac & 0xfffffffc) >> (uRam021202ac & 3) * 8 |
         *(uint *)(uRam021202ac & 0xfffffffc) << (uRam021202ac & 3) * -8 + 0x20) + 0x23c;
}

