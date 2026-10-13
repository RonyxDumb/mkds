/* Decompiled C draft; module arm9; ROM address 02020aa0. No matching claim. */
#include "types.h"
#include "deps/02020aa0_SND_UnlockChannel.h"

void SND_UnlockChannel(undefined4 param_1,undefined4 param_2)

{
  MaybeSoundSendCommand(0x1b,param_1,param_2,0,0);
  return;
}

