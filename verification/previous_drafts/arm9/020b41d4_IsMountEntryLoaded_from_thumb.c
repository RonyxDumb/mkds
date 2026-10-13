/* Decompiled C draft; module arm9; ROM address 020b41d4. No matching claim. */
#include "types.h"
#include "deps/020b41d4_IsMountEntryLoaded_from_thumb.h"

undefined4 IsMountEntryLoaded_from_thumb(int param_1)

{
  return *(undefined4 *)(*piRam020b41e4 + param_1 * 0x70 + 0x68);
}

