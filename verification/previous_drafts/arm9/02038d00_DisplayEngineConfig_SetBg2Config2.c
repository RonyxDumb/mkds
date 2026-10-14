/* Decompiled C draft; module arm9; ROM address 02038d00. No matching claim. */
#include "types.h"
#include "deps/02038d00_DisplayEngineConfig_SetBg2Config2.h"

void DisplayEngineConfig_SetBg2Config2
               (int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  *(undefined2 *)(param_1 + 0x24) = param_2;
  *(undefined2 *)(param_1 + 0x26) = param_3;
  *(undefined2 *)(param_1 + 0x28) = param_4;
  *(undefined2 *)(param_1 + 0x2a) = param_5;
  *(undefined2 *)(param_1 + 0x2c) = param_6;
  *(undefined2 *)(param_1 + 0x2e) = param_7;
  return;
}

