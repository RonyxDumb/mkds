/* Decompiled C draft; module arm9; ROM address 02020ff0. No matching claim. */
#include "types.h"
#include "deps/02020ff0_Sound_FifoHandler.h"

void Sound_FifoHandler(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = Os_DisableIrq();
  Sound_CallAlarmHandler(param_2);
  Os_RestoreIrq(uVar1);
  return;
}

