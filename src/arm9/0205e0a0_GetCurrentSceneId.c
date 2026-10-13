/* Decompiled C draft; module arm9; ROM address 0205e0a0. No matching claim. */
#include "types.h"
#include "deps/0205e0a0_GetCurrentSceneId.h"

int GetCurrentSceneId(void)

{
  return (int)*(short *)(iRam0205e0ac + 2);
}

