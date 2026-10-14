/* Decompiled C draft; module arm9; ROM address 02021154. No matching claim. */
#include "types.h"
#include "deps/02021154_func_02021154.h"

void func_02021154(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_020210c0();
  if (iVar1 != 0) {
    return;
  }
  do {
    iVar1 = Sound_CommandReceiveAndReply(0);
  } while (iVar1 != 0);
  iVar1 = func_020210c0(param_1);
  if (iVar1 != 0) {
    return;
  }
  SoundInternal_RequestCommandProc();
  iVar1 = func_020210c0(param_1);
  if (iVar1 != 0) {
    return;
  }
  do {
    Sound_CommandReceiveAndReply(1);
    iVar1 = func_020210c0(param_1);
  } while (iVar1 == 0);
  return;
}

