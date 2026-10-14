/* Decompiled C draft; module arm9; ROM address 020213ec. No matching claim. */
#include "types.h"
#include "deps/020213ec_Sound_AllocateCommand.h"

void Sound_AllocateCommand(uint param_1)

{
  int iVar1;
  
  iVar1 = Sound_IsCommandAvailable();
  if (iVar1 == 0) {
    return;
  }
  iVar1 = Sound_AllocateCommandImpl(iVar1);
  if (iVar1 != 0) {
    return;
  }
  if ((param_1 & 1) == 0) {
    return;
  }
  iVar1 = SND_CountWaitingCommand(param_1 & 1);
  if (iVar1 < 1) {
    Sound_FlushCommand(1);
  }
  else {
    do {
      iVar1 = Sound_CommandReceiveAndReply(0);
    } while (iVar1 != 0);
    iVar1 = Sound_AllocateCommandImpl();
    if (iVar1 != 0) {
      return;
    }
  }
  SoundInternal_RequestCommandProc();
  do {
    Sound_CommandReceiveAndReply(1);
    iVar1 = Sound_AllocateCommandImpl();
  } while (iVar1 == 0);
  return;
}

