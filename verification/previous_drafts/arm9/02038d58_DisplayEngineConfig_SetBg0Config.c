/* Decompiled C draft; module arm9; ROM address 02038d58. No matching claim. */
#include "types.h"
#include "deps/02038d58_DisplayEngineConfig_SetBg0Config.h"

void DisplayEngineConfig_SetBg0Config
               (undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  *param_1 = param_2;
  param_1[2] = param_4;
  param_1[3] = param_5;
  param_1[1] = param_3;
  param_1[4] = param_6;
  param_1[5] = param_7;
  param_1[6] = param_8;
  return;
}

