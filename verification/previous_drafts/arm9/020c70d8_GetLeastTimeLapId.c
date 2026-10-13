/* Decompiled C draft; module arm9; ROM address 020c70d8. No matching claim. */
#include "types.h"
#include "deps/020c70d8_GetLeastTimeLapId.h"

undefined2 GetLeastTimeLapId(void)

{
  return *(undefined2 *)
          ((*(uint *)(uRam020c70e8 & 0xfffffffc) >> (uRam020c70e8 & 3) * 8 |
           *(uint *)(uRam020c70e8 & 0xfffffffc) << (uRam020c70e8 & 3) * -8 + 0x20) + 0x14);
}

