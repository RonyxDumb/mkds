/* Decompiled C draft; module arm7; ROM address 03800700. No matching claim. */
#include "types.h"
#include "deps/03800700_FUN_03800700.h"

bool FUN_03800700(void)

{
  byte local_8 [8];
  
  FUN_038006f0(2);
  FUN_03800538(DAT_03800760,0,1,DAT_03800764);
  FUN_03800538(0,(int)(uintptr_t)(local_8),1,DAT_03800768);
  FUN_03800610(0,0);
  return (local_8[0] & 1) == 0;
}

