/* Decompiled C draft; module arm9; ROM address 020cc250. No matching claim. */
#include "types.h"
#include "deps/020cc250_DisplayConfig_SetBottomEngineBg0Config.h"

void DisplayConfig_SetBottomEngineBg0Config(int param_1)

{
  DisplayEngineConfig_SetBg0Config(param_1 + 0x70);
  return;
}

