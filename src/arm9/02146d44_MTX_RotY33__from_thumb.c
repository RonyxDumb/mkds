/* Decompiled C draft; module arm9; ROM address 02146d44. No matching claim. */
#include "types.h"
#include "deps/02146d44_MTX_RotY33__from_thumb.h"

void MTX_RotY33__from_thumb(undefined4 *param_1,int param_2,undefined4 param_3)

{
  *param_1 = param_3;
  param_1[8] = param_3;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[6] = param_2;
  param_1[2] = -param_2;
  param_1[4] = 0x1000;
  return;
}

