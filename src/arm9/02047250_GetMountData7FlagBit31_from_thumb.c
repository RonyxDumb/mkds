/* Decompiled C draft; module arm9; ROM address 02047250. No matching claim. */
#include "types.h"
#include "deps/02047250_GetMountData7FlagBit31_from_thumb.h"

int GetMountData7FlagBit31_from_thumb(void)

{
  if (*psRam02047268 == 2) {
    return *(int *)(*piRam0204726c + iRam02047270) >> 0x1f;
  }
  return 1;
}

