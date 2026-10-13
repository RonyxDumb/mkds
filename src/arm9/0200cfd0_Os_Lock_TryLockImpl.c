/* Decompiled C draft; module arm9; ROM address 0200cfd0. No matching claim. */
#include "types.h"
#include "deps/0200cfd0_Os_Lock_TryLockImpl.h"

void Os_Lock_TryLockImpl(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  
  iVar1 = Os_Lock_HandleTryLock();
  if (0 < iVar1) {
    do {
      Os_Lock_Wait();
      iVar1 = Os_Lock_HandleTryLock(param_1,param_2,param_3,param_4);
    } while (0 < iVar1);
    return;
  }
  return;
}

