/* Decompiled C draft; module arm9; ROM address 0200cea0. No matching claim. */
#include "types.h"
#include "deps/0200cea0_Os_Lock_HandleTryLock.h"

int Os_Lock_HandleTryLock(undefined4 param_1,int param_2,code *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_4 == 0) {
    uVar1 = Os_DisableIrq();
  }
  else {
    uVar1 = Os_DisableIrqFiq();
  }
  iVar2 = Mem_Swap16(param_1,param_2);
  if (iVar2 == 0) {
    if (param_3 != (code *)0x0) {
      (*param_3)();
    }
    *(short *)(param_2 + 4) = (short)param_1;
  }
  if (param_4 == 0) {
    Os_RestoreIrq(uVar1);
  }
  else {
    Os_RestoreIrqFiq(uVar1);
  }
  return iVar2;
}

