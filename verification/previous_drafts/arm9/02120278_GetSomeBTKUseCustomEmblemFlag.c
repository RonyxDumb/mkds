/* Decompiled C draft; module arm9; ROM address 02120278. No matching claim. */
#include "types.h"
#include "deps/02120278_GetSomeBTKUseCustomEmblemFlag.h"

undefined1 GetSomeBTKUseCustomEmblemFlag(int param_1)

{
  return *(undefined1 *)
          (param_1 * 0x244 +
           (*(uint *)(uRam02120290 & 0xfffffffc) >> (uRam02120290 & 3) * 8 |
           *(uint *)(uRam02120290 & 0xfffffffc) << (uRam02120290 & 3) * -8 + 0x20) + 0x43c);
}

