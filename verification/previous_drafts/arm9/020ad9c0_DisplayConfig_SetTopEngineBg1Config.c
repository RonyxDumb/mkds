/* Decompiled C draft; module arm9; ROM address 020ad9c0. No matching claim. */
#include "types.h"
#include "deps/020ad9c0_DisplayConfig_SetTopEngineBg1Config.h"

void DisplayConfig_SetTopEngineBg1Config(int param_1)

{
  DisplayEngineConfig_SetBg1Config(param_1 + 0x28);
  return;
}

