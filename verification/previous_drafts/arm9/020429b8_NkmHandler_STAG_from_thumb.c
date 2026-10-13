/* Decompiled C draft; module arm9; ROM address 020429b8. No matching claim. */
#include "types.h"
#include "deps/020429b8_NkmHandler_STAG_from_thumb.h"

undefined4 NkmHandler_STAG_from_thumb(int param_1)

{
  *(int *)(*piRam020429c4 + 0x18) = param_1 + 4;
  return 1;
}

