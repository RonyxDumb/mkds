/* Decompiled C draft; module arm9; ROM address 0215228c. No matching claim. */
#include "types.h"
#include "deps/0215228c_ComputeTimeSeconds_from_thumb.h"

int ComputeTimeSeconds_from_thumb(int *param_1)

{
  return param_1[2] + (param_1[1] + *param_1 * 0x3c) * 0x3c;
}

