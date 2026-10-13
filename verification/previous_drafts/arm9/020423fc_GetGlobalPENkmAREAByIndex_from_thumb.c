/* Decompiled C draft; module arm9; ROM address 020423fc. No matching claim. */
#include "types.h"
#include "deps/020423fc_GetGlobalPENkmAREAByIndex_from_thumb.h"

int GetGlobalPENkmAREAByIndex_from_thumb(int param_1)

{
  return *(int *)(*piRam0204240c + 0x74) + param_1 * 0x48;
}

