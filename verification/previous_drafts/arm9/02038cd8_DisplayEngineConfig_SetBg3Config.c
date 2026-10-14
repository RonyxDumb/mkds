/* Decompiled C draft; module arm9; ROM address 02038cd8. No matching claim. */
#include "types.h"
#include "deps/02038cd8_DisplayEngineConfig_SetBg3Config.h"

void DisplayEngineConfig_SetBg3Config
               (int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  *(undefined2 *)(param_1 + 0x34) = param_2;
  *(undefined2 *)(param_1 + 0x36) = param_3;
  *(undefined2 *)(param_1 + 0x38) = param_4;
  *(undefined2 *)(param_1 + 0x3a) = param_5;
  *(undefined2 *)(param_1 + 0x3c) = param_6;
  *(undefined2 *)(param_1 + 0x3e) = param_7;
  return;
}

