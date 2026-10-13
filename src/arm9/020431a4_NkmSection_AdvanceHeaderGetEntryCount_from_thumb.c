/* Decompiled C draft; module arm9; ROM address 020431a4. No matching claim. */
#include "types.h"
#include "deps/020431a4_NkmSection_AdvanceHeaderGetEntryCount_from_thumb.h"

uint NkmSection_AdvanceHeaderGetEntryCount_from_thumb(int *param_1)

{
  uint uVar1;
  
  *param_1 = *param_1 + 4;
  uVar1 = *(uint *)*param_1;
  *param_1 = (int)((uint *)*param_1 + 1);
  return uVar1 & 0xffff;
}

