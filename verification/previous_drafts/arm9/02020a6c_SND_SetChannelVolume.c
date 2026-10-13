/* Decompiled C draft; module arm9; ROM address 02020a6c. No matching claim. */
#include "types.h"
#include "deps/02020a6c_SND_SetChannelVolume.h"

void SND_SetChannelVolume(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  MaybeSoundSendCommand(0x14,param_1,param_2,param_3,0);
  return;
}

