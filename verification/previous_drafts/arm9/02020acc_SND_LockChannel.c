/* Decompiled C draft; module arm9; ROM address 02020acc. No matching claim. */
#include "types.h"
#include "deps/02020acc_SND_LockChannel.h"

void SND_LockChannel(undefined4 param_1,undefined4 param_2)

{
  MaybeSoundSendCommand(0x1a,param_1,param_2,0,0);
  return;
}

