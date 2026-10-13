/* Decompiled C draft; module arm9; ROM address 0214726c. No matching claim. */
#include "types.h"
#include "deps/0214726c_MTX_RotZ43__from_thumb.h"

undefined4 * MTX_RotZ43__from_thumb(undefined4 *param_1,int param_2,undefined4 param_3)

{
  *param_1 = param_3;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[3] = -param_2;
  param_1[4] = param_3;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0x1000;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1 + 0xc;
}

