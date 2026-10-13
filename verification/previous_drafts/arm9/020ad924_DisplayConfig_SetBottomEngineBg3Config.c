/* Decompiled C draft; module arm9; ROM address 020ad924. No matching claim. */
#include "types.h"
#include "deps/020ad924_DisplayConfig_SetBottomEngineBg3Config.h"

void DisplayConfig_SetBottomEngineBg3Config(int param_1)

{
  DisplayEngineConfig_SetBg3Config(param_1 + 0x70);
  return;
}

