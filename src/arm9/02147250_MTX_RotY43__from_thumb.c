/* Decompiled C draft; module arm9; ROM address 02147250. No matching claim. */
#include "types.h"
#include "deps/02147250_MTX_RotY43__from_thumb.h"

undefined4 * MTX_RotY43__from_thumb(undefined4 *param_1,int param_2,undefined4 param_3)

{
  param_1[6] = param_2;
  *param_1 = param_3;
  param_1[1] = 0;
  param_1[2] = -param_2;
  param_1[3] = 0;
  param_1[4] = 0x1000;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = param_3;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1 + 0xc;
}

