/* Decompiled C draft; module arm9; ROM address 020ad2dc. No matching claim. */
#include "types.h"
#include "deps/020ad2dc_SetB488TitleMenuSkipIntro.h"

void SetB488TitleMenuSkipIntro(undefined4 param_1)

{
  *(undefined4 *)
   (*(uint *)(uRam020ad2ec & 0xfffffffc) >> (uRam020ad2ec & 3) * 8 |
   *(uint *)(uRam020ad2ec & 0xfffffffc) << (uRam020ad2ec & 3) * -8 + 0x20) = param_1;
  return;
}

