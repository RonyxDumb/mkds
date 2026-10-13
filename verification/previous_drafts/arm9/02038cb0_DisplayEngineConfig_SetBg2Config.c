/* Decompiled C draft; module arm9; ROM address 02038cb0. No matching claim. */
#include "types.h"
#include "deps/02038cb0_DisplayEngineConfig_SetBg2Config.h"

void DisplayEngineConfig_SetBg2Config
               (int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined2 param_6)

{
  *(undefined4 *)(param_1 + 0x20) = 5;
  *(undefined2 *)(param_1 + 0x24) = param_2;
  *(undefined2 *)(param_1 + 0x26) = param_3;
  *(undefined2 *)(param_1 + 0x28) = param_4;
  *(undefined2 *)(param_1 + 0x2a) = param_5;
  *(undefined2 *)(param_1 + 0x2c) = param_6;
  return;
}

