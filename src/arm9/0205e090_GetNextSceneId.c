/* Decompiled C draft; module arm9; ROM address 0205e090. No matching claim. */
#include "types.h"
#include "deps/0205e090_GetNextSceneId.h"

int GetNextSceneId(void)

{
  return (int)*(short *)(iRam0205e09c + 4);
}

