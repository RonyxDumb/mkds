/* Decompiled C draft; module arm9; ROM address 0200b1b0. No matching claim. */
#include "types.h"
#include "deps/0200b1b0_func_0200b1b0.h"

undefined4 func_0200b1b0(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (0xf < param_1) {
    return 0;
  }
  uVar1 = Os_DisableIrq();
  iVar2 = func_02008934(param_1);
  if (iVar2 == 0) {
    Os_RestoreIrq(uVar1);
    return 0;
  }
  Mem_CpuCopy8(iVar2 + iRam0200b1fc,param_2,0xc0);
  Os_RestoreIrq(uVar1);
  return 1;
}

