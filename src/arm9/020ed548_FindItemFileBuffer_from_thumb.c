/* Decompiled C draft; module arm9; ROM address 020ed548. No matching claim. */
#include "types.h"
#include "deps/020ed548_FindItemFileBuffer_from_thumb.h"

undefined4 FindItemFileBuffer_from_thumb(int param_1)

{
  undefined4 uVar1;
  char acStack_108 [264];
  
  if (param_1 == 0) {
    return 0;
  }
  _snprintf(acStack_108,sRam020ed570,pcRam020ed574);
  uVar1 = FindFileBuffer_MAR_EFT_from_thumb((undefined4)(uintptr_t)(acStack_108));
  return uVar1;
}

