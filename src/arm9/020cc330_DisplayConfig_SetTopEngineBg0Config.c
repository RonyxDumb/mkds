/* Decompiled C draft; module arm9; ROM address 020cc330. No matching claim. */
#include "types.h"
#include "deps/020cc330_DisplayConfig_SetTopEngineBg0Config.h"

void DisplayConfig_SetTopEngineBg0Config(int param_1)

{
  DisplayEngineConfig_SetBg0Config(param_1 + 0x28);
  return;
}

