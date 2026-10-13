/* Decompiled C draft; module arm9; ROM address 02147218. No matching claim. */
#include "types.h"
#include "deps/02147218_MTX_Scale43__from_thumb.h"

undefined4 *
MTX_Scale43__from_thumb
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[8] = param_4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_3;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1 + 0xc;
}

