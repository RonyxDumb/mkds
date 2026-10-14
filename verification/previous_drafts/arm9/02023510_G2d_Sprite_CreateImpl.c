/* Decompiled C draft; module arm9; ROM address 02023510. No matching claim. */
#include "types.h"
#include "deps/02023510_G2d_Sprite_CreateImpl.h"

void G2d_Sprite_CreateImpl
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined1 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  param_1[1] = param_3;
  param_1[2] = param_4;
  *(undefined1 *)(param_1 + 3) = param_5;
  *param_1 = param_2;
  param_1[5] = param_6;
  param_1[6] = param_7;
  param_1[7] = param_8;
  param_1[4] = param_9;
  return;
}

