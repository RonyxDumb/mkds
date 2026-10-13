/* Decompiled C draft; module arm9; ROM address 021525e0. No matching claim. */
#include "types.h"
#include "deps/021525e0_PlayerProfileInfo_NeedsSaving_from_thumb.h"

bool PlayerProfileInfo_NeedsSaving_from_thumb(int param_1)

{
  return (*(uint *)(param_1 + 0x20) & 1) == 1;
}

