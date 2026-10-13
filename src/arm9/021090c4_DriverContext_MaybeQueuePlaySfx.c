/* Decompiled C draft; module arm9; ROM address 021090c4. No matching claim. */
#include "types.h"
#include "deps/021090c4_DriverContext_MaybeQueuePlaySfx.h"

void DriverContext_MaybeQueuePlaySfx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (((*(uint *)(uRam0210910c & 0xfffffffc) >> (uRam0210910c & 3) * 8 |
       *(uint *)(uRam0210910c & 0xfffffffc) << (uRam0210910c & 3) * -8 + 0x20) & 1) != 0) {
    StructMQRacerEntry_SomeFn_6(param_1,0,param_2,param_3);
    return;
  }
  return;
}

