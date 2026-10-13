/* Decompiled C draft; module arm9; ROM address 021283bc. No matching claim. */
#include "types.h"
#include "deps/021283bc_SelectReturnContext_OnSceneVblank_from_thumb.h"

void SelectReturnContext_OnSceneVblank_from_thumb(void)

{
  if (*(int *)*piRam02128438 != 0) {
    if (*(int *)(*piRam02128438 + iRam0212843c) == 0) {
      if (((*puRam02128440 & uRam02128444) >> 8 & 4) != 0) {
        *puRam02128440 =
             *puRam02128440 & uRam02128448 |
             ((*puRam02128440 & uRam02128444) >> 8 & 0xfffffffb) << 8;
      }
    }
    else if (((*puRam02128440 & uRam02128444) >> 8 & 4) == 0) {
      *puRam02128440 =
           *puRam02128440 & uRam02128448 | ((*puRam02128440 & uRam02128444) >> 8 | 4) << 8;
    }
    *puRam02128454 = *(int *)(*piRam02128438 + iRam0212844c) << 0x10 & uRam02128450;
  }
  return;
}

