/* Decompiled C draft; module arm9; ROM address 021202cc. No matching claim. */
#include "types.h"
#include "deps/021202cc_GetMaybeSomeWifiIdx.h"

byte GetMaybeSomeWifiIdx(int param_1)

{
  return *(byte *)(param_1 * 0x244 +
                   (*(uint *)(uRam021202ec & 0xfffffffc) >> (uRam021202ec & 3) * 8 |
                   *(uint *)(uRam021202ec & 0xfffffffc) << (uRam021202ec & 3) * -8 + 0x20) + 0x450)
         & 0xf;
}

