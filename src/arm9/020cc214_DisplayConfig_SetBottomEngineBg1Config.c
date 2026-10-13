/* Decompiled C draft; module arm9; ROM address 020cc214. No matching claim. */
#include "types.h"
#include "deps/020cc214_DisplayConfig_SetBottomEngineBg1Config.h"

void DisplayConfig_SetBottomEngineBg1Config(int param_1)

{
  DisplayEngineConfig_SetBg1Config(param_1 + 0x70);
  return;
}

