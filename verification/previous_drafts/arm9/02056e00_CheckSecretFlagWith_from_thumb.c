/* Decompiled C draft; module arm9; ROM address 02056e00. No matching claim. */
#include "types.h"
#include "deps/02056e00_CheckSecretFlagWith_from_thumb.h"

bool CheckSecretFlagWith_from_thumb(uint param_1,int param_2)

{
  return (1 << (param_1 & 7) & (uint)*(byte *)(param_2 + ((int)param_1 >> 3))) != 0;
}

