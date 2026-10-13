/* Decompiled C draft; module arm9; ROM address 020219b0. No matching claim. */
#include "types.h"
#include "deps/020219b0_SND_SetWaveDataAddress.h"

void SND_SetWaveDataAddress(int param_1,int param_2,undefined4 param_3)

{
  Sound_LockMutex();
  *(undefined4 *)(param_1 + param_2 * 4 + 0x3c) = param_3;
  DC_SomeClean(param_1 + 0x3c + param_2 * 4,4);
  Sound_UnlockMutex();
  return;
}

