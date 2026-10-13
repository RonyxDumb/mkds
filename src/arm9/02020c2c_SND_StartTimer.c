/* Decompiled C draft; module arm9; ROM address 02020c2c. No matching claim. */
#include "types.h"
#include "deps/02020c2c_SND_StartTimer.h"

void SND_StartTimer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  MaybeSoundSendCommand(0xc,param_1,param_2,param_3,param_4);
  return;
}

