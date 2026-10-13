/* Decompiled C draft; module arm9; ROM address 020ad958. No matching claim. */
#include "types.h"
#include "deps/020ad958_DisplayConfig_SetTopEngineBg3Config.h"

void DisplayConfig_SetTopEngineBg3Config(int param_1)

{
  DisplayEngineConfig_SetBg3Config(param_1 + 0x28);
  return;
}

