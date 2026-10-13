/* Decompiled C draft; module arm9; ROM address 0204ba8c. No matching claim. */
#include "types.h"
#include "deps/0204ba8c_func_0204ba8c.h"

void func_0204ba8c(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = iRam0204bad4;
  iVar1 = Os_Thread_IsTerminated(iRam0204bad4 + 0x400);
  if (iVar1 == 0) {
    iVar2 = iVar2 + 0x400;
    do {
      Os_Thread_WakeUpDirect(iVar2);
      Os_Thread_Join(iVar2);
      iVar1 = Os_Thread_IsTerminated(iVar2);
    } while (iVar1 == 0);
    return;
  }
  return;
}

