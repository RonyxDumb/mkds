/* Decompiled C draft; module arm9; ROM address 020205b0. No matching claim. */
#include "types.h"
#include "deps/020205b0_ComputeProfileInfoCrc.h"

uint ComputeProfileInfoCrc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint local_8 [2];
  
  local_8[0] = 0xffffffff;
  ComputeProfileInfoCrcImpl(param_1,local_8,(byte *)(uintptr_t)(param_2),param_3);
  return ~local_8[0];
}

