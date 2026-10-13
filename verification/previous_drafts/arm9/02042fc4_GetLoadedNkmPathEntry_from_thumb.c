/* Decompiled C draft; module arm9; ROM address 02042fc4. No matching claim. */
#include "types.h"
#include "deps/02042fc4_GetLoadedNkmPathEntry_from_thumb.h"

int GetLoadedNkmPathEntry_from_thumb(int param_1)

{
  return *(int *)(*piRam02042fd4 + 0x94) + param_1 * 8;
}

