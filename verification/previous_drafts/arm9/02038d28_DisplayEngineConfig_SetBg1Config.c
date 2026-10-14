/* Decompiled C draft; module arm9; ROM address 02038d28. No matching claim. */
#include "types.h"
#include "deps/02038d28_DisplayEngineConfig_SetBg1Config.h"

void DisplayEngineConfig_SetBg1Config
               (int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  *(undefined2 *)(param_1 + 0x10) = param_2;
  *(undefined2 *)(param_1 + 0x14) = param_4;
  *(undefined2 *)(param_1 + 0x16) = param_5;
  *(undefined2 *)(param_1 + 0x12) = param_3;
  *(undefined2 *)(param_1 + 0x18) = param_6;
  *(undefined2 *)(param_1 + 0x1a) = param_7;
  *(undefined2 *)(param_1 + 0x1c) = param_8;
  return;
}

