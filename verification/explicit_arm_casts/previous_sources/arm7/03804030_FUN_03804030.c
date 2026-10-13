/* Decompiled C draft; module arm7; ROM address 03804030. No matching claim. */
#include "types.h"
#include "deps/03804030_FUN_03804030.h"

bool FUN_03804030(void)

{
  ushort local_8 [4];
  
  FUN_03804cdc(local_8);
  return (local_8[0] & 1) == 0;
}

