/* Decompiled C draft; module arm9; ROM address 0200704c. No matching claim. */
#include "types.h"
#include "deps/0200704c_func_0200704c.h"

undefined4 func_0200704c(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = Os_DisableIrq();
  if (*piRam020070a8 != 1) {
    Os_RestoreIrq();
    return 0;
  }
  piVar2 = (int *)func_020070b0();
  if ((piVar2 != (int *)0x0) && (*piVar2 == 0)) {
    Mem_CpuCopy32(param_1,uRam020070ac,0x9c);
    Os_RestoreIrq(uVar1);
    return 1;
  }
  Os_RestoreIrq(uVar1);
  return 0;
}

