/* Decompiled C draft; module arm9; ROM address 020b403c. No matching claim. */
#include "types.h"
#include "deps/020b403c_GetLoadedFont_from_thumb.h"

undefined4 GetLoadedFont_from_thumb(int param_1)

{
  return *(undefined4 *)(iRam020b4044 + param_1 * 4);
}

