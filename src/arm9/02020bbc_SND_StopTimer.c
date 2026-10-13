/* Decompiled C draft; module arm9; ROM address 02020bbc. No matching claim. */
#include "types.h"
#include "deps/02020bbc_SND_StopTimer.h"

void SND_StopTimer(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = param_3; (iVar2 < 8 && (uVar1 != 0)); uVar1 = uVar1 >> 1) {
    if ((uVar1 & 1) != 0) {
      IncreaseMDCounter(iVar2);
    }
    iVar2 = iVar2 + 1;
  }
  MaybeSoundSendCommand(0xd,param_1,param_2,param_3,param_4);
  return;
}

