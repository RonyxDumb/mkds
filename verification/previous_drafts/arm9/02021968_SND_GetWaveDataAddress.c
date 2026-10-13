/* Decompiled C draft; module arm9; ROM address 02021968. No matching claim. */
#include "types.h"
#include "deps/02021968_SND_GetWaveDataAddress.h"

uint SND_GetWaveDataAddress(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  Sound_LockMutex();
  uVar2 = param_1 + param_2 * 4 + 0x3c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else if (uVar2 < 0x2000000) {
    uVar2 = param_1 + uVar2;
  }
  Sound_UnlockMutex();
  return uVar2;
}

