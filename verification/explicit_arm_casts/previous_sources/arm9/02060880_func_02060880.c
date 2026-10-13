/* Decompiled C draft; module arm9; ROM address 02060880. No matching claim. */
#include "types.h"
#include "deps/02060880_func_02060880.h"

undefined4 func_02060880(undefined4 param_1,int param_2)

{
  undefined1 auStack_30 [34];
  byte local_e;
  
  GlobalZ_GetOI(param_1,auStack_30);
  if (-1 < (int)((uint)local_e << 0x1f)) {
    return 0;
  }
  local_e = local_e & 0xf7 | (param_2 != 0) << 3;
  GlobalZ_SetOI(param_1,auStack_30);
  return 1;
}

