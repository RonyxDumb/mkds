/* Decompiled C draft; module arm9; ROM address 0212da2c. No matching claim. */
#include "types.h"
#include "deps/0212da2c_Sound_Context_GetMaybeSavedFrameHeapStateId.h"

int Sound_Context_GetMaybeSavedFrameHeapStateId(int param_1)

{
  return *(ushort *)(param_1 + 0xc) - 1;
}

