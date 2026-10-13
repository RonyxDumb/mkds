/* Decompiled C draft; module arm9; ROM address 020d0efc. No matching claim. */
#include "types.h"
#include "deps/020d0efc_func_020d0efc.h"

undefined4 func_020d0efc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(iRam020d0f4c + param_1 * 8) == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = func_020d0ec4();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if (*(int *)(*piRam020d0f50 + 0xc) != param_1) {
      *(int *)(*piRam020d0f50 + 0xc) = param_1;
      WorkerInsertTask(uRam020d0f54);
      WorkerInsertTask(uRam020d0f58);
      WorkerInsertTask(uRam020d0f5c);
      WorkerNotifyTaskPending();
    }
  }
  return uVar2;
}

