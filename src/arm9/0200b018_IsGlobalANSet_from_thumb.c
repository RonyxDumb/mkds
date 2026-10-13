/* Decompiled C draft; module arm9; ROM address 0200b018. No matching claim. */
#include "types.h"
#include "deps/0200b018_IsGlobalANSet_from_thumb.h"

undefined4 IsGlobalANSet_from_thumb(void)

{
  if (*piRam0200b028 != 0) {
    return 1;
  }
  return 0;
}

